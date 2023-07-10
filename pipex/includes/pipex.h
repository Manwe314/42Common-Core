/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:36:08 by lkukhale          #+#    #+#             */
/*   Updated: 2023/04/28 19:05:01 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>

# include "libft.h"
# include "ft_printf.h"

typedef struct s_pipex
{
	pid_t	processid1;
	pid_t	processid2;
	int		pipe_int[2];
	int		infile;
	int		outfile;
	char	*path;
	char	**command_path;
	char	**command_arguments;
	char	*command;
}	t_pipex;

void	child_two(t_pipex *pipex, char **argv, char **envp);
void	child_one(t_pipex *pipex, char **argv, char **envp);
char	*get_command(char *name, char **paths);
void	clean_up_child(t_pipex *pipex);
void	clean_up_parent(t_pipex *pipex);
void	close_pipes(t_pipex *pipex);
char	*get_path(char **envp);
void	p_error(char *msg);
int		error_msg(char *msg, int fd);
#endif