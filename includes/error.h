/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:42:15 by kearmand          #+#    #+#             */
/*   Updated: 2025/03/30 12:14:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

enum e_error
{
	SUCCESS = 0,
	WRONG_NB_ARG = 1,
	WRONG_ARG,
	MALLOC_FAIL,
	MUTEX_FAIL
};


#endif