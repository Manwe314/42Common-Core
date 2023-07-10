/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_one.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 21:24:10 by lkukhale          #+#    #+#             */
/*   Updated: 2023/03/08 16:59:08 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (now.tv_sec * 1000 + now.tv_usec / 1000);
}

int	error(char *msg)
{
	ft_putstr_fd(msg, 2);
	return (1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	ft_atoi(const char *str)
{
	int	i;
	int	s;
	int	nbr;

	i = 0;
	s = 1;
	nbr = 0;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == 32) && str[i] != '\0')
	{
		i++;
	}
	if (str[i] == '-')
	{
		s *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57 && str[i] != '\0')
	{
		nbr = nbr * 10 + (str[i] - 48);
		i++;
	}
	nbr = nbr * s;
	return (nbr);
}

int	get_offset_interval(t_param *param)
{
	int	interval;

	interval = (param->time_to_die - \
	(param->time_to_eat + param->time_to_sleep)) \
	/ (param->number_of_philosophers + 1);
	if (interval <= 0)
		return (1);
	return (interval);
}
