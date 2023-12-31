/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 21:48:35 by lkukhale          #+#    #+#             */
/*   Updated: 2023/07/04 15:31:28 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_fd_size(char *input)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (input[i] != '\0')
	{
		if (input[i] == '>' && !is_quoted(input, i))
		{
			if (input[i + 1] == '>')
				i++;
			size++;
		}
		if (input[i] == '<' && !is_quoted(input, i))
		{
			if (input[i + 1] == '<')
				i++;
			else
				size++;
		}
		i++;
	}
	return (size);
}

int	change_fd(char *dir, char *name, int fd)
{
	if (ft_strncmp(dir, "oft", 3) == 0)
	{
		g_global.fds[fd] = open(name, O_TRUNC | O_CREAT | O_RDWR, 0644);
		if (g_global.fds[fd] < 0)
			return (-1);
		if (dup2(g_global.fds[fd], STDOUT_FILENO) < 0)
			error_handler("Redirection dup2", 1);
	}
	if (ft_strncmp(dir, "ofa", 3) == 0)
	{
		g_global.fds[fd] = open(name, O_APPEND | O_CREAT | O_RDWR, 0644);
		if (g_global.fds[fd] < 0)
			return (-1);
		if (dup2(g_global.fds[fd], STDOUT_FILENO) < 0)
			error_handler("Redirection dup2", 1);
	}
	if (ft_strncmp(dir, "inf", 3) == 0)
	{
		g_global.fds[fd] = open(name, O_RDONLY);
		if (g_global.fds[fd] < 0)
			return (-1);
		if (dup2(g_global.fds[fd], STDIN_FILENO) < 0)
			error_handler("Redirection dup2", 1);
	}
	return (++g_global.fd_size);
}
