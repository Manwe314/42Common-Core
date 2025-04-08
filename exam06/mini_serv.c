#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<sys/types.h>
#include<sys/select.h>

fd_set active_fds, read_fds, write_fds;
int max_fd = 0;
int clients_count = 0;
int client_ids[65000];
char *client_msgs[65000];
char writing_buffer[42];
char reading_buffer[1001];




void fatal_error()
{
    write(2, "Fatal error\n", 12);
    exit(1);
}

void notify_others(int sender, char *msg)
{
    for (int fd = 0; fd <= max_fd; fd++)
    {
        if(FD_ISSET(fd, &write_fds) && fd != sender)
        {
            send(fd, msg, strlen(msg), 0);
        }
    }
}

int extract_message(char **buf, char **msg)
{
	char	*newbuf;
	int	i;

	*msg = 0;
	if (*buf == 0)
		return (0);
	i = 0;
	while ((*buf)[i])
	{
		if ((*buf)[i] == '\n')
		{
			newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
			if (newbuf == 0)
				return (-1);
			strcpy(newbuf, *buf + i + 1);
			*msg = *buf;
			(*msg)[i + 1] = 0;
			*buf = newbuf;
			return (1);
		}
		i++;
	}
	return (0);
}

char *str_join(char *buf, char *add)
{
	char	*newbuf;
	int		len;

	if (buf == 0)
		len = 0;
	else
		len = strlen(buf);
	newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
	if (newbuf == 0)
		return (0);
	newbuf[0] = 0;
	if (buf != 0)
		strcat(newbuf, buf);
	free(buf);
	strcat(newbuf, add);
	return (newbuf);
}

int create_socket()
{
    max_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (max_fd < 0)
        fatal_error();
    FD_SET(max_fd, &active_fds);
    return max_fd;
}

void register_client(int fd)
{
    if (fd > max_fd)
        max_fd = fd;
    client_ids[fd] = clients_count++;
    client_msgs[fd] = NULL;
    FD_SET(fd, &active_fds);
    sprintf(writing_buffer, "server: client %d just arrived\n", client_ids[fd]);
    notify_others(fd, writing_buffer);          
}

void remove_client(int fd)
{
    sprintf(writing_buffer, "server: client %d just left\n", client_ids[fd]);
    notify_others(fd, writing_buffer);
    free(client_msgs[fd]);
    FD_CLR(fd, &active_fds);
    close(fd);
}

void send_msg(int fd)
{
    char *msg;

    while (extract_message(&(client_msgs[fd]), &msg))
    {
        sprintf(writing_buffer, "client %d: ", client_ids[fd]);
        notify_others(fd, writing_buffer);
        notify_others(fd, msg);
        free(msg);
    }
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        write(2, "Wrong number of arguments\n", 26);
        exit(1);
    }

    FD_ZERO(&active_fds);
    int sockfd = create_socket();

    struct sockaddr_in servaddr;
    bzero(&servaddr, sizeof(servaddr)); 

	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(atoi(argv[1])); 

	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0) 
		fatal_error();
	if (listen(sockfd, 100) != 0) 
		fatal_error();

    while(1)
    {
        read_fds = write_fds = active_fds;
        if (select(max_fd + 1, &read_fds, &write_fds, NULL, NULL) < 0)
            fatal_error();
        for (int fd = 0; fd <= max_fd; fd++)
        {
            if (FD_ISSET(fd, &read_fds))
            {
                if (fd == sockfd)
                {
                    socklen_t addr_len = sizeof(servaddr);
                    int client_fd = accept(sockfd, (struct sockaddr *)&servaddr, &addr_len);
                    if (client_fd >= 0)
                    {
                        register_client(client_fd);
                        break;
                    }
                }
                else
                {
                    int read_bytes = recv(fd, reading_buffer, 1000, 0);
                    if (read_bytes <= 0)
                    {
                        remove_client(fd);
                        break;
                    }
                    reading_buffer[read_bytes] = '\0';
                    client_msgs[fd] = str_join(client_msgs[fd], reading_buffer);
                    send_msg(fd);
                }
            }
        }
    }
    return (0);
}