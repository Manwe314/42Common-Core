/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:10:03 by lkukhale          #+#    #+#             */
/*   Updated: 2023/02/02 17:57:20 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include "ft_printf.h"
# include "libft.h"

typedef struct s_stack
{
	int				index;
	int				value;
	struct s_stack	*next;
}	t_stack;

typedef struct s_push_swap
{
	t_stack	*a;
	t_stack	*b;
	int		*input;
	int		input_size;
	int		first_third_size;
	int		second_third_size;
}	t_push_swap;

int			*sort(int size, char **argv, t_push_swap *swap_push);
int			*duplicate(int *array, int size);
void		quick_sort(int *array, int low, int high);
int			partition(int *array, int low, int high);
void		swap(int *a, int *b);
int			validate(char **argv, int size);
int			duplicate_check(char **argv, int size);
int			size_check(char **argv, int size);
int			character_check(char **argv, int size);
void		thirds_split(t_push_swap *swap_push);
int			get_index(int *array, int value, int size);
void		set_stack_a(int *array, t_push_swap *swap_push);
void		set_stack_b(t_push_swap *swap_push);
void		sa(t_push_swap *swap_push);
void		ra(t_push_swap *swap_push);
void		rra(t_push_swap *swap_push);
void		pa(t_push_swap *swap_push);
void		sb(t_push_swap *swap_push);
void		rb(t_push_swap *swap_push);
void		rrb(t_push_swap *swap_push);
void		pb(t_push_swap *swap_push);
void		ss(t_push_swap *swap_push);
void		rr(t_push_swap *swap_push);
void		rrr(t_push_swap *swap_push);
t_push_swap	*handle_input(char **argv, int argc);
int			is_sorted(t_push_swap *swap_push);
int			stacked(t_push_swap *swap_push);
void		set_up_stacks(t_push_swap *swap_push);
void		finish_setting(t_push_swap *swap_push);
int			steps_to_top_of_b(t_push_swap *swap_push, t_stack *temp);
int			is_in_middle(t_stack *start, int id, int high);
int			get_a_ready(t_push_swap *swap_push, t_stack *temp);
int			get_moves(t_push_swap *swap_push, t_stack *temp);
int			get_index_to_move(t_push_swap *swap_push);
int			*get_size_and_position(t_push_swap *swap_push, int index);
void		to_top_of_b(t_push_swap *swap_push, int index);
int			a_size(t_push_swap *swap_push);
int			find_best_middle(t_stack *temp, int index);
int			*find_placement(t_push_swap *swap_push, int index);
void		to_a(t_push_swap *swap_push, int index);
void		move_index(t_push_swap *swap_push, int index);
void		greedy(t_push_swap *swap_push);
void		order(t_push_swap *swap_push);
void		clean_up(t_push_swap *swap_push);
void		input_size_three(t_push_swap *s);
void		input_size_four(t_push_swap *s);
void		input_size_five(t_push_swap *s);
void		small_input_case(t_push_swap *swap_push, int size);

#endif