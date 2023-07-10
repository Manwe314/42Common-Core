/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_one.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:53:33 by lkukhale          #+#    #+#             */
/*   Updated: 2023/02/01 21:24:21 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	steps_to_top_of_b(t_push_swap *swap_push, t_stack *temp)
{
	int		size;
	int		position;
	t_stack	*counter;

	size = 0;
	counter = swap_push->b;
	while (counter->index != -1)
	{
		if (counter->index == temp->index)
			position = size;
		size++;
		counter = counter->next;
	}
	if (size / 2 < position)
		return (size - position);
	return (position);
}

int	is_in_middle(t_stack *start, int id, int high)
{
	int	i;

	i = 0;
	while (start->index != -1)
	{
		if (high > start->index > id)
		{
			i = 1;
		}
		start = start->next;
	}
	return (i);
}

int	get_a_ready(t_push_swap *swap_push, t_stack *temp)
{
	int		moves;
	t_stack	*test;

	moves = 0;
	if (swap_push->a->next->index == -1)
		return (moves);
	test = swap_push->a;
	while (test->index != -1)
	{
		if (test->index > temp->index)
		{
			if (!is_in_middle(test, temp->index, test->index))
				break ;
		}
		moves++;
		test = test->next;
	}
	return (moves);
}

int	get_moves(t_push_swap *swap_push, t_stack *temp)
{
	int		moves;
	int		size;
	int		buffer;
	t_stack	*counter;

	moves = 0;
	counter = swap_push->a;
	size = 0;
	while (counter->index != -1)
	{
		size++;
		counter = counter->next;
	}
	buffer = get_a_ready(swap_push, temp);
	if (buffer > size / 2)
		moves += (size - buffer);
	else
		moves += buffer;
	moves += steps_to_top_of_b(swap_push, temp);
	return (moves);
}

int	get_index_to_move(t_push_swap *swap_push)
{
	int		min;
	int		tmp;
	int		index;
	t_stack	*temp;

	temp = swap_push->b;
	min = 2000000000;
	index = -1;
	while (temp->index != -1)
	{
		tmp = get_moves(swap_push, temp);
		if (tmp < min)
		{
			min = tmp;
			index = temp->index;
		}
		temp = temp->next;
	}
	return (index);
}
