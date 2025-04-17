/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watchdog.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:22:51 by kearmand          #+#    #+#             */
/*   Updated: 2025/04/03 13:39:45 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	wait_for_begin(long start);
static void	init_str(char *str);
static void	init_watchdog(t_data *data);

/***
 * @brief watchdog thread
 * 
 * Check the state of the simulation
 * Print the events
 * 
 * @param *data the data structure
 */
void	*watchdog(void *data1)
{
	t_data	*data;
	long	min;
	char	str[100];
	int		status;

	data = (t_data *)data1;
	init_str(str);
	init_watchdog(data);
	wait_for_begin(data->start);
	status = 0;
	while (!status)
	{
		update_msg(data);
		min = get_latest(data);
		if (min == -1)
		{
			status = check_apetite(data);
			usleep(100);
		}
		else
			status = display_event(data, str, min);
	}
	end_simulation(data, status);
	return (NULL);
}

static void	init_watchdog(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		data->shared.lst_msg[i] = -1;
		data->shared.lst_last_meal[i] = 0;
		pthread_mutex_lock(&data->shared.sim_is_running[i].mutex);
		data->shared.sim_is_running[i].state = 1;
		pthread_mutex_unlock(&data->shared.sim_is_running[i].mutex);
		i++;
	}
}

static void	wait_for_begin(long start)
{
	long	now;
	long	time;

	now = ft_get_time();
	time = start - now;
	precise_sleep(now, time);
}

static void	init_str(char *str)
{
	int	i;

	i = 0;
	while (i < 100)
	{
		str[i] = ' ';
		i++;
	}
}
