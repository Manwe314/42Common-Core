/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 10:54:19 by lkukhale          #+#    #+#             */
/*   Updated: 2023/02/01 20:47:02 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	valid_size(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-' || str[i] == '+')
			return (0);
		j = i + 1;
		while (str[j] != '\0')
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

void	print_base(char *str, int i, int *ptr)
{
	char	a;

	a = str[i];
	(*ptr)++;
	write(1, &a, 1);
}

void	convert(char *str, unsigned int num, int sz, int *ptr)
{
	int	d;
	int	r;

	d = num / sz;
	r = num % sz;
	if (d != 0)
		convert(str, d, sz, ptr);
	print_base(str, r, ptr);
}

void	putnbr_base(unsigned int nbr, char *base, int *ptr)
{
	int		v;

	v = valid_size(base);
	if (v != 0)
		convert(base, nbr, v, ptr);
}

int	ft_putnbr_base(unsigned int nbr, char *base)
{
	int		print_size;
	int		*ptr;

	print_size = 0;
	ptr = &print_size;
	putnbr_base(nbr, base, ptr);
	return (print_size);
}
