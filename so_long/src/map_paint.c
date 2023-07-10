/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_paint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:57:25 by lkukhale          #+#    #+#             */
/*   Updated: 2023/04/30 19:03:32 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	images_to_window(mlx_t *mlx, mlx_image_t ***images)
{
	int	i;
	int	j;

	i = 0;
	while (images[i] != 0)
	{
		j = 0;
		while (images[i][j] != 0)
		{
			mlx_image_to_window(mlx, images[i][j], \
			DIMENSION * j, DIMENSION * i);
			j++;
		}
		i++;
	}
}

mlx_image_t	***paint_map(char **map, mlx_t *mlx, int width, int height)
{
	mlx_image_t	***images;
	int			i;

	i = 0;
	images = (mlx_image_t ***)malloc((height + 1) * sizeof(mlx_image_t **));
	while (i < height)
	{
		images[i] = (mlx_image_t **)malloc((width + 1) * sizeof(mlx_image_t *));
		images[i][width] = 0;
		i++;
	}
	images[i] = 0;
	images_fill(images, mlx, map, 0);
	return (images);
}

mlx_t	*draw_map(char **map, t_game_manager *game)
{
	mlx_t		*mlx;
	int			width;
	int			height;

	width = get_width(map);
	height = get_height(map);
	mlx = mlx_init(width, height, "So_Long", false);
	mlx_set_window_limit(mlx, width, height, width, height);
	game->images = paint_map(map, mlx, width / DIMENSION, height / DIMENSION);
	images_to_window(mlx, game->images);
	return (mlx);
}
