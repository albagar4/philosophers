/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:19:59 by albagar4          #+#    #+#             */
/*   Updated: 2024/03/22 23:07:34 by albagar4         ###   ########.fr       */
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
	return (NULL);
}

void	*ft_sleep(t_philo *philos, t_param *table)
{
	printf("%f %d is sleeping\n", 1.3, philos->name);
	usleep(table->time_to_sleep);
	return (NULL);
}

void	*ft_think(t_philo *philos, t_param *table)
{
	static int	count = 0;

	printf("hola\n");
	pthread_mutex_lock(&table->mutex);
	printf("%i %d is thinking\n", 1, philos->name);
	pthread_mutex_unlock(&table->mutex);
	printf("adios\n");
	if (count == 3)
		exit(0);
	count++;
	return (NULL);
}
