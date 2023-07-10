/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:45:21 by lkukhale          #+#    #+#             */
/*   Updated: 2023/02/02 18:14:01 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	character_check(char *map, t_map_validity *map_validity)
{
	int	counter;
	int	i;

	counter = 0;
	i = 0;
	while (map[i] != '\0')
	{
		if (map[i] != '0' && map[i] != '1' && map[i] != 'C' && \
		map[i] != 'E' && map[i] != 'P' && map[i] != '\n')
			counter++;
		i++;
	}
	if (counter == 0)
		map_validity->invalid_characters = 1;
}

t_map_validity	*initialise_map_validity(t_game_manager *game_manager)
{
	t_map_validity	*map;

	map = malloc(sizeof(t_map_validity));
	map->has_collect = 0;
	map->has_exit = 0;
	map->has_solution = 0;
	map->has_spawn = 0;
	map->is_walled = 0;
	map->has_dupliactes = 0;
	map->is_rectangle = 0;
	map->invalid_characters = 0;
	game_manager->map_validity = map;
	return (map);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i] != 0)
	{
		free(split[i]);
		i++;
	}
	free(split[i]);
	free(split);
}

void	is_map_walled(char **map, int lines, \
t_map_validity *map_validity, int i)
{
	int	j;
	int	walled;

	walled = 1;
	while (map[i] != 0)
	{
		j = 0;
		if (i == 0 || i == (lines - 1))
		{
			while (map[i][j] != '\0')
			{
				if (map[i][j] != '1')
					walled = 0;
				j++;
			}
		}
		else
		{
			if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
				walled = 0;
		}
		i++;
	}
	if (walled == 1)
		map_validity->is_walled = 1;
}

void	is_rectangle(char **map, t_map_validity *map_validity)
{
	int	i;
	int	line_length;
	int	next_line_length;
	int	rectangle;

	i = 0;
	line_length = 0;
	next_line_length = 0;
	rectangle = 1;
	while (map[i + 1] != 0)
	{
		line_length = ft_strlen(map[i]);
		next_line_length = ft_strlen(map[i + 1]);
		if (line_length != next_line_length)
			rectangle = 0;
		i++;
	}
	map_validity->is_rectangle = rectangle;
}
