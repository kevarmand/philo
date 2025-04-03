/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alone.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 09:20:14 by kearmand          #+#    #+#             */
/*   Updated: 2025/04/03 10:11:17 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*alone(void *data1)
{
	t_data	*data;

	data = (t_data *)data1;
	printf("  000 1 has taken a fork\n");
	usleep(data->time_to_die);
	printf("%5.3ld 1 died\n", data->time_to_die / 1000);
	return (NULL);
}

int	alone_launch(t_data *data)
{
	pthread_t	philo;

	if (pthread_create(&philo, NULL, alone, data))
		return (1);
	pthread_join(philo, NULL);
	return (0);
}
