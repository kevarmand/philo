/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:54:25 by kearmand          #+#    #+#             */
/*   Updated: 2025/03/19 13:08:55 by kearmand         ###   ########.fr       */
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



void	print_timer(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	printf("time : %ld sec\n", now.tv_sec);
	printf("time : %ld us\n\n", now.tv_usec);
}

/***
 * @brief return difference between two timeval in microsecond
 * 
 * @param start the event start
 * @param end the event end
 * @return long - the time in microsecond
 */
long	get_time_diff(struct timeval *start, struct timeval *end)
{
	long	time;

	time = (long)(end->tv_sec - start->tv_sec) * 1000000;
	time += (end->tv_usec - start->tv_usec);
	return (time);
}

/***
 * @brief precise sleep function
 * 
 * Use usleep to wait for the time
 * Use a spinlock to wait the last second
 * @param start the start of the event
 * @param time the time to wait (in microsecond)
 */
void	precise_sleep(struct timeval *start, long time)
{
	struct timeval	now;
	long			elapsed;

	gettimeofday(&now, NULL);
	elapsed = get_time_diff(start, &now);
	while (time - elapsed - 1000000 > 0)
	{
		usleep(1000000);
		gettimeofday(&now, NULL);
		elapsed = get_time_diff(start, &now);
	}
	while (time - elapsed > 1000)
	{
		usleep((int)(time - elapsed)/2);
		gettimeofday(&now, NULL);
		elapsed = get_time_diff(start, &now);
	}
	while (time - elapsed > 0)
	{
		gettimeofday(&now, NULL);
		elapsed = get_time_diff(start, &now);
	}
}

void	time_copy(struct timeval *dst, struct timeval *src)
{
	dst->tv_sec = src->tv_sec;
	dst->tv_usec = src->tv_usec;
}

long time_to_long(struct timeval *time)
{
	long	ret;

	ret = time->tv_sec * 1000000;
	ret += time->tv_usec;
	return (ret);
}