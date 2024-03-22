/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:58:03 by albagar4          #+#    #+#             */
/*   Updated: 2024/03/22 13:26:08 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*imprimo()
{
	printf("lolaso\n");
	printf("serie o paralelo?\n");
	return (NULL);
}

void	ft_create_threads(t_param *table)
{
	int		i;

	i = 0;
	set_forks(table);
	set_philos(table);
	while (i < table->nbr_of_philo)
	{
		if (pthread_create(&table->philos[i].thread,
				NULL, &imprimo, &table->philos[i]) != 0)
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
	ft_create_threads(&param);
	return (0);
}
