/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:07:15 by kearmand          #+#    #+#             */
/*   Updated: 2025/03/27 10:14:56 by kearmand         ###   ########.fr       */
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
# include "print.h"

typedef struct s_data
{
	int				nb_philo;
	int				philo_id;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			nb_eat;
	int				sim_is_running;
	int				flag;

	t_msg_fifo		*tab_queue;
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
	struct timeval	time_last_meat;
	enum e_action	next_action;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	char			str[100];
}	t_philo;

/***
 * Function: error_msg
 */
int		error_msg(enum e_error err);

/***
 * Function: parsing
 */
int		parsing(t_data *data, int ac, char **av);
void 	init_data(t_data *data);

/***
 * Function: printf_msg
 */
void	print_msg(enum e_state state, int id, int time);

/***
 * Function: string_utils
 */
int		ft_strlen(char *str);
void	ft_strcpy(char *dst, char *src);
void	ft_strcat(char *dst, char *src);
int		ft_strcmp(char *s1, char *s2);
void	ft_custom_itoa(int n, char *str);

/***
 * Function: time
 */
int		get_runtime(struct timeval *start);
void	wait_for_start(struct timeval *star, t_philo *philo);
void	print_timer(void);
void	precise_sleep(struct timeval *start, long time);
long	get_time_diff(struct timeval *start, struct timeval *end);
void	time_copy(struct timeval *dst, struct timeval *src);
long 	time_to_long(struct timeval *time);

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

/***
 * Function: detect_starvation
 */
int		check_starvation(t_philo *philo);
int		sim_is_running(t_data *data);

/***
 * Function: philo_life
 */
void	philo_life(t_philo *philo);
void	annonce_action(t_philo *philo, enum e_state state, struct timeval *now);
void	next_action(t_philo *philo);
void	philo_eat(t_philo *philo, struct timeval *now);
void	philo_sleep(t_philo *philo, struct timeval *now);
void	philo_think(t_philo *philo, struct timeval *now);
void	philo_die(t_philo *philo, struct timeval *now);
                                      
#endif