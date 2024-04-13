/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:59:02 by albagar4          #+#    #+#             */
/*   Updated: 2024/04/13 14:08:46 by albagar4         ###   ########.fr       */
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
	bool			dead;
	long			start_time;
	struct s_philo	*philos;
	t_forks			*forks;
	pthread_mutex_t	mutex;
	pthread_mutex_t	write;
	pthread_mutex_t	mon_mutex;
}	t_param;

typedef struct s_philo
{
	int			name;
	int			left_fork;
	int			right_fork;
	long		last_eat;
	long		count;
	t_param		*table;
	pthread_t	thread;
	pthread_t	monitor;
}	t_philo;

// Utils
long	ft_atol(const char *str);
bool	read_bool(t_param *table);
void	ft_usleep(t_philo *philos, long time);
int		print_action(t_philo *philos, int nbr);
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
long	ft_clock(struct timeval ti);
int		check_time(long req, t_philo *philo);
long	get_simulation_time(t_param *table);
long	get_timestamp(void);
// Handlers
void	*ft_routine(void *data);
void	*start_monitor(t_philo *philo);
void	*ft_checker(void *philo);
// Routine
void	*ft_eat(t_philo *philos, t_param *table);
void	*ft_sleep(t_philo *philos);
void	*ft_think(t_philo *philos);
// Main
void	ft_destroy_forks(t_param *table);
void	ft_one_philo(t_param *table);
void	ft_create_threads(t_param *table);
