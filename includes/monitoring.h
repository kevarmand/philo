/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:09:38 by kearmand          #+#    #+#             */
/*   Updated: 2025/04/02 17:31:59 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONITORING_H
# define MONITORING_H

# include <pthread.h>
# include "philo.h"

# define SIZE_LIST 50

/****
 * Decoupage des msg
 * Long = 64 bits
 * 1er octet = type D ACTION
 * 2eme octet = id du philo
 * 3-8eme octet = temps de l instruction
 */
#define M_ACTION 0xFF00000000000000
#define M_ID 0x00FF000000000000
#define M_TIME 0x0000FFFFFFFFFFFF

/***
 * Forward declaration
 */
typedef struct s_philo t_philo;
typedef struct s_data t_data;
typedef struct s_fork t_fork;
typedef struct s_sim_is_running t_sim_is_running;
enum e_state;


typedef struct s_msg_fifo
{
	long			buffer[SIZE_LIST];
	int				current_idx;
	int				last_idx;
	pthread_mutex_t	mutex;
}	t_msg_fifo;

typedef struct s_data_monitoring
{
	long				*lst_msg;
	long				*lst_last_meal;
	t_msg_fifo			*tab_msg;
	t_fork				*fork_drawer;
	t_sim_is_running	*sim_is_running;
}	t_data_monitoring;

void	build_str(char *str, long instr, int flag, t_data *data);
long 	encode_msg(long id, enum e_state state, long time);
void	*watchdog(void *data1);
void	update_msg(t_data *data);
long	get_latest(t_data *data);

void 	printf_philo_die(int id, long time, int flag);

int display_event(t_data *data, char *str, long min);

void	add_msg(t_msg_fifo *msg_queue, long msg);
long	get_msg(t_msg_fifo *msg_queue);

/***
 * maessage generation function
 */

 void	add_id(int id, char *str);
 void	add_action(enum e_state state, char *str);
 void	add_time(int time, char *str);
 void	add_vanilla_time(long time, char *str);
 void	add_emoji(enum e_state state, char *str);
 void	add_color(int id, char *str);

/***
 * print advanced
 */
int		check_apetite(t_data *data);
void	end_simulation(t_data *data, int status);

#endif