/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 18:28:33 by lkukhale          #+#    #+#             */
/*   Updated: 2023/05/31 18:04:26 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_name_empty(char *filename)
{
	int	length;

	length = ft_strlen(filename);
	if (filename[length - 1] == 'r' && filename[length - 2] == 'e'\
	&& filename[length - 3] == 'b' && filename[length - 4] == '.')
		return (0);
	return (1);
}

int	main(int argc, char *argv[])
{
	int				fd;
	t_game_manager	*game_manager;
	mlx_t			*mlx;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || argc != 2)
		return (error_handler(\
		"Map dosent exist or number of arguments is invalid", 0));
	if (check_name_empty(argv[1]))
		return (error_handler("The file is not .ber", 0));
	game_manager = malloc(sizeof(t_game_manager));
	game_manager->map = map_validificator(fd, game_manager);
	if (game_manager->map == 0)
	{
		free(game_manager->map);
		free(game_manager);
		return (error_handler("Please Use a valid map", 0));
	}
	mlx = draw_map(game_manager->map, game_manager);
	game_manager->mlx = mlx;
	start_game(mlx, game_manager->map, game_manager);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	system("leaks so_long");
	return (0);
}
