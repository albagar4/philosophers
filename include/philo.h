/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:59:02 by albagar4          #+#    #+#             */
/*   Updated: 2024/03/20 15:11:54 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>

typedef struct s_param
{
	long	nbr_of_philo;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	end_of_loop;
}	t_param;

// Utils
long	ft_atol(const char *str);
// Init philo
void	ft_parsing(char **argv, t_param *param);
int		check_correct_param(t_param param);
