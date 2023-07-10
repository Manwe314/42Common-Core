/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:56:31 by lkukhale          #+#    #+#             */
/*   Updated: 2023/04/28 20:13:03 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_handler(char *msg, t_map_validity *map_valid)
{
	if (map_valid == 0)
	{
		ft_printf("Error\n%s\n", msg);
		return (0);
	}
	if (map_valid->is_walled == 0)
		error_handler("The map is not Walled in", 0);
	if (map_valid->is_rectangle == 0)
		error_handler("The map is not a rectangle", 0);
	if (map_valid->has_dupliactes == 0)
		error_handler("There are 2 Spawn (P) or Exit (E) points", 0);
	if (map_valid->has_exit == 0)
		error_handler("The map has no exit (E) point", 0);
	if (map_valid->has_spawn == 0)
		error_handler("The map has no spawn (P) point", 0);
	if (map_valid->has_collect == 0)
		error_handler("The map has no collectable (C)", 0);
	if (map_valid->has_solution == 0)
		error_handler("The map has no solution", 0);
	if (map_valid->invalid_characters == 0)
		error_handler("Incorrect characters in the map!", 0);
	return (1);
}

void	find_solution(char **map, \
t_map_validity *map_validity, int number_of_lines)
{
	int	row;
	int	col;

	if (map_validity->is_rectangle != 1)
		return ;
	row = 0;
	while (map[row] != 0)
	{
		col = 0;
		while (map[row][col] != '\0')
		{
			if (map[row][col] == 'P')
				recursive_find(map, row, col, number_of_lines);
			col++;
		}
		row++;
	}
	check_solution(map, map_validity);
}

void	check_solution(char **map, t_map_validity *map_validity)
{
	int	i;

	i = 0;
	map_validity->has_solution = 1;
	while (map[i] != 0)
	{
		if (ft_strchr(map[i], 'C') != 0)
			map_validity->has_solution = 0;
		if (ft_strchr(map[i], 'E') != 0)
			map_validity->has_solution = 0;
		i++;
	}
}

void	recursive_find(char **map, int row, int col, int number_of_lines)
{
	if (row < 0 || col < 0 || row > number_of_lines - 1 \
	|| col > ft_strlennl(map[0]) - 1)
		return ;
	if (map[row][col] == 'P' || map[row][col] == 'E' || \
	map[row][col] == 'C' || map[row][col] == '0')
	{
		map[row][col] = '1';
		recursive_find(map, row - 1, col, number_of_lines);
		recursive_find(map, row + 1, col, number_of_lines);
		recursive_find(map, row, col - 1, number_of_lines);
		recursive_find(map, row, col + 1, number_of_lines);
	}
}

void	has_duplicates(char *map, t_map_validity *map_validity)
{
	char	**duplicates;
	char	*str;
	int		i;

	i = 0;
	str = map;
	duplicates = ft_split(str, 'P');
	map_validity->has_dupliactes = 1;
	while (duplicates[i] != 0)
		i++;
	if (i != 2)
		map_validity->has_dupliactes = 0;
	i = 0;
	free_split(duplicates);
	duplicates = ft_split(str, 'E');
	i = 0;
	while (duplicates[i] != 0)
		i++;
	if (i != 2)
		map_validity->has_dupliactes = 0;
	free_split(duplicates);
}
