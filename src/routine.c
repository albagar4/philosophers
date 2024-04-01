/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:19:59 by albagar4          #+#    #+#             */
/*   Updated: 2024/04/01 17:20:47 by albagar4         ###   ########.fr       */
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
	philos->last_eat = get_timestamp();
	print_action(philos, 3);
	usleep(table->time_to_eat * 1000);
	philos->count--;
	pthread_mutex_unlock(&table->forks[lfork].mutex);
	pthread_mutex_unlock(&table->forks[rfork].mutex);
	return (NULL);
}

void	*ft_sleep(t_philo *philos)
{
	pthread_mutex_t	mutex;

	set_mutex(&mutex);
	pthread_mutex_lock(&mutex);
	print_action(philos, 2);
	usleep(philos->table->time_to_sleep * 1000);
	pthread_mutex_unlock(&mutex);
	return (NULL);
}

void	*ft_think(t_philo *philos)
{
	pthread_mutex_t	mutex;

	// philos->table->mutex = mutex;
	set_mutex(&mutex);
	pthread_mutex_lock(&mutex);
	print_action(philos, 1);
	pthread_mutex_unlock(&mutex);
	// pthread_mutex_destroy(&mutex);
	return (NULL);
}
