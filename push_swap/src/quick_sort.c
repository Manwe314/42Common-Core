/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:38:24 by lkukhale          #+#    #+#             */
/*   Updated: 2023/02/01 21:29:02 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	partition(int *array, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = array[high];
	i = (low - 1);
	j = low;
	while (j <= high - 1)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
		j++;
	}
	swap(&array[i + 1], &array[high]);
	return (i + 1);
}

void	quick_sort(int *array, int low, int high)
{
	int	pivot;

	if (low < high)
	{
		pivot = partition(array, low, high);
		quick_sort(array, low, pivot - 1);
		quick_sort(array, pivot + 1, high);
	}
}

int	*duplicate(int *array, int size)
{
	int	i;
	int	*duplicat;

	duplicat = malloc(size * sizeof(int));
	i = 0;
	while (i < size)
	{
		duplicat[i] = array[i];
		i++;
	}
	return (duplicat);
}

int	*sort(int size, char **argv, t_push_swap *swap_push)
{
	int	*array;
	int	i;

	array = malloc(size * sizeof(int));
	i = 0;
	while (i < size)
	{
		array[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	swap_push->input = duplicate(array, size);
	quick_sort(array, 0, size - 1);
	return (array);
}
