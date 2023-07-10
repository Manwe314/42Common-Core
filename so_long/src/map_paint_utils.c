/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_paint_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:59:13 by lkukhale          #+#    #+#             */
/*   Updated: 2023/04/28 21:55:22 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	floor_fill(mlx_image_t ***images, mlx_t *mlx, int i, int j)
{
	xpm_t	*xpm;

	xpm = mlx_load_xpm42(FLOOR);
	images[i][j] = mlx_new_image(mlx, DIMENSION, DIMENSION);
	images[i][j] = mlx_texture_to_image(mlx, &(xpm->texture));
	mlx_delete_xpm42(xpm);
}

void	wall_fill(mlx_image_t ***images, mlx_t *mlx, int i, int j)
{
	xpm_t	*xpm;

	xpm = mlx_load_xpm42(WALL);
	images[i][j] = mlx_new_image(mlx, DIMENSION, DIMENSION);
	images[i][j] = mlx_texture_to_image(mlx, &(xpm->texture));
	mlx_delete_xpm42(xpm);
}

void	mid_perimeter_fill(mlx_image_t ***images, mlx_t *mlx, int i, int j)
{
	xpm_t	*xpm;

	if (j == 0)
		xpm = mlx_load_xpm42(WALLML);
	else
		xpm = mlx_load_xpm42(WALLMR);
	images[i][j] = mlx_new_image(mlx, DIMENSION, DIMENSION);
	images[i][j] = mlx_texture_to_image(mlx, &(xpm->texture));
	mlx_delete_xpm42(xpm);
}

void	images_fill(mlx_image_t ***images, mlx_t *mlx, char **map, int i)
{
	int		j;

	while (map[i] != 0)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (i == 0)
				top_perimeter_fill(images, mlx, get_width(map) / DIMENSION, j);
			else if (i == (get_height(map) / DIMENSION) - 1)
				bot_perimeter_fill(images, mlx, get_width(map) / DIMENSION, j);
			else
			{
				if (j == 0 || j == (get_width(map) / DIMENSION) - 1)
					mid_perimeter_fill(images, mlx, i, j);
				else if (map[i][j] == '1')
					wall_fill(images, mlx, i, j);
				else
					floor_fill(images, mlx, i, j);
			}
			j++;
		}
		i++;
	}
}
