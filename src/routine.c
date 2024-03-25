/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:19:59 by albagar4          #+#    #+#             */
/*   Updated: 2024/03/25 18:37:45 by albagar4         ###   ########.fr       */
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
	printf("%d has taken a fork\n", philos->name);
	printf("%d is eating\n", philos->name);
	usleep(table->time_to_eat);
	pthread_mutex_unlock(&table->forks[lfork].mutex);
	pthread_mutex_unlock(&table->forks[rfork].mutex);
	return (NULL);
}

void	*ft_sleep(t_philo *philos, t_param *table)
{
	printf("%d is sleeping\n", philos->name);
	usleep(table->time_to_sleep);
	return (NULL);
}

void	*ft_think(t_philo *philos)
{
	static int		count = 0;
	pthread_mutex_t	mutex;

	set_mutex(&mutex);
	pthread_mutex_lock(&mutex);
	printf("%d is thinking\n", philos->name);
	pthread_mutex_unlock(&mutex);
	if (count == 300)
		exit(0);
	count++;
	return (NULL);
}
