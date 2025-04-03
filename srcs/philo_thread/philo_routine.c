/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:22:03 by kearmand          #+#    #+#             */
/*   Updated: 2025/04/03 13:23:28 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	next_action(t_philo *philo);

/***
 * @brief philosopher routine
 * 
 * @param *philo the philosopher structure
 */
void	philo_life(t_philo *philo)
{
	long		time;
	static void	(*action[3])(t_philo *philo, long *now) = {
		philo_eat,
		philo_sleep,
		philo_think
	};

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

static void	next_action(t_philo *philo)
{
	if (philo->next_action == EAT)
		philo->next_action = SLEEP;
	else if (philo->next_action == SLEEP)
		philo->next_action = THINK;
	else if (philo->next_action == THINK)
		philo->next_action = EAT;
}
