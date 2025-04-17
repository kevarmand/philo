/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_buffer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:17:06 by kearmand          #+#    #+#             */
/*   Updated: 2025/04/02 14:15:45 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	add_msg(t_msg_fifo *msg_queue, long msg)
{
	pthread_mutex_lock(&msg_queue->mutex);
	msg_queue->buffer[msg_queue->last_idx] = msg;
	msg_queue->last_idx = (msg_queue->last_idx + 1) % SIZE_LIST;
	pthread_mutex_unlock(&msg_queue->mutex);
}

long	get_msg(t_msg_fifo *msg_queue)
{
	long	msg;

	pthread_mutex_lock(&msg_queue->mutex);
	if (msg_queue->current_idx == msg_queue->last_idx)
	{
		pthread_mutex_unlock(&msg_queue->mutex);
		return (-1);
	}
	msg = msg_queue->buffer[msg_queue->current_idx];
	msg_queue->current_idx = (msg_queue->current_idx + 1) % SIZE_LIST;
	pthread_mutex_unlock(&msg_queue->mutex);
	return (msg);
}
