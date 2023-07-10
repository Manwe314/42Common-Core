/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:57:51 by lkukhale          #+#    #+#             */
/*   Updated: 2023/02/23 18:32:16 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_push_swap *swap_push)
{
	t_stack	*temp;

	if (swap_push->a->index == -1 || swap_push->a->next->index == -1)
		return ;
	temp = swap_push->a->next;
	swap_push->a->next = swap_push->a->next->next;
	temp->next = swap_push->a;
	swap_push->a = temp;
}

void	ra(t_push_swap *swap_push)
{
	t_stack	*temp1;
	t_stack	*minusone;
	t_stack	*previouslast;

	if (swap_push->a->index == -1)
		return ;
	temp1 = swap_push->a->next;
	minusone = swap_push->a;
	previouslast = swap_push->a;
	while (previouslast->next->index != -1)
		previouslast = previouslast->next;
	while (minusone->index != -1)
		minusone = minusone->next;
	swap_push->a->next = minusone;
	previouslast->next = swap_push->a;
	swap_push->a = temp1;
}

void	rra(t_push_swap *swap_push)
{
	t_stack	*temp;
	t_stack	*b4;

	if (swap_push->a->index == -1)
		return ;
	temp = swap_push->a;
	b4 = swap_push->a;
	while (swap_push->a->next->index != -1)
		swap_push->a = swap_push->a->next;
	while (b4->next->next->index != -1)
		b4 = b4->next;
	b4->next = b4->next->next;
	swap_push->a->next = temp;
}

void	pa(t_push_swap *swap_push)
{
	t_stack	*temp;

	if (swap_push->b->index == -1)
		return ;
	temp = swap_push->b;
	swap_push->b = swap_push->b->next;
	temp->next = swap_push->a;
	swap_push->a = temp;
}
