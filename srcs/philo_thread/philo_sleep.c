/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:08:38 by kearmand          #+#    #+#             */
/*   Updated: 2025/03/31 15:29:27 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_sleep(t_philo *philo, long *now)
{
	long	time_to_sleep;

	time_to_sleep = philo->data->time_to_sleep;
	annonce_action(philo, SLEEPING, *now);
	precise_sleep(*now, time_to_sleep);
}