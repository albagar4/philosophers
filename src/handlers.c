/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:02:20 by albagar4          #+#    #+#             */
/*   Updated: 2024/04/01 16:56:38 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*ft_routine(void *data)
{
	t_philo			*philos;

	philos = (t_philo *)data;
	philos->table->start_time = get_timestamp();
	philos->last_eat = get_timestamp();
	start_monitor(philos);
	if (philos->name % 2)
		usleep(1 * 1000);
	while (philos->table->dead == 0 && philos->count != 0)
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
	while (table->dead == 0)
	{
		clock = get_timestamp();
		if (clock - philos->last_eat > table->time_to_die)
		{
			table->dead = 1;
			printf("%ld %i died\n", get_simulation_time(philos->table),
				philos->name);
			break ;
		}
	}
	return (NULL);
}
