/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:07:15 by kearmand          #+#    #+#             */
/*   Updated: 2025/04/01 16:09:50 by kearmand         ###   ########.fr       */
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
# include "monitoring.h"

/***
 * Structure: t_fork
 * -------------------
 * state: -1 = taken
 * else id of last philo who took it
 */
typedef struct s_fork
{
	int				state;
	pthread_mutex_t	mutex;
}	t_fork;

/***
 * Structure: t_sim_is_running
 * -------------------
 * state: 1 = running
 * else 0
 */
typedef struct s_sim_is_running
{
	int				state;
	pthread_mutex_t	mutex;
}	t_sim_is_running;

/*** */


typedef struct s_data
{
	long			nb_philo;
	int				philo_id;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			nb_eat;
	int				flag;
	long			start;

	t_data_monitoring shared;
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
	long			time_last_meat;
	enum e_action	next_action;
	t_fork			*left_fork;
	t_fork			*right_fork;
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
 * Function: string_utils
 */
int		ft_strlen(char *str);
void	ft_strcpy(char *dst, char *src);
void	ft_strcat(char *dst, char *src);
int		ft_strcmp(char *s1, char *s2);
void	ft_custom_itoa(int n, char *str);
int		ft_strchr(char *str, char c);

/***
 * Function: time
 */
long	get_runtime(long start);
void	wait_for_start(long star, t_philo *philo);
void	precise_sleep(long start, long time);
long	ft_get_time(void);

/***
 * Function: philo_thread
 */
int		philosophers_arrival(t_data *data, pthread_t **thread);
void	philo_leave(pthread_t *thread, int nb);
void	*philo_presentation(void *data);
int		is_sim_running(t_data *data, int id);

/***
 * data init function
 */
void	init_data(t_data *data);
int		init_shared_data(t_data *data);
int		init_queue(t_msg_fifo **tab_msg, int nb_philo);
int 	init_fork_drawer(t_fork **fork_drawer, long nb_philo);
int		init_sim_is_running(t_sim_is_running **sim_is_running, long nb_philo);
void	destroy_sim_is_running(t_sim_is_running *sim_is_running, long nb_philo);
void	destroy_fork_drawer(t_fork *fork_drawer, long nb);
void	destroy_queue(t_msg_fifo *tab_msg, int nb);
void 	destroy_shared_data(t_data *data);

/***
 * Function: philo_life
 */
void	philo_life(t_philo *philo);
void	annonce_action(t_philo *philo, enum e_state state,long now);
void	next_action(t_philo *philo);
void	philo_eat(t_philo *philo, long *now);
void	philo_sleep(t_philo *philo, long *now);
void	philo_think(t_philo *philo, long *now);

                                      
#endif