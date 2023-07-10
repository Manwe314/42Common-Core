/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stage1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:24:57 by lkukhale          #+#    #+#             */
/*   Updated: 2023/02/01 21:29:46 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_push_swap *swap_push)
{
	int		is_sorted;
	t_stack	*temp;

	is_sorted = 1;
	temp = swap_push->a;
	if (swap_push->b->index != -1)
		is_sorted = 0;
	while (temp->next->index != -1)
	{
		if ((temp->index > temp->next->index) && temp->next->index != -1)
			is_sorted = 0;
		temp = temp->next;
	}
	return (is_sorted);
}

int	stacked(t_push_swap *swap_push)
{
	t_stack	*temp;
	int		is_finished;

	temp = swap_push->a;
	is_finished = 1;
	while (temp->index != -1)
	{
		if (temp->index <= swap_push->second_third_size)
			is_finished = 0;
		temp = temp->next;
	}
	return (is_finished);
}

void	set_up_stacks(t_push_swap *swap_push)
{
	if (swap_push->a->index <= swap_push->first_third_size)
	{
		pb(swap_push);
		ft_printf("pb\n");
		if (swap_push->b->next->index > swap_push->first_third_size)
		{
			rb(swap_push);
			ft_printf("rb\n");
		}
	}
	if (swap_push->a->index > swap_push->first_third_size && \
	swap_push->a->index <= swap_push->second_third_size)
	{
		pb(swap_push);
		ft_printf("pb\n");
	}
	if (swap_push->a->index > swap_push->second_third_size)
	{
		ra(swap_push);
		ft_printf("ra\n");
	}
	if (!stacked(swap_push))
		set_up_stacks(swap_push);
}

void	finish_setting(t_push_swap *swap_push)
{
	if (swap_push->a->next->index == -1)
		return ;
	if (swap_push->a->index == swap_push->input_size)
	{
		ra(swap_push);
		ft_printf("ra\n");
	}
	pb(swap_push);
	ft_printf("pb\n");
	finish_setting(swap_push);
}
