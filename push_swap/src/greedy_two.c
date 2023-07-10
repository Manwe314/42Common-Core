/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:54:20 by lkukhale          #+#    #+#             */
/*   Updated: 2023/02/01 21:27:44 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*get_size_and_position(t_push_swap *swap_push, int index)
{
	int		size;
	int		position;
	int		*ret;
	t_stack	*counter;

	size = 0;
	counter = swap_push->b;
	ret = malloc(2 * sizeof(int));
	while (counter->index != -1)
	{
		if (counter->index == index)
			position = size;
		size++;
		counter = counter->next;
	}
	ret[0] = size;
	ret[1] = position;
	return (ret);
}

void	to_top_of_b(t_push_swap *swap_push, int index)
{
	int	i;
	int	*info;

	i = 0;
	info = get_size_and_position(swap_push, index);
	if ((info[0] / 2) < info[1])
	{
		while (i != info[0] - info[1])
		{
			rrb(swap_push);
			ft_printf("rrb\n");
			i++;
		}
	}
	else
	{
		while (i != info[1])
		{
			rb(swap_push);
			ft_printf("rb\n");
			i++;
		}
	}
	free(info);
}

int	a_size(t_push_swap *swap_push)
{
	t_stack	*temp;
	int		size;

	temp = swap_push->a;
	size = 0;
	while (temp->index != -1)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}

int	find_best_middle(t_stack *temp, int index)
{
	int		offset;
	int		min;
	int		id;
	t_stack	*counter;

	offset = 0;
	min = 200000000;
	counter = temp;
	while (counter->index != -1)
	{
		if ((counter->index - index) < min && (counter->index - index) > 0)
		{
			min = counter->index - index;
			id = counter->index;
		}
		counter = counter->next;
	}
	while (temp->index != id)
	{
		offset++;
		temp = temp->next;
	}
	return (offset);
}

int	*find_placement(t_push_swap *swap_push, int index)
{
	int		*ret;
	int		position;
	t_stack	*temp;

	ret = malloc(2 * sizeof(int));
	temp = swap_push->a;
	position = 0;
	while (temp->index != -1)
	{
		if (temp->index > index)
		{
			if (!is_in_middle(temp, index, temp->index))
			{
				position += find_best_middle(temp, index);
				break ;
			}
		}
		position++;
		temp = temp->next;
	}
	ret[0] = a_size(swap_push);
	ret[1] = position;
	return (ret);
}
