/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:34:06 by lkukhale          #+#    #+#             */
/*   Updated: 2023/02/01 21:28:24 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	thirds_split(t_push_swap *swap_push)
{
	int	remeinder;
	int	temp;

	remeinder = swap_push->input_size % 3;
	temp = swap_push->input_size;
	temp -= remeinder;
	swap_push->first_third_size = (temp / 3);
	swap_push->second_third_size = (temp / 3) * 2;
}

int	get_index(int *array, int value, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (array[i] == value)
			return (i + 1);
		i++;
	}
	return (i);
}

void	set_stack_a(int *array, t_push_swap *swap_push)
{
	t_stack	*a_head;
	t_stack	*temp;
	int		i;

	a_head = malloc(sizeof(t_stack));
	a_head->index = -1;
	a_head->next = 0;
	i = 0;
	while (i < swap_push->input_size)
	{
		temp = a_head;
		a_head = malloc(sizeof(t_stack));
		a_head->next = temp;
		a_head->value = swap_push->input[swap_push->input_size - 1 - i];
		a_head->index = get_index(array, a_head->value, swap_push->input_size);
		i++;
	}
	swap_push->a = a_head;
}

void	set_stack_b(t_push_swap *swap_push)
{
	t_stack	*b_head;

	b_head = malloc(sizeof(t_stack));
	b_head->index = -1;
	b_head->next = 0;
	swap_push->b = b_head;
}

t_push_swap	*handle_input(char **argv, int argc)
{
	t_push_swap	*swap_push;
	int			*array;

	swap_push = (t_push_swap *)malloc(sizeof(t_push_swap));
	swap_push->input_size = argc - 1;
	thirds_split(swap_push);
	array = sort(argc - 1, argv, swap_push);
	set_stack_a(array, swap_push);
	set_stack_b(swap_push);
	free(array);
	return (swap_push);
}
