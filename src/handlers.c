/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:02:20 by albagar4          #+#    #+#             */
/*   Updated: 2024/03/30 21:23:38 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*ft_routine(void *data)
{
	t_philo			*philos;
	struct timeval	ti;

	philos = (t_philo *)data;
	gettimeofday(&ti, NULL);
	philos->table->init_tmp = ti;
	while (philos->table->dead == 0)
	{
		ft_think(philos, ti);
		ft_eat(philos, philos->table, ti);
		ft_sleep(philos, ti);
	}
	return (NULL);
}

void	*start_monitor(t_param *data)
{
	pthread_t	*monitor;
	int			i;

	i = 0;
	monitor = (pthread_t)malloc(sizeof(pthread_t) * data->nbr_of_philo);
	if (!monitor)
		return (NULL);
	data->monitor = monitor;
	while (i < data->nbr_of_philo)
	{
		if (pthread_create(&monitor[i], NULL, &ft_checker,
				(void *) &data) != 0)
			return (NULL);
		i++;
	}
	i = 0;
	while (i < data->nbr_of_philo)
	{
		pthread_detach(monitor[i]);
		i++;
	}
	return (NULL);
}

void	*ft_checker(void *data)
{
	t_param	*table;
	t_philo	*philos;
	int		i;

	table = (t_param *)data;
	philos = table->philos;
	while (table->dead == 0)
	{
		ft_clock(table->init_tmp, table);
		if (table->time - philos[i].last_eat > table->time_to_die)
		{
			table->dead = 1;
			printf("%ld %i died\n", table->time, philos[i].name);
			break ;
		}
	}
	return (NULL);
}
