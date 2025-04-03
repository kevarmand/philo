/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_arrival.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 09:50:07 by kearmand          #+#    #+#             */
/*   Updated: 2025/04/03 09:24:33 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/***
 * on cree les philo
 */
int	philosophers_arrival(t_data *data, pthread_t **thread)
{
	int	i;

	*thread = malloc(sizeof(pthread_t) * data->nb_philo + 1);
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
