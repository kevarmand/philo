/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_gestion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 09:50:07 by kearmand          #+#    #+#             */
/*   Updated: 2025/04/03 13:42:44 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	philosophers_arrival(t_data *data, pthread_t **thread);
static void	philo_leave(pthread_t *thread, int nb);

/***
 * @brief start the simulation
 * 
 * Encapsulate the creation of all threads
 * 
 * @param *data the data structure
 * @return int the number of philosophers
 */
int	start_simulation(t_data *data)
{
	int			err;
	pthread_t	*thread;
	pthread_t	monithread;

	data->start = ft_get_time() + 1000000;
	err = philosophers_arrival(data, &thread);
	if (err == data->nb_philo)
	{
		if (!pthread_create(&monithread, NULL, watchdog, data))
			pthread_join(monithread, NULL);
	}
	if (err > 0)
		philo_leave(thread, err);
	free (thread);
	return (err);
}

/***
 * @brief Create all the philosophers threads
 */
int	philosophers_arrival(t_data *data, pthread_t **thread)
{
	int	i;

	*thread = NULL;
	*thread = malloc(sizeof(pthread_t) * (data->nb_philo + 1));
	if (!*thread)
		return (MALLOC_FAIL);
	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_create(&(*thread)[i], NULL, &philo_presentation, data))
			return (i);
		i++;
	}
	return (data->nb_philo);
}

/**
 * @brief wait for all the philosophers to leave
 */
void	philo_leave(pthread_t *thread, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		pthread_join(thread[i], NULL);
		i++;
	}
}
