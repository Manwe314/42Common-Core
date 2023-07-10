/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_norm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:13:56 by lkukhale          #+#    #+#             */
/*   Updated: 2023/04/28 20:17:06 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	f_norm(char *entire_map, char **map, t_map_validity *map_validity)
{
	character_check(entire_map, map_validity);
	has_duplicates(entire_map, map_validity);
	validate_map_validity(map, map_validity, entire_map);
}

char	**f_norm_two(char *f_norm)
{
	free(f_norm);
	return (0);
}
