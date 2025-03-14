/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:07:15 by kearmand          #+#    #+#             */
/*   Updated: 2025/03/14 14:00:46 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

# include "color.h"
# include "error.h"

typedef struct s_data
{
	int				nb_philo;
	int				philo_id;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_eat;
	int				sim_is_running;
	
	pthread_mutex_t	*fork_drawer;
	pthread_mutex_t	talking_stick;
	pthread_mutex_t	dead;
	struct timeval	start;
}	t_data;

enum e_action
{
	EAT = 0,
	SLEEP,
	THINK
};

enum e_state
{
	THINKING = 0,
	EATING,
	SLEEPING,
	DIED,
	FORK,
	END,
	TEST
};


typedef struct s_philo
{
	t_data			*data;
	int				id;
	int				nb_eat;
	int				time_last_meat;
	enum e_action	next_action;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}	t_philo;

/***
 * Function: error_msg
 */
int		error_msg(enum e_error err);

/***
 * Function: parsing
 */
int		parsing(t_data *data, int ac, char **av);

/***
 * Function: printf_msg
 */
void	print_msg(enum e_state state, int id, int time);

/***
 * Function: string_utils
 */
int		ft_strlen(char *str);
void	ft_strcpy(char *dst, char *src);
void	ft_custom_itoa(int n, char *str);

/***
 * Function: time
 */
int		get_runtime(struct timeval *start);
void	wait_for_start(t_data *data);
void	print_timer(void);

/***
 * Function: philo_thread
 */
int		philosophers_arrival(t_data *data, pthread_t **thread);
void	philo_leave(t_data *data, pthread_t *thread, int nb);
void	philo_presentation(t_data *data);

/***
 * Fork function
 */
int		create_fork(t_data *data);
void	destroy_fork_drawer(t_data *data, int nb);

#endif