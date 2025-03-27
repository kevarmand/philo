/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 10:56:47 by kearmand          #+#    #+#             */
/*   Updated: 2025/03/27 13:00:03 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_life(t_philo *philo);

/***
 * Attention l id du philo = data->philo_id
 * [ Ce nest pas son nom , le nom est n +1]
 */
void	philo_presentation(t_data *data)
{
	t_philo	philo;

	philo.data = data;
	
	for (int i = 0; i < 100; i++)
		philo.str[i] = 0;
	pthread_mutex_lock(&data->dead);
	philo.id = data->philo_id;
	data->philo_id++;
	pthread_mutex_unlock(&data->dead);
	philo.nb_eat = 0;
	if (philo.id % 2 == 1 && data->nb_philo % 2 == 1)
	{
		philo.right_fork = &data->fork_drawer[philo.id];
		philo.left_fork = &data->fork_drawer[(philo.id + 1) % data->nb_philo];
	}
	else
	{
		philo.left_fork = &data->fork_drawer[philo.id];
		philo.right_fork = &data->fork_drawer[(philo.id + 1) % data->nb_philo];
	}
	time_copy(&philo.time_last_meat, &data->start);
	philo.next_action = EAT;
	
	//wait le debut de la simulation
	wait_for_start(&data->start, &philo);
	philo_life(&philo);
}


void	next_action(t_philo *philo)
{
	if (philo->next_action == EAT)
		philo->next_action = SLEEP;
	else if (philo->next_action == SLEEP)
		philo->next_action = THINK;
	else if (philo->next_action == THINK)
		philo->next_action = EAT;
}

void	philo_life(t_philo *philo)
{
	struct timeval	time;
	//tableau de fonction
	static void	(*action[3])(t_philo *philo, struct timeval *now) = {philo_eat,
				philo_sleep, philo_think};
	
	while (1)
	{
		gettimeofday(&time, NULL);
		if (check_starvation(philo))
			return ;
		if (!sim_is_running(philo->data))
			return ;
		action[philo->next_action](philo, &time);
		next_action(philo);
	}
}
