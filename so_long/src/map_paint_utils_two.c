/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_paint_utils_two.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:00:01 by lkukhale          #+#    #+#             */
/*   Updated: 2023/04/30 19:02:59 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_width(char **map)
{
	int	i;

	i = 0;
	while (map[0][i] != '\0')
		i++;
	i *= DIMENSION;
	return (i);
}

int	get_height(char **map)
{
	int	i;

	i = 0;
	while (map[i] != 0)
		i++;
	i *= DIMENSION;
	return (i);
}

void	top_perimeter_fill(mlx_image_t ***images, mlx_t *mlx, int width, int j)
{
	xpm_t	*xpm;

	if (j == 0)
	{
		xpm = mlx_load_xpm42(WALLTL);
		images[0][j] = mlx_new_image(mlx, DIMENSION, DIMENSION);
		images[0][j] = mlx_texture_to_image(mlx, &(xpm->texture));
		mlx_delete_xpm42(xpm);
	}
	else if (j == width - 1)
	{
		xpm = mlx_load_xpm42(WALLTR);
		images[0][j] = mlx_new_image(mlx, DIMENSION, DIMENSION);
		images[0][j] = mlx_texture_to_image(mlx, &(xpm->texture));
		mlx_delete_xpm42(xpm);
	}
	else
	{
		xpm = mlx_load_xpm42(WALLT);
		images[0][j] = mlx_new_image(mlx, DIMENSION, DIMENSION);
		images[0][j] = mlx_texture_to_image(mlx, &(xpm->texture));
		mlx_delete_xpm42(xpm);
	}
}

int	f_the_norm(mlx_image_t ***images)
{
	int		i;

	i = 0;
	while (images[i] != 0)
		i++;
	i -= 1;
	return (i);
}

void	bot_perimeter_fill(mlx_image_t ***images, mlx_t *mlx, int width, int j)
{
	xpm_t	*xpm;
	int		i;

	i = f_the_norm(images);
	if (j == 0)
	{
		xpm = mlx_load_xpm42(WALLBL);
		images[i][j] = mlx_new_image(mlx, DIMENSION, DIMENSION);
		images[i][j] = mlx_texture_to_image(mlx, &(xpm->texture));
		mlx_delete_xpm42(xpm);
	}
	else if (j == width - 1)
	{
		xpm = mlx_load_xpm42(WALLBR);
		images[i][j] = mlx_new_image(mlx, DIMENSION, DIMENSION);
		images[i][j] = mlx_texture_to_image(mlx, &(xpm->texture));
		mlx_delete_xpm42(xpm);
	}
	else
	{
		xpm = mlx_load_xpm42(WALLB);
		images[i][j] = mlx_new_image(mlx, DIMENSION, DIMENSION);
		images[i][j] = mlx_texture_to_image(mlx, &(xpm->texture));
		mlx_delete_xpm42(xpm);
	}
}
