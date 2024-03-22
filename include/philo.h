/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:59:02 by albagar4          #+#    #+#             */
/*   Updated: 2024/03/22 16:47:51 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>

typedef struct s_forks
{
	int				nbr;
	pthread_mutex_t	mutex;
}	t_forks;

typedef struct s_philo
{
	int			name;
	int			left_fork;
	int			right_fork;
	long		last_eat;
	bool		dead;
	pthread_t	thread;
}	t_philo;

typedef struct s_param
{
	long			nbr_of_philo;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			end_of_loop;
	t_philo			*philos;
	pthread_t		*monitors;
	t_forks			*forks;
	pthread_mutex_t	mutex;
}	t_param;

// Utils
long	ft_atol(const char *str);
// Parsing
void	ft_parsing(char **argv, t_param *param);
int		check_correct_param(t_param param);
// Preset
void	*set_mutex(t_param *table);
void	*set_forks(t_param *table);
void	*set_philos(t_param *table);
// Routine
void	*ft_eat(t_philo *philos, t_param *table);
void	*ft_sleep(t_philo *philos, t_param *table);
void	*ft_think(t_philo *philos, t_param *table);
// Main
void	ft_create_threads(t_param *table);
void	*ft_routine();
