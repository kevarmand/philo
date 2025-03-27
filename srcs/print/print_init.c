/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:46:05 by kearmand          #+#    #+#             */
/*   Updated: 2025/03/27 11:46:03 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_init (t_msg_fifo **tab_msg, int nb_philo)
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
			print_destroy(*tab_msg, i);
			return (MUTEX_FAIL);
		}
		i++;
	}
	return (0);
}

void	print_destroy(t_msg_fifo *tab_msg, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		pthread_mutex_destroy(&tab_msg[i].mutex);
		i++;
	}
	free (tab_msg);
}