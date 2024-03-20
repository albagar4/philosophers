/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:27:07 by albagar4          #+#    #+#             */
/*   Updated: 2024/03/20 13:28:35 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_parsing(char **argv, t_param *param)
{
	param->nbr_of_philo = ft_atol(argv[1]);
	param->time_to_die = ft_atol(argv[2]);
	param->time_to_eat = ft_atol(argv[3]);
	param->time_to_sleep = ft_atol(argv[4]);
	if (argv[5])
		param->end_of_loop = ft_atol(argv[5]);
	else
		param->end_of_loop = -2;
}

int	check_correct_param(t_param param)
{
	int	checker;

	checker = 0;
	if (param.nbr_of_philo == -1 || param.time_to_die == -1
		|| param.time_to_eat == -1 || param.time_to_sleep == -1
		|| param.end_of_loop == -1)
		checker = -1;
	else if (param.nbr_of_philo > __INT32_MAX__
		|| param.time_to_die > __INT32_MAX__
		|| param.time_to_eat > __INT32_MAX__
		|| param.time_to_sleep > __INT32_MAX__
		|| param.end_of_loop > __INT32_MAX__)
		checker = -1;
	return (checker);
}
