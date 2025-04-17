/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processus_gestion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 09:50:07 by kearmand          #+#    #+#             */
/*   Updated: 2025/04/17 16:53:17 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


static int philosophers_arrival(t_data *data, pid_t *pid);
static int philo_leave(pid_t *state, int nb);
static int terminate_all(pid_t *state, int nb);
static void mark_philo_dead(pid_t *state, pid_t pid, int nb);

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
	return (philo_leave(pid, data->nb_philo));
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
			kill(state[i], SIGKILL);
		i++;
	}
	return (-1);
}

/***
 * @brief delete the line of the philo who is dead
 * 
 */
void	mark_philo_dead(pid_t *state, pid_t pid, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		if (state[i] == pid)
		{
			state[i] = 0;
			return ;
		}
		i++;
	}
}

/***
 * @param *state : array of state
 * @brief wait for all the philosophers to leave
 * the return of each philo is :
 * 1 : dead =>kill all other philo
 * 0  : alive => wait for the other
*/
static int	philo_leave(pid_t *state, int nb)
{
	int		status;
	pid_t	pid;
	int		i;

	usleep(2000000);
	printf("%i\n", state[0]);
	kill(state[0], SIGKILL);
	i = nb;
	while (i > 0)
	{
		printf("waitpid\n");
		pid = waitpid(-1, &status, 0);
		printf("pid : %d\n", pid);
		if (pid == -1)
		{
			error_msg(WAITPID_ERR);
			terminate_all(state, nb);
			return (-1);
		}
		if (WIFEXITED(status))
		{
			if (WEXITSTATUS(status) == 0)
				mark_philo_dead(state, pid, nb);
			else 
				return (terminate_all(state, nb));
			i--;
		}
	}
	return (0);
}
