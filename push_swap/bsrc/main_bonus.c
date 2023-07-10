/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:53:52 by lkukhale          #+#    #+#             */
/*   Updated: 2023/03/10 20:49:33 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "push_swap_bonus.h"
#include "get_next_line.h"

int	main(int argc, char *argv[])
{
	t_push_swap	*swap_push;

	if (argc < 2 || !validate(argv, argc - 1))
	{
		if (argc > 1)
			ft_putstr_fd("Error\n", 0);
		return (0);
	}
	swap_push = handle_input(argv, argc);
	if (do_instructions(swap_push) != 0)
		ft_putstr_fd("Incorrect instruction\n", 2);
	return (0);
}
