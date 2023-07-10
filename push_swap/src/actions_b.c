/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:59:26 by lkukhale          #+#    #+#             */
/*   Updated: 2023/03/10 20:54:20 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_push_swap *swap_push)
{
	t_stack	*temp;

	if (swap_push->b->index == -1 || swap_push->b->next->index == -1)
		return ;
	temp = swap_push->b->next;
	swap_push->b->next = swap_push->b->next->next;
	temp->next = swap_push->b;
	swap_push->b = temp;
}

void	rb(t_push_swap *swap_push)
{
	t_stack	*temp1;
	t_stack	*minusone;
	t_stack	*previouslast;

	if (swap_push->b->index == -1)
		return ;
	temp1 = swap_push->b->next;
	minusone = swap_push->b;
	previouslast = swap_push->b;
	while (previouslast->next->index != -1)
		previouslast = previouslast->next;
	while (minusone->index != -1)
		minusone = minusone->next;
	swap_push->b->next = minusone;
	previouslast->next = swap_push->b;
	swap_push->b = temp1;
}

void	rrb(t_push_swap *swap_push)
{
	t_stack	*temp;
	t_stack	*b4;

	if (swap_push->b->index == -1)
		return ;
	temp = swap_push->b;
	b4 = swap_push->b;
	while (swap_push->b->next->index != -1)
		swap_push->b = swap_push->b->next;
	while (b4->next->next->index != -1)
		b4 = b4->next;
	b4->next = b4->next->next;
	swap_push->b->next = temp;
}

void	pb(t_push_swap *swap_push)
{
	t_stack	*temp;

	if (swap_push->a->index == -1)
		return ;
	temp = swap_push->a;
	swap_push->a = swap_push->a->next;
	temp->next = swap_push->b;
	swap_push->b = temp;
}
