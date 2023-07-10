/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:45:55 by lkukhale          #+#    #+#             */
/*   Updated: 2023/05/09 19:04:01 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	pipex;

	if (argc != 5)
		return (error_msg("Invalid number of arguments\n", 2));
	pipex.infile = open(argv[1], O_RDONLY);
	if (pipex.infile < 0)
		p_error("Infile");
	pipex.outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (pipex.outfile < 0)
		p_error("Outfile");
	if (pipe(pipex.pipe_int) < 0)
		p_error("Pipe");
	pipex.path = get_path(envp);
	pipex.command_path = ft_split(pipex.path, ':');
	pipex.processid1 = fork();
	if (pipex.processid1 == 0)
		child_one(&pipex, argv, envp);
	pipex.processid2 = fork();
	if (pipex.processid2 == 0)
		child_two(&pipex, argv, envp);
	waitpid(pipex.processid1, NULL, 0);
	waitpid(pipex.processid2, NULL, 0);
	close_pipes(&pipex);
	clean_up_parent(&pipex);
	return (0);
}
