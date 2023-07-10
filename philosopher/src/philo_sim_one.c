/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sim_one.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:07:34 by lkukhale          #+#    #+#             */
/*   Updated: 2023/04/24 20:48:25 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	act(t_param *param, int id, char action, t_philo *philo)
{
	if (action == 's' && !check_sim(philo))
	{
		pthread_mutex_lock(&(param->writing));
		printf("%ld %d is sleeping\n", get_time() - param->sim_start, id);
		pthread_mutex_unlock(&(param->writing));
	}
	if (action == 'f' && !check_sim(philo))
	{
		pthread_mutex_lock(&(param->writing));
		printf("%ld %d has taken a fork\n", get_time() - param->sim_start, id);
		pthread_mutex_unlock(&(param->writing));
	}
	if (action == 'e' && !check_sim(philo))
	{
		pthread_mutex_lock(&(param->writing));
		printf("%ld %d is eating\n", get_time() - param->sim_start, id);
		pthread_mutex_unlock(&(param->writing));
	}
	if (action == 'd')
	{
		pthread_mutex_lock(&(param->writing));
		printf("%ld %d died\n", get_time() - param->sim_start, id);
		pthread_mutex_unlock(&(param->writing));
	}
}

int	check_death(t_philo *philo)
{
	if (get_time() - philo->last_time_eaten >= philo->time_to_die)
	{
		pthread_mutex_lock(&(philo->param->param_change));
		philo->param->philosopher_has_died = 1;
		pthread_mutex_unlock(&(philo->param->param_change));
		return (1);
	}
	return (0);
}

void	snooz(long duration, t_philo *philo)
{
	long	start_time;

	start_time = get_time();
	while (get_time() < start_time + duration)
	{
		if (check_sim(philo))
			break ;
		usleep(250);
	}
	if (check_death(philo))
	{
		pthread_mutex_lock(&(philo->param->param_change));
		if (philo->param->death_announced == 0)
			act(philo->param, philo->id, 'd', philo);
		philo->param->death_announced = 1;
		pthread_mutex_unlock(&(philo->param->param_change));
	}
}

void	try_to_eat(t_philo *philo)
{
	pthread_mutex_lock(&(philo->right_fork));
	act(philo->param, philo->id, 'f', philo);
	pthread_mutex_lock(&(philo->next_philo->right_fork));
	act(philo->param, philo->id, 'f', philo);
	act(philo->param, philo->id, 'e', philo);
	philo->last_time_eaten = get_time();
	snooz((long)philo->param->time_to_eat, philo);
	philo->amount_of_times_has_eaten += 1;
	pthread_mutex_unlock(&(philo->right_fork));
	pthread_mutex_unlock(&(philo->next_philo->right_fork));
	pthread_mutex_lock(&(philo->param->param_change));
	if (philo->amount_of_times_has_eaten \
	== philo->param->times_each_philosopher_must_eat)
		philo->param->philos_that_ate_enough_times += 1;
	pthread_mutex_unlock(&(philo->param->param_change));
}

int	check_sim(t_philo *philo)
{
	int	must_end;

	must_end = 0;
	check_death(philo);
	pthread_mutex_lock(&(philo->param->param_change));
	if (philo->param->philosopher_has_died == 1)
	{
		if (philo->param->death_announced == 0)
		{
			act(philo->param, philo->id, 'd', philo);
			philo->param->death_announced = 1;
		}
		must_end = 1;
	}
	if (philo->param->number_of_philosophers \
	== philo->param->philos_that_ate_enough_times)
		must_end = 1;
	pthread_mutex_unlock(&(philo->param->param_change));
	return (must_end);
}
