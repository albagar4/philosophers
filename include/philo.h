/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:59:02 by albagar4          #+#    #+#             */
/*   Updated: 2024/03/29 18:45:50 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/time.h>

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
	long			time;
	bool			dead;
	struct timeval	init_tmp;
	struct s_philo	*philos;
	pthread_t		monitor;
	t_forks			*forks;
	pthread_mutex_t	mutex;
}	t_param;

typedef struct s_philo
{
	int			name;
	int			left_fork;
	int			right_fork;
	long		last_eat;
	t_param		*table;
	pthread_t	thread;
}	t_philo;

// Utils
long	ft_atol(const char *str);
int		print_action(t_philo *philos, struct timeval tmp, int nbr);
// Parsing
void	ft_parsing(char **argv, t_param *param);
int		check_correct_param(t_param param);
// Preset
void	*set_mutex(pthread_mutex_t *locker);
void	*set_forks(t_param *table);
t_philo	*set_philos(t_param *table);
// Time check
long	get_current_time(struct timeval ti, struct timeval tf);
void	calc_time(struct timeval ti, t_philo *philo);
void	ft_clock(struct timeval ti, t_param *table);
int		check_time(long req, t_philo *philo);
// Handlers
void	*ft_routine(void *data);
void	*ft_checker(void *data);
// Routine
void	*ft_eat(t_philo *philos, t_param *table, struct timeval tmp);
void	*ft_sleep(t_philo *philos, struct timeval tmp);
void	*ft_think(t_philo *philos, struct timeval tmp);
// Main
void	ft_create_threads(t_param *table);
