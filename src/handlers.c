/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:02:20 by albagar4          #+#    #+#             */
/*   Updated: 2024/04/13 14:28:00 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*ft_routine(void *data)
{
	t_philo			*philos;

	philos = (t_philo *)data;
	pthread_mutex_lock(&philos->table->mon_mutex);
	philos->last_eat = get_timestamp();
	pthread_mutex_unlock(&philos->table->mon_mutex);
	start_monitor(philos);
	// if (philos->name == philos->table->nbr_of_philo)
	// {
	// 	pthread_mutex_lock(&philos->table->mutex);
	// 	philos->table->start_time = get_timestamp();
	// 	pthread_mutex_unlock(&philos->table->mutex);
	// }
	if (philos->name % 2)
		ft_usleep(philos, 1);
	while (read_bool(philos->table) == 0 && philos->count != 0)
	{
		ft_think(philos);
		ft_eat(philos, philos->table);
		ft_sleep(philos);
	}
	return (NULL);
}

void	*start_monitor(t_philo *philo)
{
	pthread_t	monitor;

	monitor = (pthread_t)malloc(sizeof(pthread_t));
	if (!monitor)
		return (NULL);
	philo->monitor = monitor;
	if (pthread_create(&monitor, NULL, &ft_checker,
			(void *) philo) != 0)
		return (NULL);
	pthread_detach(monitor);
	return (NULL);
}

void	*ft_checker(void *philo)
{
	t_param	*table;
	t_philo	*philos;
	long	clock;

	philos = (t_philo *)philo;
	table = philos->table;
	// pthread_mutex_lock(&philos->table->mutex);
	// philos->table->start_time = get_timestamp();
	// pthread_mutex_unlock(&philos->table->mutex);
	while (read_bool(table) == 0)
	{
		clock = get_timestamp();
		pthread_mutex_lock(&table->mon_mutex);
		if ((clock - 5) - philos->last_eat > table->time_to_die)
		{
			table->dead = 1;
			printf("%ld %i died\n", get_simulation_time(philos->table),
				philos->name);
			break ;
		}
		pthread_mutex_unlock(&table->mon_mutex);
	}
	return (NULL);
}
