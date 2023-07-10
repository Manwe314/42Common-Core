/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:11:36 by lkukhale          #+#    #+#             */
/*   Updated: 2023/03/08 16:55:14 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>

typedef struct s_parameters
{
	int						time_to_die;
	int						number_of_philosophers;
	int						time_to_eat;
	int						time_to_sleep;
	int						times_each_philosopher_must_eat;
	int						philos_that_ate_enough_times;
	int						philosopher_has_died;
	int						death_announced;
	long					sim_start;
	pthread_mutex_t			param_change;
	pthread_mutex_t			writing;
	struct s_philosopher	*philosopher;
}	t_param;

typedef struct s_philosopher
{
	int						id;
	int						amount_of_times_has_eaten;
	int						time_to_die;
	long					last_time_eaten;
	int						offset;
	struct s_parameters		*param;
	struct s_philosopher	*next_philo;
	pthread_mutex_t			right_fork;
	pthread_t				thread_id;
}	t_philo;

void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(const char *str);
long	get_time(void);
int		error(char *msg);
int		get_offset_interval(t_param *param);
int		get_offset(int id, t_param *param);
int		set_input(t_param *param, char **argv, int argc);
int		check_sim(t_philo *philo);
int		run_simulation(t_param *param);
void	*philosopher(void *par);
void	try_to_eat(t_philo *philo);
void	snooz(long duration, t_philo *philo);
int		check_death(t_philo *philo);
void	act(t_param *param, int id, char action, t_philo *philo);

#endif
