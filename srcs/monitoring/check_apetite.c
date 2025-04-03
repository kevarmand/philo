/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_apetite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:03:06 by kearmand          #+#    #+#             */
/*   Updated: 2025/04/03 09:44:29 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_starvation(t_data *data);
static int	check_satiety(t_data *data);

int	check_apetite(t_data *data)
{
	int	status;

	status = check_starvation(data);
	status += check_satiety(data);
	return (status);
}

static int	check_starvation(t_data *data)
{
	int		i;
	long	now;
	long	diff;
	long	*lst_last_meal;

	lst_last_meal = data->shared.lst_last_meal;
	i = 0;
	now = get_runtime(data->start);
	while (i < data->nb_philo)
	{
		if (lst_last_meal[i] != -1)
		{
			diff = now - lst_last_meal[i];
			if (diff > data->time_to_die)
			{
				printf_philo_die(i, now, data->flag);
				return (1);
			}
		}
		i++;
	}
	return (0);
}

static int	check_satiety(t_data *data)
{
	long	i;
	long	*lst_last_meal;
	long	nb_philo;

	nb_philo = data->nb_philo;
	lst_last_meal = data->shared.lst_last_meal;
	i = -1;
	while (++i < nb_philo)
	{
		if (lst_last_meal[i] != -1)
			return (0);
	}
	return (2);
}

/***
 * "kill all philo"
 */
void	end_simulation(t_data *data, int status)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_lock(&data->shared.sim_is_running[i].mutex);
		data->shared.sim_is_running[i].state = 0;
		pthread_mutex_unlock(&data->shared.sim_is_running[i].mutex);
		i++;
	}
	printf("\n");
	if (status == 1)
		printf("🚑  🚑  A philosopher died, the simulation is over  🚑  🚑\n");
	else if (status == 2)
	{
		printf("🎉  🎉  Everyone has finished eating, the simulation is over");
		printf("  🎉  🎉\n");
	}
}
