/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_arrival.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 09:50:07 by kearmand          #+#    #+#             */
/*   Updated: 2025/03/20 14:45:55 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philosophers_arrival(t_data *data, pthread_t **thread)
{
	int	i;

	*thread = malloc(sizeof(pthread_t) * data->nb_philo);
	if (!*thread)
		return (MALLOC_FAIL);
	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_create(&(*thread)[i], NULL, &philo_presentation, data))
			return (i);
		i++;
	}
	return (0);
}

void philo_leave(t_data *data, pthread_t *thread, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		pthread_join(thread[i], NULL);
		i++;
	}
}
