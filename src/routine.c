/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:19:59 by albagar4          #+#    #+#             */
/*   Updated: 2024/03/27 18:20:21 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*ft_eat(t_philo *philos, t_param *table, struct timeval tmp)
{
	int	lfork;
	int	rfork;

	lfork = philos->left_fork;
	rfork = philos->right_fork;
	pthread_mutex_lock(&table->forks[lfork].mutex);
	pthread_mutex_lock(&table->forks[rfork].mutex);
	if (check_time(table->time_to_die, philos) == -1)
		return (NULL);
	print_action(philos, tmp, 3);
	usleep(table->time_to_eat * 1000);
	pthread_mutex_unlock(&table->forks[lfork].mutex);
	pthread_mutex_unlock(&table->forks[rfork].mutex);
	return (NULL);
}

void	*ft_sleep(t_philo *philos, struct timeval tmp)
{
	if (check_time(philos->table->time_to_die, philos) == -1)
		return (NULL);
	print_action(philos, tmp, 2);
	usleep(philos->table->time_to_sleep * 1000);
	return (NULL);
}

void	*ft_think(t_philo *philos, struct timeval tmp)
{
	pthread_mutex_t	mutex;

	set_mutex(&mutex);
	pthread_mutex_lock(&mutex);
	if (check_time(philos->table->time_to_die, philos) == -1)
		return (NULL);
	print_action(philos, tmp, 1);
	pthread_mutex_unlock(&mutex);
	return (NULL);
}
