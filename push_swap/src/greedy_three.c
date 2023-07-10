/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_three.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:55:12 by lkukhale          #+#    #+#             */
/*   Updated: 2023/02/01 21:22:14 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	to_a(t_push_swap *swap_push, int index)
{
	int	*info;
	int	i;

	info = find_placement(swap_push, index);
	i = 0;
	if (info[1] > info[0] / 2)
	{
		while (i != info[0] - info[1])
		{
			rra(swap_push);
			ft_printf("rra\n");
			i++;
		}
	}
	else
	{
		while (i != info[1])
		{
			ra(swap_push);
			ft_printf("ra\n");
			i++;
		}
	}
	free(info);
}

void	move_index(t_push_swap *swap_push, int index)
{
	to_top_of_b(swap_push, index);
	to_a(swap_push, index);
	pa(swap_push);
	ft_printf("pa\n");
}

void	greedy(t_push_swap *swap_push)
{
	int	index;

	while (swap_push->b->index != -1)
	{
		index = get_index_to_move(swap_push);
		move_index(swap_push, index);
	}
}

void	order(t_push_swap *swap_push)
{
	while (swap_push->a->index != 1)
	{
		ra(swap_push);
		ft_printf("ra\n");
	}
}
