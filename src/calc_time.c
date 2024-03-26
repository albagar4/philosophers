/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:21:59 by albagar4          #+#    #+#             */
/*   Updated: 2024/03/26 17:53:23 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

double	get_current_time(struct timeval ti, struct timeval tf)
{
	double	time;

	//if (gettimeofday(&ti, NULL) == -1)
		//write(2, "gettimeofday() error\n", 22);
	time = ((tf.tv_sec - ti.tv_sec) * 1000 + (tf.tv_usec - ti.tv_usec) / 1000);
	printf("%ld\n", tf.tv_sec);
	printf("%ld\n", ti.tv_sec);
	printf("%d\n", tf.tv_usec);
	printf("%d\n", ti.tv_usec);
	// printf("time es %f\n", time);
	return (time);
}

void	set_time(struct timeval ti, t_philo *philo)
{
	double			time;
	struct timeval	tf;

	gettimeofday(&tf, NULL);
	time = get_current_time(ti, tf);
	// gettimeofday(&ti, NULL);
	philo->time = time;
	// printf("philo->time es %f\n", philo->time);
}

int	check_time(long req, t_philo *philo)
{
	if (philo->time > req)
	{
		philo->dead = true;
		printf("%f %i died\n", philo->time, philo->name);
		return (-1);
	}
	return (0);
}
