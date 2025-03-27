/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:09:38 by kearmand          #+#    #+#             */
/*   Updated: 2025/03/27 16:57:31 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include <pthread.h>
# include "philo.h"

# define SIZE_LIST 50

/****
 * Decoupage des instruction 
 * Long = 64 bits
 * 1er octet = type D ACTION
 * 2eme octet = id du philo
 * 3-8eme octet = temps de l instruction
 */
#define M_ACTION 0xFF00000000000000
#define M_ID 0x00FF000000000000
#define M_INST 0x0000FFFFFFFFFFFF

/***
 * Forwar declaration
 */
typedef struct s_philo t_philo;
typedef struct s_data t_data;
enum e_state;



typedef struct s_msg_fifo
{
	long			buffer[SIZE_LIST]; //liste d intruction
	int				current_idx;//index de la liste
	int				last_idx; 	//dernier index de la liste
	pthread_mutex_t	mutex;		//mutex pour la liste
	int				sim_is_running;		//flag de mort ()
}	t_msg_fifo;

void	gen_str(char *str, long instr, int flag);
void	gen_msg(t_philo *philo, enum e_state state, long time);
void	printer(t_data *data);
void	print_update(long *lst_instr, t_data *data);
long	check_min(long *lst_instr, t_data *data);

void	print_add(t_msg_fifo *msg_queue, long msg);
long	print_get(t_msg_fifo *msg_queue);
void	print_destroy(t_msg_fifo *tab_msg, int nb);
int		print_init (t_msg_fifo **tab_msg, int nb_philo);

/***
 * maessage generation function
 */

 void	add_id(int id, char *str);
 void	add_action(enum e_state state, char *str);
 void	add_time(int time, char *str);
 void	add_emoji(enum e_state state, char *str);

/***
 * print advanced
 */
int		check_starvation(long *lst_last_meal, t_data *data);
void	end_simulation(t_data *data);

#endif