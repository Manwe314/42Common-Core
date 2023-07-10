/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:23:46 by lkukhale          #+#    #+#             */
/*   Updated: 2023/05/09 19:03:33 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	clean_up_child(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->command_arguments[i] != 0)
	{
		free (pipex->command_arguments[i]);
		i++;
	}
	free(pipex->command_arguments[i]);
	free(pipex->command_arguments);
	free(pipex->command);
}

char	*get_command(char *name, char **paths)
{
	char	*temp;
	char	*command;
	int		i;

	i = 0;
	while (paths[i] != 0)
	{
		temp = ft_strjoin(paths[i], "/");
		command = ft_strjoin(temp, name);
		free (temp);
		if (access(command, 0) == 0)
			return (command);
		free (command);
		i++;
	}
	return (0);
}

void	execute_command(char **envp, t_pipex *pipex)
{
	char	*msg;
	int		execute;

	if (pipex->command == 0)
	{
		msg = ft_strjoin(pipex->command_arguments[0], ": Command Not Found\n");
		clean_up_child(pipex);
		error_msg(msg, 2);
		free (msg);
		exit(1);
	}
	execute = execve(pipex->command, pipex->command_arguments, envp);
	if (execute == -1)
	{
		clean_up_child(pipex);
		p_error("Failed to execute command\n");
	}
}

void	child_one(t_pipex *pipex, char **argv, char **envp)
{
	dup2(pipex->pipe_int[1], 1);
	close(pipex->pipe_int[0]);
	dup2(pipex->infile, 0);
	pipex->command_arguments = ft_split(argv[2], ' ');
	pipex->command = get_command(pipex->command_arguments[0], \
	pipex->command_path);
	execute_command(envp, pipex);
}

void	child_two(t_pipex *pipex, char **argv, char **envp)
{
	dup2(pipex->outfile, 1);
	close(pipex->pipe_int[1]);
	dup2(pipex->pipe_int[0], 0);
	pipex->command_arguments = ft_split(argv[3], ' ');
	pipex->command = get_command(pipex->command_arguments[0], \
	pipex->command_path);
	execute_command(envp, pipex);
}
