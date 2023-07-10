/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_one.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 20:46:33 by lkukhale          #+#    #+#             */
/*   Updated: 2023/04/28 19:41:19 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "push_swap_bonus.h"
#include "get_next_line.h"

int	operate_on_two(char *instruction, t_push_swap *swap_push)
{
	if (instruction[0] == 'r')
	{
		if (operate_rotate(instruction, swap_push))
			return (1);
	}
	if (instruction[0] == 's')
	{
		if (operate_swap(instruction, swap_push))
			return (1);
	}
	if (instruction[0] == 'p')
	{
		if (operate_push(instruction, swap_push))
			return (1);
	}
	return (0);
}

int	operate(char *instruction, t_push_swap *swap_push)
{
	if (instruction[2] != '\n')
	{
		if (ft_strncmp(instruction, "rrr", 3) == 0)
		{
			rrr(swap_push);
			return (0);
		}
		if (ft_strncmp(instruction, "rra", 3) == 0)
		{
			rra(swap_push);
			return (0);
		}
		if (ft_strncmp(instruction, "rrb", 3) == 0)
		{
			rrb(swap_push);
			return (0);
		}
		return (1);
	}
	else
	{
		if (operate_on_two(instruction, swap_push))
			return (1);
		return (0);
	}
}

int	error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (1);
}

int	do_instructions(t_push_swap *swap_push)
{
	char	*instruction;

	instruction = get_next_line(0);
	while (instruction != 0)
	{
		if (operate(instruction, swap_push))
		{
			free(instruction);
			return (error());
		}
		free(instruction);
		instruction = get_next_line(0);
	}
	free(instruction);
	check(swap_push);
	return (0);
}

void	check(t_push_swap *swap_push)
{
	t_stack	*temp;

	if (swap_push->b->index != -1)
	{
		ft_printf("KO\n");
		return ;
	}
	temp = swap_push->a;
	while (temp->next->index != -1)
	{
		if (temp->index > temp->next->index)
		{
			ft_printf("KO\n");
			return ;
		}
		temp = temp->next;
	}
	ft_printf("OK\n");
}
