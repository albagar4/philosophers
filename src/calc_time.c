/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:21:59 by albagar4          #+#    #+#             */
/*   Updated: 2024/04/01 16:10:11 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long	get_timestamp(void)
{
	struct timeval	timestruct;

	gettimeofday(&timestruct, NULL);
	return ((timestruct.tv_sec * 1000) + (timestruct.tv_usec / 1000));
}

long	get_simulation_time(t_param *table)
{
	return (get_timestamp() - table->start_time);
}
