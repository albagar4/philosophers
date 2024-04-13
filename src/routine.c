/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:19:59 by albagar4          #+#    #+#             */
/*   Updated: 2024/04/13 15:46:50 by albagar4         ###   ########.fr       */
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
	pthread_mutex_lock(&table->mon_mutex);
	philos->last_eat = get_timestamp();
	pthread_mutex_unlock(&table->mon_mutex);
	pthread_mutex_lock(&table->write);
	print_action(philos, 3);
	pthread_mutex_unlock(&table->write);
	pthread_mutex_lock(&philos->table->mon_mutex);
	philos->count--;
	pthread_mutex_unlock(&philos->table->mon_mutex);
	ft_usleep(philos, philos->table->time_to_eat);
	pthread_mutex_unlock(&table->forks[lfork].mutex);
	pthread_mutex_unlock(&table->forks[rfork].mutex);
	return (NULL);
}

void	*ft_sleep(t_philo *philos)
{
	pthread_mutex_lock(&philos->table->write);
	print_action(philos, 2);
	pthread_mutex_unlock(&philos->table->write);
	ft_usleep(philos, philos->table->time_to_sleep);
	return (NULL);
}

void	*ft_think(t_philo *philos)
{
	pthread_mutex_lock(&philos->table->write);
	print_action(philos, 1);
	pthread_mutex_unlock(&philos->table->write);
	return (NULL);
}
