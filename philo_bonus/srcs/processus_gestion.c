/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processus_gestion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 09:50:07 by kearmand          #+#    #+#             */
/*   Updated: 2025/04/18 15:22:10 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


static int philosophers_arrival(t_data *data, pid_t *pid);
static int philo_leave(t_data *data);
static int terminate_all(pid_t *state, int nb);

/***
 * Encapsulate the fork function
 * to create the philosophers
 * and to handle the error
 * @param *data : the data structure
 * @return 0 if success
 * @return -1 if error
 */
int	start_simulation(t_data *data)
{
	int		err;
	pid_t	*pid;

	err = 0;
	data->start = ft_get_time() + 1000000;
	data->time_last_meal = data->start;
	pid = malloc(sizeof(pid_t) * data->nb_philo);
	if (!pid)
		return (error_msg(MALLOC_FAIL));
	if (data->nb_philo > 1)
	{
		err = philosophers_arrival(data, pid);
		free(pid);
		if (err == FORK_FAIL)
			return (FORK_FAIL);
	}
	return (0);
}

/***
 * @brief Create all the philosophers fork
 */
static int	philosophers_arrival(t_data *data, pid_t *pid)
{
	int		i;

	i = 0;
	while (i < data->nb_philo)
	{
		pid[i] = fork();
		if (pid[i] == -1)
		{
			error_msg(FORK_FAIL);
			terminate_all(pid, i);
			return (FORK_FAIL);
		}
		if (pid[i] == 0)
		{
			data->philo_id = i;
			philo_presentation(data);
		}
		i++;
	}
	data->pid = pid;
	return (philo_leave(pid));
}

/***
 * @brief Terminate all the children-processus
 */
static int	terminate_all(pid_t *state, int nb)
{
	int	i;
	printf("kill all\n");
	i = 0;
	while (i < nb)
	{
		if (state[i] != 0)
		{
			printf("try kill %d-%d\n", state[i], i);
			kill(state[i], SIGKILL);
			printf("ok: kill %d-%d\n", state[i], i);
		}
		i++;
	}
	return (-1);
}

/***
 * @param *state : array of state
 * @brief wait for all the philosophers to leave
 * the return of each philo is :
 * 1 : dead =>kill all other philo
 * 0  : alive => wait for the other
*/
static int	philo_leave(t_data *data)
{
	pthread_t	watch_death_thread;
	pthread_t	watch_full_thread;

	if (pthread_create(&watch_full_thread, NULL, watch_full, data) != 0)
	{
		perror("pthread_create watch_full failed");
		return (1);
	}
	if (pthread_create(&watch_death_thread, NULL, watch_death, data) != 0)
	{
		perror("pthread_create watch_death failed");
		sem_wait(data->sem_main);
		data->simulation = 1;
		sem_post(data->sem_main);
		sem_post(data->sem_full);
		pthread_join(watch_full_thread, NULL);
		return (1);
	}
	pthread_join(watch_full_thread, NULL);
	pthread_join(watch_death_thread, NULL);
	return (0);
}
