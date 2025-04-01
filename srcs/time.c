/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:54:25 by kearmand          #+#    #+#             */
/*   Updated: 2025/04/01 16:37:28 by kearmand         ###   ########.fr       */
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

long	get_runtime(long start)
{
	struct timeval	now;
	long			time;

	gettimeofday(&now, NULL);
	time = now.tv_sec * 1000000 + now.tv_usec - start;
	return (time);
}


/***
 * @brief precise sleep function
 * 
 * On va peut etre rajouter un sim_is_running
 * Use usleep to wait for the time
 * Use a spinlock to wait the last second
 * @param start the start of the event
 * @param time the time to wait (in microsecond)
 */
void	precise_sleep(long start, long time)
{
	long	now;
	long	elapsed;

	now = ft_get_time();
	elapsed = now - start;
	while (time - elapsed - 1000000 > 0)
	{
		usleep(1000000);
		now = ft_get_time();
		elapsed = now - start;
	}
	while (time - elapsed > 100)
	{
		usleep((int)(time - elapsed)/2);
		now = ft_get_time();
		elapsed = now - start;
	}
	while (time - elapsed > 0)
	{
		now = ft_get_time();
		elapsed = now - start;
	}
}

long	ft_get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000000 + time.tv_usec);
}
