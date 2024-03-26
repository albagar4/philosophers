/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:59:02 by albagar4          #+#    #+#             */
/*   Updated: 2024/03/26 16:33:09 by albagar4         ###   ########.fr       */
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

typedef struct s_param
{
	long			nbr_of_philo;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			end_of_loop;
	struct s_philo	*philos;
	pthread_t		*monitors;
	t_forks			*forks;
	pthread_mutex_t	mutex;
}	t_param;

typedef struct s_philo
{
	int			name;
	int			left_fork;
	int			right_fork;
	long		last_eat;
	long		time;
	bool		dead;
	t_param		*table;
	pthread_t	thread;
}	t_philo;

// Utils
long	ft_atol(const char *str);
// Parsing
void	ft_parsing(char **argv, t_param *param);
int		check_correct_param(t_param param);
// Preset
void	*set_mutex(pthread_mutex_t *locker);
void	*set_forks(t_param *table);
t_philo	*set_philos(t_param *table);
// Routine
void	*ft_eat(t_philo *philos, t_param *table);
void	*ft_sleep(t_philo *philos, t_param *table);
void	*ft_think(t_philo *philos);
// Main
void	ft_create_threads(t_param *table);
void	*ft_routine();
