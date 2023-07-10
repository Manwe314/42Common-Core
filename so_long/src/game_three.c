/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:30:28 by lkukhale          #+#    #+#             */
/*   Updated: 2023/04/30 18:58:15 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_game_end(t_game_manager *game)
{
	if (game->game->spawn[0] == game->game->exit[0] && \
	game->game->spawn[1] == game->game->exit[1])
	{
		if (game->game->collectable_amount == game->game->collected_amount)
		{
			mlx_close_hook(game->mlx, &close_function, game);
			mlx_close_window(game->mlx);
		}
	}
}

void	close_function(void *param)
{
	t_game_manager	*game;

	game = param;
	free_split(game->map);
	free(game->game->collecatble_y);
	free(game->game->collectable_x);
	free(game->game->spawn);
	free(game->game->exit);
	free(game->game);
	free(game->map_validity);
	free_images(game);
	free_xpm(game);
	free(game);
}

void	handle_collectable(t_game_info *game, t_game_manager *game_manager)
{
	int	i;

	game->collected_amount += 1;
	i = get_instance(game_manager);
	mlx_set_instance_depth(&game_manager->collectable->instances[i], -1);
	game_manager->map[game->spawn[0]][game->spawn[1]] = '0';
}

void	game_key_manage(mlx_key_data_t keydata, void *param)
{
	t_game_manager	*game;

	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		try_to_move_up(param);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		try_to_move_left(param);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		try_to_move_down(param);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		try_to_move_right(param);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		game = param;
		mlx_close_hook(game->mlx, &close_function, game);
		mlx_close_window(game->mlx);
	}
}

void	start_game(mlx_t *mlx, char **map, t_game_manager *game_manager)
{
	void	*game;

	game_manager->game = game_info_setup(map);
	overlay_display(mlx, game_manager->game, game_manager);
	game = game_manager;
	mlx_key_hook(mlx, &game_key_manage, game);
}
