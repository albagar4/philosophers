/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:02:20 by albagar4          #+#    #+#             */
/*   Updated: 2024/04/13 15:24:36 by albagar4         ###   ########.fr       */
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
	if (philos->name % 2)
		ft_usleep(philos, 1);
	while (read_bool(philos->table) == 0 && philos->count != 0)
	{
		if (philos->count != 0)
			ft_think(philos);
		if (philos->count != 0)
			ft_eat(philos, philos->table);
		if (philos->count != 0)
			ft_sleep(philos);
	}
	return (NULL);
}

void	*start_monitor(t_philo *philo)
{
	if (pthread_create(&philo->monitor, NULL, &ft_checker,
			(void *) philo) != 0)
		return (NULL);
	pthread_detach(philo->monitor);
	return (NULL);
}

void	*ft_checker(void *philo)
{
	t_philo	*philos;
	long	clock;

	philos = (t_philo *)philo;
	while (read_bool(philos->table) == 0)
	{
		clock = get_timestamp();
		pthread_mutex_lock(&philos->table->mon_mutex);
		if (philos->count == 0)
		{
			pthread_mutex_unlock(&philos->table->mon_mutex);
			break ;
		}
		else if ((clock - 9) - philos->last_eat > philos->table->time_to_die)
		{
			philos->table->dead = 1;
			printf("%ld %i died\n", get_simulation_time(philos->table),
				philos->name);
			pthread_mutex_unlock(&philos->table->mon_mutex);
			break ;
		}
		pthread_mutex_unlock(&philos->table->mon_mutex);
	}
	return (NULL);
}
