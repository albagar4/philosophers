/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:19:59 by albagar4          #+#    #+#             */
/*   Updated: 2024/04/12 21:09:07 by albagar4         ###   ########.fr       */
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
	ft_usleep(philos, philos->table->time_to_eat);
	philos->count--;
	pthread_mutex_unlock(&table->forks[lfork].mutex);
	pthread_mutex_unlock(&table->forks[rfork].mutex);
	return (NULL);
}

void	*ft_sleep(t_philo *philos)
{
	// pthread_mutex_lock(&philos->table->write);
	print_action(philos, 2);
	ft_usleep(philos, philos->table->time_to_sleep);
	// pthread_mutex_unlock(&philos->table->write);
	return (NULL);
}

void	*ft_think(t_philo *philos)
{
	// pthread_mutex_lock(&philos->table->write);
	print_action(philos, 1);
	// pthread_mutex_unlock(&philos->table->write);
	return (NULL);
}
