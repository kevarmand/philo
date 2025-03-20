/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:09:38 by kearmand          #+#    #+#             */
/*   Updated: 2025/03/20 14:22:46 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include <pthread.h>

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
#define M_INST 0x0000FFFFFFFFFF

typedef struct s_msg_fifo
{
	long			buffer[SIZE_LIST]; //liste d intruction
	int				current_idx; //index de la liste
	int				last_idx; //dernier index de la liste
	pthread_mutex_t	mutex;//mutex pour la liste
} t_msg_fifo;

#endif