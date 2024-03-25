/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:58:03 by albagar4          #+#    #+#             */
/*   Updated: 2024/03/25 18:12:43 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*ft_routine(void *data)
{
	t_philo	*philos;

	philos = (t_philo *)data;
	printf("su nombre es philo->%d\n", philos->name);
	while (1)
	{
		ft_think(philos);
		// ft_eat(table->philos, table);
		// ft_sleep(table->philos, table);
	}
	return (NULL);
}

void	ft_create_threads(t_param *table)
{
	int				i;

	i = 0;
	// set_mutex(table);
	set_forks(table);
	set_philos(table);
	while (i < table->nbr_of_philo)
	{
		if (pthread_create(&table->philos[i].thread,
				NULL, &ft_routine, (void *) &table->philos[i]) != 0)
			return ;
		i++;
	}
	i = 0;
	while (i < table->nbr_of_philo)
	{
		if (pthread_join(table->philos[i].thread, NULL) != 0)
			return ;
		i++;
	}
	return ;
}

int	main(int argc, char *argv[])
{
	t_param	param;

	if (argc != 5)
		if (argc != 6)
			return (printf("Invalid number of parameters\n"), 0);
	ft_parsing(argv, &param);
	if (check_correct_param(param) == -1)
		return (printf("Invalid parameters\n"), 0);
	ft_create_threads(&param);
	return (0);
}
