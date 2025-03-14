/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:54:25 by kearmand          #+#    #+#             */
/*   Updated: 2025/03/14 11:39:01 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/***
 * @brief return the time in microsecond
 * 
 * @param start the start of the simulation
 * @return int the time in microsecond
 * 
 */

int	get_runtime(struct timeval *start)
{
	struct timeval	now;
	int				time;

	gettimeofday(&now, NULL);
	time = (now.tv_sec - start->tv_sec) * 1000000;
	time += (now.tv_usec - start->tv_usec);
	return (time);
}

void	wait_for_start(t_data *data)
{
	struct timeval	now;
	int				time;

	gettimeofday(&now, NULL);
	time = get_runtime(&data->start);
	usleep( -time);
}

void	print_timer(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	printf("time : %ld sec\n", now.tv_sec);
	printf("time : %ld us\n\n", now.tv_usec);
}