/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 10:56:47 by kearmand          #+#    #+#             */
/*   Updated: 2025/04/17 16:08:50 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


/***
 * @brief initialize the philosopher (data/wait for start)
 * 
 * * @param *data the data structure (void *)
 */
void	*philo_presentation(void *data1)
{
	t_data	*data;
	pid_t	pid;

	data = (t_data *)data1;

	pid = fork();
	if (pid == -1)
	{
		exit(1);
	}
	if (pid == 0)
		watchdog(data);	
	wait_for_start(data->start, data);
	philo_life(data);
	return (NULL);
}
