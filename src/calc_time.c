/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:21:59 by albagar4          #+#    #+#             */
/*   Updated: 2024/03/26 16:45:04 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long	get_current_time(struct timeval ti, struct timeval tf)
{
	long	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	time = ((tf.tv_sec - ti.tv_sec) * 1000 + (tf.tv_usec - ti.tv_usec) / 1000);
	return (time);
}

void	set_time(struct timeval *ti, struct timeval *tf, t_philo *philo)
{
	long	time;

	gettimeofday(&tf);
	time = get_current_time(*ti, *tf);
	gettimeofday(&ti);
	time = philo->time;
}

int	check_time(long req, t_philo *philo)
{
	if (philo->time > req)
	{
		philo->dead = true;
		printf("%ld %i died\n", philo->time, philo->name);
		return (-1);
	}
	return (0);
}
