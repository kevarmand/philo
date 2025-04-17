/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:42:15 by kearmand          #+#    #+#             */
/*   Updated: 2025/04/03 14:22:02 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

enum e_error
{
	SUCCESS = 0,
	WRONG_NB_ARG = -1,
	WRONG_ARG = -2,
	MALLOC_FAIL = -3,
	MUTEX_FAIL = -4,
	THREAD_FAIL = -5,
	DEATH = -6,
	WRONG_FLAG = -7,
	ERROR_NB = -8,
	ERROR_MEAL = -9,
	ERROR_LOGICAL = -10,
	ERROR_TIME = -11
};

#endif