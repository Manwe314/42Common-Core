/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 18:53:53 by lkukhale          #+#    #+#             */
/*   Updated: 2023/04/30 19:04:23 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_images(t_game_manager	*game)
{
	int	i;
	int	j;

	i = 0;
	while (game->images[i] != 0)
	{
		j = 0;
		while (game->images[i][j] != 0)
		{
			mlx_delete_image(game->mlx, game->images[i][j]);
			j++;
		}
		i++;
	}
	mlx_delete_image(game->mlx, game->collectable);
	mlx_delete_image(game->mlx, game->player);
	mlx_delete_image(game->mlx, game->exit);
}

void	free_xpm(t_game_manager *game)
{
	mlx_delete_xpm42(game->xpmc);
	mlx_delete_xpm42(game->xpme);
	mlx_delete_xpm42(game->xpmp);
}
