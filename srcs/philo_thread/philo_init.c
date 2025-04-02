/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 10:56:47 by kearmand          #+#    #+#             */
/*   Updated: 2025/04/02 15:28:08 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_life(t_philo *philo);

/***
 * Attention l id du philo = data->philo_id
 * [ Ce nest pas son nom , le nom est n + 1]
 */
void	*philo_presentation(void *data1)
{
	t_philo	philo;
	t_data	*data;

	data = (t_data *)data1;
	philo.data = data;;
	//on utilise un mutex qui existe deja
	pthread_mutex_lock(&data->shared.sim_is_running[0].mutex);
	philo.id = data->philo_id;
	data->philo_id++;
	pthread_mutex_unlock(&data->shared.sim_is_running[0].mutex);
	philo.nb_eat = 0;
	philo.left_fork = &data->shared.fork_drawer[philo.id];
	philo.right_fork = &data->shared.fork_drawer[(philo.id + 1) % data->nb_philo];
	philo.time_last_meat = data->start;
	philo.next_action = EAT;
	//wait le debut de la simulation
	wait_for_start(data->start, &philo);
	philo_life(&philo);
	return (NULL);
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
	long 		time;
	static void	(*action[3])(t_philo *philo, long *now) = {philo_eat,
				philo_sleep, philo_think};
				
	while (1)
	{
		time = ft_get_time();
		if (!is_sim_running(philo->data, philo->id))
			break ;
		if (philo->data->nb_eat != -1 && philo->nb_eat >= philo->data->nb_eat)
			break ;
		action[philo->next_action](philo, &time);
		next_action(philo);
	}
	annonce_action(philo, END, time);
}
