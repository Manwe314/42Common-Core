/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:22:50 by lkukhale          #+#    #+#             */
/*   Updated: 2023/04/28 19:04:37 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	error_msg(char *msg, int fd)
{
	ft_putstr_fd(msg, fd);
	return (1);
}

void	p_error(char *msg)
{
	perror(msg);
	exit(1);
}

char	*get_path(char **envp)
{
	int	i;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	return (envp[i] + 5);
}

void	close_pipes(t_pipex *pipex)
{
	close(pipex->pipe_int[0]);
	close(pipex->pipe_int[1]);
}

void	clean_up_parent(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->command_path[i] != 0)
	{
		free(pipex->command_path[i]);
		i++;
	}
	free(pipex->command_path[i]);
	free(pipex->command_path);
	close(pipex->infile);
	close(pipex->outfile);
}
