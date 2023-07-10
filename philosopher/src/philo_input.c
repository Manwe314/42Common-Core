/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:46:38 by lkukhale          #+#    #+#             */
/*   Updated: 2023/03/14 17:35:47 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	validate(t_param *param)
{
	if (param->number_of_philosophers <= 0)
		return (error("0 or less philosophers\n"));
	if (param->time_to_die <= 0)
		return (error("0 or less MS for time to die\n"));
	if (param->time_to_eat <= 0)
		return (error("0 or less MS for time to eat\n"));
	if (param->time_to_sleep <= 0)
		return (error("0 or less MS for time to sleep\n"));
	if (param->times_each_philosopher_must_eat < -1)
		return (error("Times each philosopher must eat \
		is optional write -1 OR nothing to disable it\n"));
	return (0);
}

int	get_offset(int id, t_param *param)
{
	int	even_constant_offset;
	int	count;
	int	offset_interval;

	if (param->number_of_philosophers % 2 == 1)
		even_constant_offset = (param->number_of_philosophers / 2) + 1;
	else
		even_constant_offset = param->number_of_philosophers / 2;
	offset_interval = get_offset_interval(param);
	count = 0;
	if (id % 2 == 1 || id == 1)
	{
		while (id - (2 * count + 1) >= 0)
			count++;
		return (count * offset_interval);
	}
	else
		return (((id / 2) + even_constant_offset) * offset_interval);
}

void	initilize_philo(t_philo *philo, int id, t_param *param)
{
	philo->id = id + 1;
	philo->amount_of_times_has_eaten = 0;
	philo->param = param;
	philo->time_to_die = param->time_to_die;
	philo->offset = get_offset(philo->id, param);
	if (pthread_mutex_init(&(philo->right_fork), NULL))
		error("Fork mutex could not initilize\n");
}

int	list_the_philosophers(t_param *param)
{
	int		i;
	t_philo	*philo;
	t_philo	*temp;

	i = 1;
	philo = (t_philo *)malloc(sizeof(t_philo));
	if (philo == 0)
		return (1);
	initilize_philo(philo, 0, param);
	param->philosopher = philo;
	temp = philo;
	while (i < param->number_of_philosophers)
	{
		philo = (t_philo *)malloc(sizeof(t_philo));
		if (philo == 0)
			return (1);
		initilize_philo(philo, i, param);
		temp->next_philo = philo;
		temp = temp->next_philo;
		i++;
	}
	temp->next_philo = param->philosopher;
	return (0);
}

int	set_input(t_param *param, char **argv, int argc)
{
	param->philosopher_has_died = 0;
	param->philos_that_ate_enough_times = 0;
	param->number_of_philosophers = ft_atoi(argv[1]);
	param->time_to_die = ft_atoi(argv[2]);
	param->time_to_eat = ft_atoi(argv[3]);
	param->time_to_sleep = ft_atoi(argv[4]);
	param->death_announced = 0;
	if (pthread_mutex_init(&(param->param_change), NULL))
		return (error("Mutex for param change could not initilize\n"));
	if (pthread_mutex_init(&(param->writing), NULL))
		return (error("Mutex for writing could not initilize\n"));
	if (argc == 6)
		param->times_each_philosopher_must_eat = ft_atoi(argv[5]);
	else
		param->times_each_philosopher_must_eat = -1;
	if (validate(param))
		return (error("Invalid Arguments\n"));
	if (list_the_philosophers(param))
		return (error("Problem with setting up philo list\n"));
	return (0);
}
