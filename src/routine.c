/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:19:59 by albagar4          #+#    #+#             */
/*   Updated: 2024/03/22 14:58:51 by albagar4         ###   ########.fr       */
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
	printf("%f %d has taken a fork\n", 1.1, philos->name);
	printf("%f %d is eating\n", 1.2, philos->name);
	usleep(table->time_to_eat);
	pthread_mutex_unlock(&table->forks[lfork].mutex);
	pthread_mutex_unlock(&table->forks[rfork].mutex);
	ft_sleep(philos, table);
	return (NULL);
}

void	*ft_sleep(t_philo *philos, t_param *table)
{
	printf("%f %d is sleeping\n", 1.3, philos->name);
	usleep(table->time_to_sleep);
	ft_think(philos, table);
	return (NULL);
}

void	*ft_think(t_philo *philos, t_param *table)
{
	static int	count = 0;

	printf("%f %d is thinking\n", 1.0, philos->name);
	if (count == 3)
		exit(0);
	count++;
	ft_eat(philos, table);
	return (NULL);
}
