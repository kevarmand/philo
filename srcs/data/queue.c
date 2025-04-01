/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:46:05 by kearmand          #+#    #+#             */
/*   Updated: 2025/04/01 16:48:47 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_queue(t_msg_fifo **tab_msg, int nb_philo)
{
	int	i;

	*tab_msg = malloc(sizeof(t_msg_fifo) * nb_philo);
	if (!*tab_msg)
		return (MALLOC_FAIL);
	i = 0;
	while (i < nb_philo)
	{
		(*tab_msg)[i].current_idx = 0;
		(*tab_msg)[i].last_idx = 0;
		if (pthread_mutex_init(&(*tab_msg)[i].mutex, NULL))
		{
			destroy_queue(*tab_msg, i);
			*tab_msg = NULL;
			return (MUTEX_FAIL);
		}
		i++;
	}
	return (0);
}

void	destroy_queue(t_msg_fifo *tab_msg, int nb)
{
	int	i;

	if (!tab_msg)
		return ;
	i = 0;
	while (i < nb)
	{
		pthread_mutex_destroy(&tab_msg[i].mutex);
		i++;
	}
	free (tab_msg);
}