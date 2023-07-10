/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:28:54 by lkukhale          #+#    #+#             */
/*   Updated: 2023/04/28 21:43:54 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*get_image(mlx_t *mlx, char *name, t_game_manager *game)
{
	mlx_image_t	*image;

	image = mlx_new_image(mlx, DIMENSION, DIMENSION);
	if (ft_strncmp("exit", name, 4) == 0)
	{
		game->xpme = mlx_load_xpm42(EXIT);
		image = mlx_texture_to_image(mlx, &(game->xpme->texture));
	}
	if (ft_strncmp("player", name, 6) == 0)
	{
		game->xpmp = mlx_load_xpm42(PLAYER);
		image = mlx_texture_to_image(mlx, &(game->xpmp->texture));
	}
	if (ft_strncmp("collectable", name, 11) == 0)
	{
		game->xpmc = mlx_load_xpm42(COLLECTABLE);
		image = mlx_texture_to_image(mlx, &(game->xpmc->texture));
	}
	return (image);
}

void	overlay_display(mlx_t *mlx, t_game_info *game, \
t_game_manager *game_manager)
{
	mlx_image_t	*exit;
	mlx_image_t	*player;
	mlx_image_t	*collectable;
	int			i;

	collectable = get_image(mlx, "collectable", game_manager);
	exit = get_image(mlx, "exit", game_manager);
	player = get_image(mlx, "player", game_manager);
	mlx_image_to_window(mlx, exit, \
	game->exit[1] * DIMENSION, game->exit[0] * DIMENSION);
	mlx_image_to_window(mlx, player, \
	game->spawn[1] * DIMENSION, game->spawn[0] * DIMENSION);
	game_manager->player = player;
	game_manager->collectable = collectable;
	game_manager->exit = exit;
	i = 0;
	while (game->collectable_x[i] != -1)
	{
		mlx_image_to_window(mlx, collectable, \
		game->collectable_x[i] * DIMENSION, game->collecatble_y[i] * DIMENSION);
		i++;
	}
}

int	get_instance(t_game_manager *game_manager)
{
	int	i;

	i = 0;
	while (i < game_manager->game->collectable_amount)
	{
		if (game_manager->collectable->instances[i].x == \
		game_manager->game->spawn[1] * DIMENSION && \
		game_manager->collectable->instances[i].y == \
		game_manager->game->spawn[0] * DIMENSION)
			return (i);
		i++;
	}
	return (0);
}
