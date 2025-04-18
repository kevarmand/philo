/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:46:45 by kearmand          #+#    #+#             */
/*   Updated: 2025/04/18 15:23:22 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*watch_full(void *data1)
{
	t_data	*data;
	int		i;

	data = (t_data *)data1;
	i = 0;
	while (i < data->nb_philo)
	{
		sem_wait(data->sem_full); // des qu un philo a mangé
		sem_wait(data->sem_main);
		if (data->simulation == 1) //watch a death_watch
		{
			sem_post(data->sem_main);
			return (NULL);
		}
		sem_post(data->sem_main);
		i++;
	}
	//tout les philosophes ont mange on arete 
	sem_wait(data->sem_main);
	data->simulation = 1; // on dit a watch_death de s'arreter
	sem_post(data->sem_main);
	sem_post(data->sem_death); // on dit a watch_death de s'arreter
	//retourner dans le main (peut etr eimplemeter un messagepou dire a watch_death d areter de surveiller)
	terminate_all(data->pid, data->nb_philo);
	usleep(100);
	return (NULL);
}

void	*watch_death(void *data1)
{
	t_data	*data;

	data = (t_data *)data1;
	sem_wait(data->sem_death); // si unseul meurt on kill tout
	sem_wait(data->sem_main); // pour changer le flag
	if (data->simulation == 1) //alors watch full a fini le travail
	{
		sem_post(data->sem_main);
	}
	else
	{
		data->simulation = 1; // on dit a full full de s'arreter
		sem_post(data->sem_main);
		sem_post(data->sem_full); // on dit a watch full de s'arreter
		terminate_all(data->pid, data->nb_philo);
	}
	usleep(100);
	return (NULL);
}