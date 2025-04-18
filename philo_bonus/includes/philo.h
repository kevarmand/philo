/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:07:15 by kearmand          #+#    #+#             */
/*   Updated: 2025/04/18 15:22:39 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <string.h>
# include <semaphore.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <fcntl.h>


# include "error.h"
# include "color.h"

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

typedef struct s_data
{
	long				nb_philo;
	int					philo_id;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	long				nb_eat;
	int					flag;
	long				start;

	sem_t				*sem_forks_count;
	sem_t				*sem_forks_access;
	sem_t				*sem_print;
	sem_t				*sem_death;
	sem_t				*sem_full;
	sem_t				*sem_main;
	sem_t				**sem_meal_check;
	pid_t				*pid;

	int					nb_eat_done;
	int					simulation;
	long				time_last_meal;
	enum e_action		next_action;
}	t_data;

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
void	ft_strcat(char *dst, char *src);
int		ft_strcmp(char *s1, char *s2);
void	ft_custom_itoa(int n, char *str);
int		ft_strchr(char *str, char c);

/***
 * watchmain
 */
void	*watch_full(void *data1);
void	*watch_death(void *data1);

/***
 * Function: time
 */

long	get_runtime(long start);
void	wait_for_start(long start, t_data *data);
void	precise_sleep(long start, long time);
long	ft_get_time(void);
void	ft_infinite_loop();
/***
 * Function: philo_processus
 */
void	*watchdog(void *data1);
int		start_simulation(t_data *data);
void	*philo_presentation(void *data);
int		alone_launch(t_data *data);

/***
 * data init function
 */

void	init_data(t_data *data);
int		init_semaphores(t_data *data);
void	destroy_semaphores(t_data *data);

/***
 * Function: philo_life
 */

void	philo_life(t_data *data);
void	philo_eat(t_data *data, long *now);
void	philo_sleep(t_data *data, long *now);
void	philo_think(t_data *data, long *now);


/***
 * Function: philo_processus
 */
void	build_str(char *str, long time, enum e_state action, t_data *data);
void	annonce_action(t_data *data, enum e_state state, long now);

void	print_death(t_data *data, long time);
void	add_id(int id, char *str);
void	add_action(enum e_state state, char *str);
void	add_time(int time, char *str);
void	add_vanilla_time(long time, char *str);
void	add_emoji(enum e_state state, char *str);
void	add_color(int id, char *str);
#endif
