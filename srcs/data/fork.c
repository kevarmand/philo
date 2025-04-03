/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 09:34:44 by kearmand          #+#    #+#             */
/*   Updated: 2025/04/03 09:45:41 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_fork_drawer(t_fork *fork_drawer, long nb)
{
	int	i;

	if (!fork_drawer)
		return ;
	i = 0;
	while (i < nb)
	{
		pthread_mutex_destroy(&fork_drawer[i].mutex);
		i++;
	}
	free (fork_drawer);
}

int	init_fork_drawer(t_fork **fork_drawer, long nb_philo)
{
	int	i;

	*fork_drawer = malloc(sizeof(t_fork) * nb_philo);
	if (!*fork_drawer)
		return (MALLOC_FAIL);
	i = 0;
	while (i < nb_philo)
	{
		(*fork_drawer)[i].state = -2;
		if (pthread_mutex_init(&(*fork_drawer)[i].mutex, NULL))
		{
			destroy_fork_drawer(*fork_drawer, i);
			*fork_drawer = NULL;
			return (MUTEX_FAIL);
		}
		i++;
	}
	return (0);
}
