/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_clean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:56:20 by lkukhale          #+#    #+#             */
/*   Updated: 2023/02/01 21:29:20 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clean_up(t_push_swap *swap_push)
{
	t_stack	*temp;

	free(swap_push->b);
	free(swap_push->input);
	while (swap_push->a->index != -1)
	{
		temp = swap_push->a->next;
		free(swap_push->a);
		swap_push->a = temp;
	}
	free(swap_push->a);
	free(swap_push);
}

void	input_size_three(t_push_swap *s)
{
	if (s->a->index == 1)
	{
		ft_printf("pb\n");
		ft_printf("sa\n");
		ft_printf("pa\n");
	}
	if (s->a->index == 3 && s->a->next->index == 1)
		ft_printf("ra\n");
	if (s->a->index == 3 && s->a->next->index == 2)
	{
		ft_printf("ra\n");
		ft_printf("sa\n");
	}
	if (s->a->index == 2 && s->a->next->index == 1)
		ft_printf("sa\n");
	if (s->a->index == 2 && s->a->next->index == 3)
		ft_printf("rra\n");
}

void	input_size_four(t_push_swap *s)
{
	while (s->a->next->next->index != -1)
	{
		if (s->a->index == 2 || s->a->index == 1)
		{
			pb(s);
			ft_printf("pb\n");
		}
		else
		{
			ra(s);
			ft_printf("ra\n");
		}
	}
	if (s->a->index == 4 && s->b->index == 1)
		ft_printf("ss\n");
	if (s->a->index == 4 && s->b->index != 1)
		ft_printf("sa\n");
	if (s->a->index != 4 && s->b->index == 1)
		ft_printf("sb\n");
	ft_printf("pa\n");
	ft_printf("pa\n");
}

void	input_size_five(t_push_swap *s)
{
	while (s->a->next->next->index != -1)
	{
		if (s->a->index < 4)
		{
			pb(s);
			ft_printf("pb\n");
			if (s->b->index < s->b->next->index)
			{
				sb(s);
				ft_printf("sb\n");
			}
		}
		else
		{
			ra(s);
			ft_printf("ra\n");
		}
	}
	if (s->a->index == 5)
		ft_printf("sa\n");
	ft_printf("pa\n");
	if (s->b->next->index == 1)
		ft_printf("sb\n");
	ft_printf("pa\n");
	ft_printf("pa\n");
}

void	small_input_case(t_push_swap *swap_push, int size)
{
	if (size == 2)
	{
		sa(swap_push);
		ft_printf("sa\n");
	}
	if (size == 3)
		input_size_three(swap_push);
	if (size == 4)
		input_size_four(swap_push);
	if (size == 5)
		input_size_five(swap_push);
}
