/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:21:59 by albagar4          #+#    #+#             */
/*   Updated: 2024/03/29 17:43:56 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long	get_current_time(struct timeval ti, struct timeval tf)
{
	long	time;

	time = ((tf.tv_sec - ti.tv_sec) * 1000 + (tf.tv_usec - ti.tv_usec) / 1000);
	return (time);
}

void	calc_time(struct timeval ti, t_philo *philo)
{
	long			time;
	struct timeval	tf;

	gettimeofday(&tf, NULL);
	time = get_current_time(ti, tf);
	philo->last_eat = time;
}

void	ft_clock(struct timeval ti, t_param *table)
{
	long			clock;
	struct timeval	tf;

	gettimeofday(&tf, NULL);
	clock = get_current_time(ti, tf);
	table->time = clock;
}

int	check_time(long req, t_philo *philo)
{
	if (philo->last_eat > req && !philo->table->dead)
	{
		philo->table->dead = true;
		printf("%ld %i died\n", philo->table->time, philo->name);
		return (-1);
	}
	return (0);
}
