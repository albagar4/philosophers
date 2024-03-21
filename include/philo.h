/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:59:02 by albagar4          #+#    #+#             */
/*   Updated: 2024/03/21 13:28:55 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_param
{
	long			nbr_of_philo;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				death;
	long			end_of_loop;
	pthread_mutex_t	*forks;
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
// Main
void	free_threads_and_mutex(t_philo *philos);
void	ft_create_philo(t_param *data);
void	set_philosophers(t_philo *philos, t_param *data);
void	*imprimo();
