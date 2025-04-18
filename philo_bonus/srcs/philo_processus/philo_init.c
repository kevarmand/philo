/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 10:56:47 by kearmand          #+#    #+#             */
/*   Updated: 2025/04/18 11:14:37 by kearmand         ###   ########.fr       */
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
	t_data		*data;
	pthread_t	thread_id;
	int			ret;

	data = (t_data *)data1;
	ret = pthread_create(&thread_id, NULL, watchdog, data);
	if (ret != 0)
	{
		printf("Error: pthread_create\n");
		return (NULL);
	}
	pthread_detach(thread_id);
	wait_for_start(data->start, data);
	philo_life(data);
	return (NULL);
}
