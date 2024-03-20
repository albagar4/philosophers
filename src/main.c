/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:58:03 by albagar4          #+#    #+#             */
/*   Updated: 2024/03/20 18:56:40 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*imprimo()
{
	printf("lolaso\n");
	//usleep(30);
	printf("serie o paralelo?\n");
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
		philos[i].name = i;
		if (i == data->nbr_of_philo)
			philos[i].left_fork = 1;
		else
			philos[i].left_fork = i + 1;
		philos[i].right_fork = i;
		philos[i].last_eat = 0;
		philos[i].last_sleep = 0;
		philos[i].last_think = 0;
		philos[i].data = data;
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
		if (pthread_create(&philos[i].thread, NULL, &imprimo, NULL) != 0)
			return ;
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
