/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_two.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 20:48:32 by lkukhale          #+#    #+#             */
/*   Updated: 2023/03/10 20:49:14 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "push_swap_bonus.h"
#include "get_next_line.h"

int	operate_swap(char *instruction, t_push_swap *swap_push)
{
	if (instruction[1] == 's')
	{
		ss(swap_push);
		return (0);
	}
	if (instruction[1] == 'a')
	{
		sa(swap_push);
		return (0);
	}
	if (instruction[1] == 'b')
	{
		sb(swap_push);
		return (0);
	}
	return (1);
}

int	operate_push(char *instruction, t_push_swap *swap_push)
{
	if (instruction[1] == 'a')
	{
		pa(swap_push);
		return (0);
	}
	if (instruction[1] == 'b')
	{
		pb(swap_push);
		return (0);
	}
	return (1);
}

int	operate_rotate(char *instruction, t_push_swap *swap_push)
{
	if (instruction[1] == 'r')
	{
		rr(swap_push);
		return (0);
	}
	if (instruction[1] == 'a')
	{
		ra(swap_push);
		return (0);
	}
	if (instruction[1] == 'b')
	{
		rb(swap_push);
		return (0);
	}
	return (1);
}
