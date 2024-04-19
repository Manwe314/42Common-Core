/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 19:08:56 by lkukhale          #+#    #+#             */
/*   Updated: 2024/04/18 15:15:18 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MICROSHELL_H
#define MICROSHELL_H

#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<wait.h>


#define SIDE_OUT 0
#define SIDE_IN 1

#define STDIN 0
#define STDOUT 1
#define STDERR 2


typedef struct s_command_list
{
    char* command;
    char** arguments;
    int pipe_type;
    int pipes[2];
    struct s_command_list* next;
} t_clist;

#endif
