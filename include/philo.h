/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:59:02 by albagar4          #+#    #+#             */
/*   Updated: 2024/03/20 18:48:14 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_param
{
	long	nbr_of_philo;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	int		death;
	long	end_of_loop;
}	t_param;

typedef struct s_philo
{
	int			name;
	int			left_fork;
	int			right_fork;
	long		last_eat;
	long		last_sleep;
	long		last_think;
	t_param		*data;
	pthread_t	thread;
}	t_philo;

// Utils
long	ft_atol(const char *str);
// Parsing
void	ft_parsing(char **argv, t_param *param);
int		check_correct_param(t_param param);
