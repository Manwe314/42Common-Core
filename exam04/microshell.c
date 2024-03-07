/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 19:34:20 by lkukhale          #+#    #+#             */
/*   Updated: 2024/03/07 23:16:18 by lkukhale         ###   ########.fr       */
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

int arg_size(t_arg *trav)
{
    int size = 0;
    while (trav != 0)
    {
        if (strcmp(trav->argument, "|") != 0)
            size ++;
        trav = trav->next;
    }
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

void free_args(t_arg *args)
{
    t_arg *temp;

    while (args != 0)
    {
        temp = args->next;
        free(args->argument);
        free(args);
        args = temp;
    }
}

void free_clist(t_clist *com)
{
    t_clist *temp;

    while (com != 0)
    {
        temp = com->next;
        free(com->command);
        free_args(com->arguments);
        free(com);
        com = temp;
    }
    
}

void arg_push_back(t_arg *head, char *str)
{
    t_arg* traverse;
    t_arg* new;

    if (strcmp("|", head->argument) == 0)
    {
        free(head->argument);
        head->argument = ft_strdup(str);
        return;
    }

    traverse = head;
    while (traverse->next != 0)
        traverse = traverse->next;
    new = (t_arg*)malloc(sizeof(t_arg));
    new->argument = ft_strdup(str);
    new->next = 0;
    traverse->next = new;        
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


t_clist *prepare_arguments(int size, char *argv[])
{
    int i = 1;
    int j;
    t_clist *trav;
    t_clist *com;

    if (strcmp(";", argv[1]) == 0 || strcmp("|", argv[1]) == 0)
        return 0;
    
    com = (t_clist*)malloc(sizeof(t_clist));
    trav = com;
    
    while (i <= size)
    {
        trav->command = ft_strdup(argv[i]);
        
        trav->arguments = (t_arg*)malloc(sizeof(t_arg));
        trav->arguments->argument = ft_strdup("|");
        trav->arguments->next = 0;
        
        j = i + 1;
        
        while (j <= size && strcmp(";", argv[j]) != 0 && strcmp("|", argv[j]) != 0)
        {
            arg_push_back(trav->arguments, argv[j]);
            j++;
        }

        trav->pipe_type = determine_pipe_type(argv, i, j, size);
        
        i = j + 1;
        
        if (i <= size)
        {
            trav->next = (t_clist*)malloc(sizeof(t_clist));
            trav = trav->next;
        }
        else
            trav->next = 0;
    }
    return com;
}

char *get_name(t_clist *com)
{
    char *name;
    int i;
    int j;

    i = ft_strlen(com->command) - 1;

    while (i >= 0 && com->command[i] != '/')
        i--;
    if (i < 0)
        return ft_strdup(com->command);
    name = (char *)malloc(sizeof(char) * (ft_strlen(com->command) - i));
    j = 0;
    i++;
    while (com->command[i] != '\0')
    {
        name[j] = com->command[i];
        i++;
        j++;
    }
    name[j] = '\0';
    return name;
}

char **arg_arry(t_arg *list, t_clist *com)
{
    int i;
    int list_size = arg_size(list);
    char **args;
    
    
    args = (char **)malloc(sizeof(char *) * (list_size + 2));
    i = 1;
    if (list_size != 0)
    {    
        while (i <= list_size)
        {
            args[i] = ft_strdup(list->argument);
            list = list->next;
            i++;
        }
    }
    args[i] = 0;
    args[0] = get_name(com);
    return args;
}

int execute_command(t_clist *com, t_clist *prev, char *env[])
{
    __pid_t pid;
    int ret;
    int is_pipe_open;
    int status;
    char **args;

    ret = 1;
    is_pipe_open = 0;
    args = arg_arry(com->arguments, com);
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
        if ((ret = execve(com->command, args, env)) < 0)
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
    if (args != 0)
        free_split(args);
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
            if (arg_size(com->arguments) == 0 || arg_size(com->arguments) > 1)
                ret = ft_putstr_fd("error: cd: bad arguments\n", STDERR, 1);
            else if(chdir(com->arguments->argument) != 0)
            {
                ret = ft_putstr_fd("error: cd: cannot change directory to ", STDERR, 1);
                ft_putstr_fd(com->arguments->argument, STDERR, 1);
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


/*

for vim settings:
vim ~/.vimrc

set mouse=a
set nu
syntax on

*/