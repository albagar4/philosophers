/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:15:15 by albagar4          #+#    #+#             */
/*   Updated: 2024/04/13 14:49:22 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long	ft_atol(const char *str)
{
	int		i;
	long	result;

	i = 0;
	result = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			return (-1);
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			result = (result * 10) + (str[i] - '0');
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		i++;
	}
	return (result);
}

bool	read_bool(t_param *table)
{
	bool	dead;

	pthread_mutex_lock(&table->mon_mutex);
	dead = table->dead;
	pthread_mutex_unlock(&table->mon_mutex);
	return (dead);
}

void	ft_usleep(t_philo *philos, long time)
{
	(void)philos;
	usleep(time * 1000);
}

int	print_action(t_philo *philos, int nbr)
{
	long	clock;

	// pthread_mutex_lock(&philos->table->write);
	if (read_bool(philos->table) == 0)
	{
		clock = get_simulation_time(philos->table);
		if (nbr == 1)
			printf("%ld %d is thinking\n", clock, philos->name);
		else if (nbr == 2)
			printf("%ld %d is sleeping\n", clock, philos->name);
		else if (nbr == 3)
		{
			printf("%ld %d has taken a fork\n", clock, philos->name);
			printf("%ld %d is eating\n", clock, philos->name);
		}
	}
	// pthread_mutex_unlock(&philos->table->write);
	return (0);
}
