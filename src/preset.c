/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:17:16 by albagar4          #+#    #+#             */
/*   Updated: 2024/03/25 18:25:49 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*set_mutex(pthread_mutex_t *locker)
{
	locker = malloc(sizeof(pthread_mutex_t) * 1);
	if (!locker)
		return (NULL);
	pthread_mutex_init(locker, NULL);
	return (NULL);
}

void	*set_forks(t_param *table)
{
	t_forks	*fork_list;
	int		i;

	i = 0;
	fork_list = malloc(sizeof(t_forks) * table->nbr_of_philo);
	if (!fork_list)
		return (NULL);
	while (i < table->nbr_of_philo)
	{
		fork_list[i].nbr = i + 1;
		pthread_mutex_init(&fork_list[i].mutex, NULL);
		i++;
	}
	table->forks = fork_list;
	return (NULL);
}

t_philo	*set_philos(t_param *table)
{
	t_philo	*philos;
	int		i;

	i = 0;
	philos = malloc(sizeof(t_philo) * table->nbr_of_philo);
	if (!philos)
		return (NULL);
	while (i < table->nbr_of_philo)
	{
		philos[i].name = i + 1;
		if (i == table->nbr_of_philo - 1)
			philos[i].left_fork = table->forks[0].nbr;
		else
			philos[i].left_fork = table->forks[i + 1].nbr;
		philos[i].right_fork = table->forks[i].nbr;
		philos[i].last_eat = 0;
		philos[i].dead = false;
		philos[i].table = table;
		i++;
	}
	return (philos);
}
