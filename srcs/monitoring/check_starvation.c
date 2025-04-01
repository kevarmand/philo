/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_starvation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:03:06 by kearmand          #+#    #+#             */
/*   Updated: 2025/04/01 16:40:34 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_starvation(long *lst_last_meal, t_data *data)
{
	int		i;
	long	now;
	long	diff;

	i = 0;
	now = get_runtime(data->start);
	while (i < data->nb_philo)
	{
		if (lst_last_meal[i] != -1)
		{
			diff = now - lst_last_meal[i];
			if (diff > data->time_to_die)
			{
				printf("philo %d is dead\n", i + 1);
				return (1);
			}
		}
		i++;
	}
	return (0);
}

/***
 * "kill all philo"
 */
void	end_simulation(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_lock(&data->shared.tab_msg[i].mutex);
		data->shared.tab_msg[i].buffer[data->shared.tab_msg[i].current_idx] = -1;
		pthread_mutex_unlock(&data->shared.tab_msg[i].mutex);
		i++;
	}
}
