/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:58:03 by albagar4          #+#    #+#             */
/*   Updated: 2024/04/13 14:19:43 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_one_philo(t_param *table)
{
	printf("0 1 is thinking\n");
	usleep(table->time_to_die);
	printf("%ld 1 has died\n", table->time_to_die + 1);
}

void	ft_destroy_forks(t_param *table)
{
	int	count;

	count = 0;
	while (count < table->nbr_of_philo)
	{
		pthread_mutex_destroy(&table->forks[count].mutex);
		count++;
	}
	free(&table->forks);
}

void	ft_create_threads(t_param *table)
{
	t_philo		*philos;
	int			i;

	i = 0;
	set_forks(table);
	philos = set_philos(table);
	table->start_time = get_timestamp();
	while (i < table->nbr_of_philo)
	{
		if (pthread_create(&philos[i].thread,
				NULL, &ft_routine, (void *) &philos[i]) != 0)
			return ;
		i++;
	}
	i = 0;
	while (i < table->nbr_of_philo)
	{
		if (pthread_join(philos[i].thread, NULL) != 0)
			return ;
		i++;
	}
	pthread_mutex_destroy(&table->mutex);
	pthread_mutex_destroy(&table->write);
	pthread_mutex_destroy(&table->mon_mutex);
	ft_destroy_forks(table);
}

int	main(int argc, char *argv[])
{
	t_param	param;

	if (argc != 5 && argc != 6)
		return (printf("Invalid number of parameters\n"), 0);
	ft_parsing(argv, &param);
	if (check_correct_param(param) == -1)
		return (printf("Invalid parameters\n"), 0);
	if (param.nbr_of_philo == 1)
		ft_one_philo(&param);
	else
		ft_create_threads(&param);
	return (0);
}
