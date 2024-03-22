/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:58:03 by albagar4          #+#    #+#             */
/*   Updated: 2024/03/21 13:57:01 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*imprimo(void * philos[i])
{
	pthread_mutex_lock(philos->data->fork);
	printf("lolaso\n");
	//usleep(30);
	printf("serie o paralelo?\n");
	pthread_mutex_unlock(philos->data->fork);
	return (NULL);
}

void	set_philosophers(t_philo *philos, t_param *data)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (j < data->nbr_of_philo)
	{
		philos[j].name = i;
		if (j == data->nbr_of_philo)
			philos[j].left_fork = 1;
		else
			philos[j].left_fork = i + 1;
		philos[j].right_fork = i;
		philos[j].last_eat = 0;
		philos[j].last_sleep = 0;
		philos[j].last_think = 0;
		philos[j].data = data;
		i++;
		j++;
	}
}

void	ft_create_philo(t_param *data)
{
	t_philo	*philos;
	int		i;

	i = 0;
	philos = ((t_philo *)malloc(sizeof(t_philo) * data->nbr_of_philo));
	if (!philos)
		return ;
	set_philosophers(philos, data);
	while (i < data->nbr_of_philo)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		if (pthread_create(&philos[i].thread, NULL, &imprimo, &philos[i]) != 0)
			return ;
		i++;
	}
	free_threads_and_mutex(philos);
}

void	free_threads_and_mutex(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->data->nbr_of_philo)
	{
		if (pthread_join(philos[i].thread, NULL) != 0)
			return ;
		pthread_mutex_destroy(&philos->data->forks[i]);
		i++;
	}
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
	ft_create_philo(&param);
	return (0);
}
