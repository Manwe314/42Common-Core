/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_info_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 19:22:07 by lkukhale          #+#    #+#             */
/*   Updated: 2023/02/02 18:04:35 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_p(char **map, char index)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != 0)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'P')
			{
				if (index == 'x')
					return (i);
				else if (index == 'y')
					return (j);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	find_e(char **map, char index)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != 0)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'E')
			{
				if (index == 'x')
					return (i);
				else if (index == 'y')
					return (j);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	*point_finder(char *to_find, char **map)
{
	int	*position;

	position = malloc(2 * sizeof(int));
	if (ft_strncmp("spawn", to_find, 5) == 0)
	{
		position[0] = find_p(map, 'x');
		position[1] = find_p(map, 'y');
	}
	if (ft_strncmp("exit", to_find, 4) == 0)
	{
		position[0] = find_e(map, 'x');
		position[1] = find_e(map, 'y');
	}
	return (position);
}
