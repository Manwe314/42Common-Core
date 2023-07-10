/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:00:23 by lkukhale          #+#    #+#             */
/*   Updated: 2023/04/30 16:03:39 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	final_check(t_map_validity *map_valididty)
{
	if (map_valididty->invalid_characters && \
	map_valididty->has_collect && map_valididty->has_dupliactes && \
	map_valididty->has_exit && map_valididty->has_solution && \
	map_valididty->has_spawn && map_valididty->is_rectangle && \
	map_valididty->is_walled)
		return (1);
	return (0);
}

void	validate_map_validity(char **map, \
t_map_validity *map_validity, char *enitre_map)
{
	int		i;
	int		number_of_lines;
	char	**map_copy;

	i = 0;
	number_of_lines = 0;
	while (map[number_of_lines] != 0)
		number_of_lines++;
	map_copy = (char **)malloc((number_of_lines + 1) * sizeof(char *));
	while (map[i] != 0)
	{
		map_copy[i] = ft_strdup(map[i]);
		i++;
	}
	map_copy[i] = 0;
	if (ft_strchr(enitre_map, 'C') != 0)
		map_validity->has_collect = 1;
	if (ft_strchr(enitre_map, 'E') != 0)
		map_validity->has_exit = 1;
	if (ft_strchr(enitre_map, 'P') != 0)
		map_validity->has_spawn = 1;
	is_map_walled(map, number_of_lines, map_validity, 0);
	is_rectangle(map, map_validity);
	find_solution(map_copy, map_validity, number_of_lines);
	free_split(map_copy);
}

char	**map_validificator(int fd, t_game_manager *game_manager)
{
	char			*temporary_string;
	char			*entire_map;
	char			**map;
	t_map_validity	*map_validity;

	temporary_string = get_next_line(fd);
	if (temporary_string == 0)
		return (f_norm_two(temporary_string));
	entire_map = (char *)malloc(1);
	entire_map[0] = '\0';
	while (temporary_string)
	{
		entire_map = ft_strjoint(entire_map, temporary_string);
		free(temporary_string);
		temporary_string = get_next_line(fd);
	}
	free(temporary_string);
	map = ft_split(entire_map, '\n');
	map_validity = initialise_map_validity(game_manager);
	f_norm(entire_map, map, map_validity);
	free(entire_map);
	error_handler(0, map_validity);
	if (final_check(map_validity))
		return (map);
	return (0);
}
