/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:08:51 by lkukhale          #+#    #+#             */
/*   Updated: 2022/11/30 20:35:22 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	sizeer(uintptr_t ptr)
{
	int	print_size;

	print_size = 0;
	while (ptr != 0)
	{
		print_size++;
		ptr = ptr / 16;
	}
	return (print_size);
}

int	putpointer(uintptr_t ptr)
{
	int	print_size;

	print_size = sizeer(ptr);
	if (ptr >= 16)
	{
		putpointer(ptr / 16);
		putpointer(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar_fd((ptr + '0'), 1);
		else
			ft_putchar_fd((ptr - 10 + 'a'), 1);
	}
	return (print_size);
}
