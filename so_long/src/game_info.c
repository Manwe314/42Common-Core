/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 19:20:45 by lkukhale          #+#    #+#             */
/*   Updated: 2023/02/02 18:05:15 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_collectables(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i] != 0)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	*collect_x(int size, char **map)
{
	int	i;
	int	j;
	int	k;
	int	*array;

	i = 0;
	k = 0;
	array = malloc((size + 1) * sizeof(int));
	while (map[i] != 0)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'C')
			{
				array[k] = j;
				k++;
			}
			j++;
		}
		i++;
	}
	array[k] = -1;
	return (array);
}

int	*collect_y(int size, char **map)
{
	int	i;
	int	j;
	int	k;
	int	*array;

	i = 0;
	k = 0;
	array = malloc((size + 1) * sizeof(int));
	while (map[i] != 0)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'C')
			{
				array[k] = i;
				k++;
			}
			j++;
		}
		i++;
	}
	array[k] = -1;
	return (array);
}

t_game_info	*game_info_setup(char **map)
{
	t_game_info	*game;
	int			count;

	count = count_collectables(map);
	game = (t_game_info *)malloc(sizeof(t_game_info));
	game->collectable_amount = count;
	game->collected_amount = 0;
	game->spawn = point_finder("spawn", map);
	game->exit = point_finder("exit", map);
	game->collectable_x = collect_x(count, map);
	game->collecatble_y = collect_y(count, map);
	game->moves = 0;
	return (game);
}
