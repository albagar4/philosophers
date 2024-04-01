/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:15:15 by albagar4          #+#    #+#             */
/*   Updated: 2024/04/01 17:05:25 by albagar4         ###   ########.fr       */
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

int	print_action(t_philo *philos, int nbr)
{
	long	clock;

	if (philos->table->dead == 0)
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
	return (0);
}
