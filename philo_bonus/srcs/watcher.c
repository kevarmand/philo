/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:46:45 by kearmand          #+#    #+#             */
/*   Updated: 2025/04/19 16:32:34 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/***
 * @brief watch the philosophers to see if they are full
 * Loop until all the philosophers are full
 * @param *data : the data structure
 * @return 0 if success
 * @return -1 if error
 */
void	*watch_full(void *data1)
{
	t_data	*data;
	int		i;

	data = (t_data *)data1;
	i = 0;
	while (i < data->nb_philo)
	{
		sem_wait(data->sem_full);
		sem_wait(data->sem_main);
		if (data->simulation == 1)
		{
			sem_post(data->sem_main);
			return (NULL);
		}
		sem_post(data->sem_main);
		i++;
	}
	sem_wait(data->sem_main);
	data->simulation = 1;
	sem_post(data->sem_main);
	sem_post(data->sem_death);
	terminate_all(data->pid, data->nb_philo);
	usleep(200);
	return (NULL);
}

/***
 * @brief watch the philosophers to see if they are dead
 * @param *data : the data structure
 * @return 0 if success
 * @return -1 if error
 */
void	*watch_death(void *data1)
{
	t_data	*data;

	data = (t_data *)data1;
	sem_wait(data->sem_death);
	sem_wait(data->sem_main);
	if (data->simulation == 1)
	{
		sem_post(data->sem_main);
	}
	else
	{
		data->simulation = 1;
		sem_post(data->sem_main);
		sem_post(data->sem_full);
		terminate_all(data->pid, data->nb_philo);
	}
	usleep(200);
	return (NULL);
}
