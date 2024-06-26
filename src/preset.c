/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 21:11:19 by albagar4          #+#    #+#             */
/*   Updated: 2024/04/13 14:14:58 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*set_forks(t_param *table)
{
	t_forks	*fork_list;
	int		i;

	i = 0;
	fork_list = malloc(sizeof(t_forks) * table->nbr_of_philo);
	if (!fork_list)
		return (NULL);
	pthread_mutex_init(&table->mutex, NULL);
	pthread_mutex_init(&table->write, NULL);
	pthread_mutex_init(&table->mon_mutex, NULL);
	while (i < table->nbr_of_philo)
	{
		fork_list[i].nbr = i;
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
		philos[i].count = table->end_of_loop;
		philos[i].table = table;
		i++;
	}
	table->philos = philos;
	return (philos);
}
