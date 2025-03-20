/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 10:09:38 by kearmand          #+#    #+#             */
/*   Updated: 2025/03/20 10:38:38 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include <pthread.h>

# define SIZE_LIST 100

typedef struct s_msg_fifo
{
	int				buffer[SIZE_LIST]; //liste d intruction
	int				current_idx; //index de la liste
	int				last_idx; //dernier index de la liste
	pthread_mutex_t	mutex;//mutex pour la liste
} t_msg_fifo;

#endif