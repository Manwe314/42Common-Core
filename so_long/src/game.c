/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:27:17 by lkukhale          #+#    #+#             */
/*   Updated: 2022/12/27 18:29:38 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	try_to_move_up(t_game_manager *game)
{
	int	x;
	int	y;

	x = game->game->spawn[0] - 1;
	y = game->game->spawn[1];
	if (game->map[x][y] != '1')
	{
		game->game->moves += 1;
		game->game->spawn[0] -= 1;
		if (game->map[x][y] == 'C')
			handle_collectable(game->game, game);
		game->player->instances[0].y -= DIMENSION;
		ft_printf("%d\n", game->game->moves);
		check_game_end(game);
	}
}

void	try_to_move_left(t_game_manager *game)
{
	int	x;
	int	y;

	x = game->game->spawn[0];
	y = game->game->spawn[1] - 1;
	if (game->map[x][y] != '1')
	{
		game->game->moves += 1;
		game->game->spawn[1] -= 1;
		if (game->map[x][y] == 'C')
			handle_collectable(game->game, game);
		game->player->instances[0].x -= DIMENSION;
		ft_printf("%d\n", game->game->moves);
		check_game_end(game);
	}
}

void	try_to_move_down(t_game_manager *game)
{
	int	x;
	int	y;

	x = game->game->spawn[0] + 1;
	y = game->game->spawn[1];
	if (game->map[x][y] != '1')
	{
		game->game->moves += 1;
		game->game->spawn[0] += 1;
		if (game->map[x][y] == 'C')
			handle_collectable(game->game, game);
		game->player->instances[0].y += DIMENSION;
		ft_printf("%d\n", game->game->moves);
		check_game_end(game);
	}
}

void	try_to_move_right(t_game_manager *game)
{
	int	x;
	int	y;

	x = game->game->spawn[0];
	y = game->game->spawn[1] + 1;
	if (game->map[x][y] != '1')
	{
		game->game->moves += 1;
		game->game->spawn[1] += 1;
		if (game->map[x][y] == 'C')
			handle_collectable(game->game, game);
		game->player->instances[0].x += DIMENSION;
		ft_printf("%d\n", game->game->moves);
		check_game_end(game);
	}
}
