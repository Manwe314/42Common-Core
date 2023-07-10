/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:54:16 by lkukhale          #+#    #+#             */
/*   Updated: 2023/03/10 20:50:57 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

void	check(t_push_swap *swap_push);
int		operate_swap(char *instruction, t_push_swap *swap_push);
int		operate_push(char *instruction, t_push_swap *swap_push);
int		operate_rotate(char *instruction, t_push_swap *swap_push);
int		operate_on_two(char *instruction, t_push_swap *swap_push);
int		operate(char *instruction, t_push_swap *swap_push);
int		error(void);
int		do_instructions(t_push_swap *swap_push);
void	check(t_push_swap *swap_push);
#endif