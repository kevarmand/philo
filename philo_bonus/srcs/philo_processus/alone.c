/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alone.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 09:20:14 by kearmand          #+#    #+#             */
/*   Updated: 2025/04/19 16:36:08 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*alone(t_data *data)
{
	printf("  000 1 has taken a fork\n");
	usleep(data->time_to_die);
	printf("%5.3ld 1 died\n", data->time_to_die / 1000);
	return (NULL);
}

/***
 * @brief launch the simulation for one philosopher
 */
int	alone_launch(t_data *data)
{
	pid_t	philo;

	philo = fork();
	if (philo == -1)
	{
		perror("Fork failed");
		return (FORK_FAIL);
	}
	if (philo == 0)
	{
		alone(data);
		exit(0);
	}
	else
	{
		waitpid(philo, NULL, 0);
	}
	return (0);
}
