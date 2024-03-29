/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:02:20 by albagar4          #+#    #+#             */
/*   Updated: 2024/03/29 18:42:56 by albagar4         ###   ########.fr       */
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

void	*ft_checker(void *data)
{
	t_param	*table;
	t_philo	*philos;
	int		i;

	table = (t_param *)data;
	philos = table->philos;
	i = 0;
	while (table->dead == 0)
	{
		if (i == table->nbr_of_philo)
			i = 0;
		ft_clock(table->init_tmp, table);
		if (table->time - philos[i].last_eat > table->time_to_die)
		{
			table->dead = 1;
			printf("%ld %i died\n", table->time, philos[i].name);
			break ;
		}
		i++;
	}
	return (NULL);
}
