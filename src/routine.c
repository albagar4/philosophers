/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:19:59 by albagar4          #+#    #+#             */
/*   Updated: 2024/03/26 17:19:41 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*ft_eat(t_philo *philos, t_param *table)
{
	int	lfork;
	int	rfork;

	lfork = philos->left_fork;
	rfork = philos->right_fork;
	pthread_mutex_lock(&table->forks[lfork].mutex);
	pthread_mutex_lock(&table->forks[rfork].mutex);
	if (check_time(table->time_to_eat, philos) == -1)
		return (NULL);
	// printf("%ld %d has taken a fork\n", philos->time, philos->name);
	// printf("%ld %d is eating\n", philos->time, philos->name);
	usleep(table->time_to_eat);
	pthread_mutex_unlock(&table->forks[lfork].mutex);
	pthread_mutex_unlock(&table->forks[rfork].mutex);
	return (NULL);
}

void	*ft_sleep(t_philo *philos, t_param *table)
{
	if (check_time(table->time_to_eat, philos) == -1)
		return (NULL);
	// printf("%ld %d is sleeping\n", philos->time, philos->name);
	usleep(table->time_to_sleep);
	return (NULL);
}

void	*ft_think(t_philo *philos)
{
	pthread_mutex_t	mutex;

	set_mutex(&mutex);
	pthread_mutex_lock(&mutex);
	if (check_time(philos->table->time_to_eat, philos) == -1)
		return (NULL);
	// printf("%ld %d is thinking\n", philos->time, philos->name);
	pthread_mutex_unlock(&mutex);
	return (NULL);
}
