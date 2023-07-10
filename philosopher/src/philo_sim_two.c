/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sim_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:09:05 by lkukhale          #+#    #+#             */
/*   Updated: 2023/04/24 20:25:47 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philosopher(void *phi)
{
	t_philo	*philo;

	philo = (t_philo *)phi;
	snooz((long)philo->offset, philo);
	while (1)
	{
		try_to_eat(philo);
		act(philo->param, philo->id, 's', philo);
		snooz((long)philo->param->time_to_sleep, philo);
		if (check_sim(philo))
			return (NULL);
		if (!check_sim(philo))
		{
			pthread_mutex_lock(&(philo->param->writing));
			printf("%ld %d is thinking\n", \
			get_time() - philo->param->sim_start, philo->id);
			pthread_mutex_unlock(&(philo->param->writing));
		}
		if (check_sim(philo))
			return (NULL);
	}
	return (NULL);
}

void	*one_philosopher(void *phi)
{
	t_philo	*philo;

	philo = (t_philo *)phi;
	act(philo->param, philo->id, 'f', philo);
	snooz((long)philo->param->time_to_die, philo);
	return (NULL);
}

int	simulate_one(t_param *param)
{
	t_philo	*temp;

	temp = param->philosopher;
	param->sim_start = get_time();
	temp->last_time_eaten = get_time();
	if (pthread_create(&(temp->thread_id), NULL, one_philosopher, temp))
		return (1);
	pthread_join(temp->thread_id, NULL);
	return (0);
}

int	run_simulation(t_param *param)
{
	int		i;
	t_philo	*temp;

	if (param->number_of_philosophers == 1)
		return (simulate_one(param));
	i = 0;
	temp = param->philosopher;
	param->sim_start = get_time();
	while (i < param->number_of_philosophers)
	{
		temp->last_time_eaten = get_time();
		if (pthread_create(&(temp->thread_id), NULL, philosopher, temp))
			return (1);
		temp = temp->next_philo;
		i++;
	}
	temp = param->philosopher;
	while (temp->id < param->number_of_philosophers)
	{
		pthread_join(temp->thread_id, NULL);
		temp = temp->next_philo;
	}
	pthread_join(temp->thread_id, NULL);
	return (0);
}
