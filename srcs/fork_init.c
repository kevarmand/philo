/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 09:34:44 by kearmand          #+#    #+#             */
/*   Updated: 2025/03/14 11:21:40 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_fork(t_data *data)
{
	int	i;

	data->fork_drawer = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (!data->fork_drawer)
		return (MALLOC_FAIL);
	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_mutex_init(&data->fork_drawer[i], NULL))
		{
			destroy_fork_drawer(data, i);
			return (MUTEX_FAIL);
		}
		i++;
	}
	if (pthread_mutex_init(&data->talking_stick, NULL))
	{
		destroy_fork_drawer(data, i);
		return (MUTEX_FAIL);
	}
	if (pthread_mutex_init(&data->dead, NULL))
	{
		destroy_fork_drawer(data, i);
		return (MUTEX_FAIL);
	}
	return (0);
}

void	destroy_fork_drawer(t_data *data, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		pthread_mutex_destroy(&data->fork_drawer[i]);
		i++;
	}
	free (data->fork_drawer);
}