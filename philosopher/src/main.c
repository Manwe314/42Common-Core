/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:10:50 by lkukhale          #+#    #+#             */
/*   Updated: 2023/05/29 16:34:11 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clean_up(t_param *param)
{
	t_philo	*philo;
	t_philo	*temp;

	pthread_mutex_destroy(&(param->writing));
	pthread_mutex_destroy(&(param->param_change));
	philo = param->philosopher;
	while (philo->id < param->number_of_philosophers)
	{
		pthread_mutex_destroy(&(philo->right_fork));
		temp = philo;
		philo = philo->next_philo;
		free(temp);
	}
	pthread_mutex_destroy(&(philo->right_fork));
	free (philo);
}

int	main(int argc, char *argv[])
{
	t_param	param;

	if (argc != 5 && argc != 6)
		return (error("Invalid Number of Arguments\n"));
	if (set_input(&param, argv, argc))
		return (error("Input set up failed\n"));
	if (run_simulation(&param))
		return (error("Problem with creating threads\n"));
	clean_up(&param);
	return (0);
}
