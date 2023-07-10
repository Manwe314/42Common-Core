/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:52:41 by lkukhale          #+#    #+#             */
/*   Updated: 2023/04/28 14:44:43 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	character_check(char **argv, int size)
{
	int	i;
	int	j;
	int	is_valid;

	i = 1;
	is_valid = 1;
	while (i <= size)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if ((argv[i][j] < '0' || argv[i][j] > '9') && argv[i][j] != '-')
				is_valid = 0;
			if (ft_strlen(argv[i]) == 1 && argv[i][j] == '-')
				is_valid = 0;
			j++;
		}
		if (ft_strlen(argv[i]) < 1)
			is_valid = 0;
		i++;
	}
	return (is_valid);
}

int	size_check(char **argv, int size)
{
	int	i;
	int	is_valid;

	i = 1;
	is_valid = 1;
	while (i <= size)
	{
		if (ft_strlen(argv[i]) > 11)
			is_valid = 0;
		if (ft_strlen(argv[i]) == 10)
		{
			if (ft_strncmp("2147483647", argv[i], 10) < 0)
				is_valid = 0;
		}
		if (ft_strlen(argv[i]) == 11)
		{
			if (ft_strncmp("-2147483647", argv[i], 11) < 0)
				is_valid = 0;
		}
		i++;
	}
	return (is_valid);
}

int	duplicate_check(char **argv, int size)
{
	int	i;
	int	j;
	int	is_valid;

	i = 1;
	is_valid = 1;
	while (i <= size)
	{
		j = i + 1;
		while (j <= size)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				is_valid = 0;
			j++;
		}
		i++;
	}
	return (is_valid);
}

int	validate(char **argv, int size)
{
	int	is_valid;

	is_valid = 0;
	if (!character_check(argv, size))
		return (is_valid);
	if (!size_check(argv, size))
		return (is_valid);
	if (!duplicate_check(argv, size))
		return (is_valid);
	is_valid = 1;
	return (is_valid);
}
