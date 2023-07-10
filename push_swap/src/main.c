/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:51:21 by lkukhale          #+#    #+#             */
/*   Updated: 2023/03/29 19:54:48 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_push_swap	*swap_push;

	if (argc < 2 || !validate(argv, argc - 1))
	{
		if (argc != 1)
			ft_putstr_fd("Error\n", 0);
		return (0);
	}
	swap_push = handle_input(argv, argc);
	if (!is_sorted(swap_push))
	{
		if (argc - 1 > 5)
		{
			set_up_stacks(swap_push);
			finish_setting(swap_push);
			greedy(swap_push);
			order(swap_push);
		}
		else
		{
			small_input_case(swap_push, argc - 1);
		}
		clean_up(swap_push);
	}
	return (0);
}
