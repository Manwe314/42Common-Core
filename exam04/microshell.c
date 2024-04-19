/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 19:34:20 by lkukhale          #+#    #+#             */
/*   Updated: 2024/04/18 15:16:28 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

int ft_strlen(char *str)
{
    int i = 0;
    while(str[i] != '\0')
        i++;
    return i;
}

char *ft_strdup(char *str)
{
    char *new = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1));
    int i = 0;
    while (i < ft_strlen(str))
    {
        new[i] = str[i];
        i++;
    }
    new[i] = '\0';
    return new;
}

int arg_size(char **trav)
{
    int size = 0;

    while (trav[size] != 0)
        size++;
    return size;
}

int ft_putstr_fd(char *str, int fd, int ret)
{
    int i = 0;
    if (str == 0)
        return ret;
    while (str[i] != '\0')
    {
        write(fd, &str[i], 1);
        i++;
    }
    return ret;   
}

int fatal_exit(char *msg)
{
    ft_putstr_fd(msg, STDERR, 1);
    exit(EXIT_FAILURE);
    return(1);
}

void free_split(char **split)
{
    int i = 0;
    while (split[i] != 0)
    {
        free(split[i]);
        i++;
    }
    free(split[i]);
    free(split);
}

void free_clist(t_clist *com)
{
    t_clist *temp;

    while (com != 0)
    {
        temp = com->next;
        if (com->command != 0)
            free(com->command);
        if (com->arguments != 0)
            free_split(com->arguments);
        free(com);
        com = temp;
    }
    
}

int determine_pipe_type(char *argv[], int i, int j, int size)
{
    if (i - 1 >= 1 && strcmp(argv[i - 1], "|") == 0)
    {
        if (j <= size && strcmp(argv[j], "|") == 0)
            return 2;
        else
            return 3;
    }
    else
    {
        if (j <= size && strcmp(argv[j], "|") == 0)
            return 1;
        else
            return 0;
    }
}

char *get_name(char *command)
{
    char *name;
    int i;
    int j;

    i = ft_strlen(command) - 1;

    while (i >= 0 && command[i] != '/')
        i--;
    if (i < 0)
        return ft_strdup(command);
    name = (char *)malloc(sizeof(char) * (ft_strlen(command) - i));
    j = 0;
    i++;
    while (command[i] != '\0')
    {
        name[j] = command[i];
        i++;
        j++;
    }
    name[j] = '\0';
    return name;
}

int execute_command(t_clist *com, t_clist *prev, char *env[])
{
    pid_t pid;
    int ret;
    int is_pipe_open;
    int status;

    ret = 1;
    is_pipe_open = 0;
    if (com->pipe_type != 0)
    {
        is_pipe_open = 1;
        if (com->pipe_type != 3)
            if (pipe(com->pipes))
                return (fatal_exit("error: fatal\n"));
    }
    pid = fork();
    if (pid < 0)
        return (fatal_exit("error: fatal\n"));
    else if (pid == 0)
    {
        if (com->pipe_type == 1 && dup2(com->pipes[SIDE_IN], STDOUT) < 0)
            return (fatal_exit("error: fatal\n"));
        if (com->pipe_type == 2 && dup2(prev->pipes[SIDE_OUT], STDIN) < 0 && dup2(com->pipes[SIDE_IN], STDOUT) < 0)
            return (fatal_exit("error: fatal\n"));
        if (com->pipe_type == 3 && dup2(prev->pipes[SIDE_OUT], STDIN) < 0)
            return (fatal_exit("error: fatal\n"));
        if ((ret = execve(com->command, com->arguments, env)) < 0)
        {
            ft_putstr_fd("error: cannot execute: ", STDERR, 1);
            ft_putstr_fd(com->command, STDERR, 1);
            ft_putstr_fd("\n", STDERR, 1);
            exit (ret);
        }
    }
    else
    {
        waitpid(pid, &status, 0);
        if (is_pipe_open)
        {
            if (com->pipe_type == 1)
                close(com->pipes[SIDE_IN]);
            if (com->pipe_type == 2)
            {
                close(prev->pipes[SIDE_OUT]);
                close(com->pipes[SIDE_IN]);   
            }
            if (com->pipe_type == 3)
                close(prev->pipes[SIDE_OUT]);
        }
        if (WIFEXITED(status))
            ret = WEXITSTATUS(status);
    }
    return ret;
}

int execute_list(t_clist *com, char *env[])
{
    int ret;
    t_clist *previous = com;
    while (com != 0)
    {
        if (strcmp(com->command, "cd") == 0)
        {
            if (arg_size(com->arguments) == 1 || arg_size(com->arguments) > 2)
                ret = ft_putstr_fd("error: cd: bad arguments\n", STDERR, 1);
            else if(chdir(com->arguments[1]) != 0)
            {
                ret = ft_putstr_fd("error: cd: cannot change directory to ", STDERR, 1);
                ft_putstr_fd(com->arguments[1], STDERR, 1);
                ft_putstr_fd("\n", STDERR, 1);
            }
        }
        else
        {
            ret = execute_command(com, previous, env);
        }
        
        if (previous != com)
            previous = previous->next;
        com = com->next;
    }
    return ret;
}

int invalid_start(int i, char **argv)
{
    if (strcmp(argv[i], "|") == 0 || strcmp(argv[i], ";") == 0)
        return 1;
    return 0;
}

char **make_args(char **argv, int i, int j)
{
    char **args;
    int k = 0;
    args = (char**)malloc(sizeof(char *) * ((j - i) + 1));
    args[k] = get_name(argv[i]);
    i++;
    k++;
    while (i != j)
    {
        args[k] = ft_strdup(argv[i]);
        i++;
        k++;
    }
    args[k] = 0;
    return args;
}

t_clist *prepare_arguments(int size, char **argv)
{
    t_clist *com;
    t_clist *head;
    int i;
    int j;

    i = 1;

    com = (t_clist*)malloc(sizeof(t_clist));
    com->command = 0;
    com->arguments = 0;
    head = com;

    while (i <= size)
    {
        if (invalid_start(i, argv))
        {
            free_clist(head);
            return 0;
        }
        j = i;
        while (j <= size && strcmp(argv[j], "|") != 0 && strcmp(argv[j], ";") != 0)
            j++;
        com->pipe_type = determine_pipe_type(argv, i, j, size);
        com->command = ft_strdup(argv[i]);
        com->arguments = make_args(argv, i, j);
        com->next = 0;
        i  = j + 1;
        if (i <= size)
        {
            com->next = (t_clist*)malloc(sizeof(t_clist));
            com = com->next;
            com->command = 0;
            com->arguments = 0;
        }
    }
    return head;
}

int main (int argc, char *argv[], char *env[])
{
    t_clist *com;
    int ret;
    
    ret = EXIT_SUCCESS;
    com = NULL;
    if (argc < 2)
        return ret;
    com = prepare_arguments(argc - 1, argv);
    
    if (com == 0)
        return ft_putstr_fd("error: bad token usage\n", STDERR, 1);
        
    ret = execute_list(com, env);

    free_clist(com);

    return ret;
}
