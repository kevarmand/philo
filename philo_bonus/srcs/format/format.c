/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:10:52 by kearmand          #+#    #+#             */
/*   Updated: 2025/04/17 15:01:06 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/***
 * FUNCTIONs : take a string and add some information
 * 
 */

void	add_id(int id, char *str)
{
	ft_strcat(str, "\t");
	ft_custom_itoa(id + 1, str + ft_strlen(str));
	ft_strcat(str, " ");
	if (id < 10)
		ft_strcat(str, " ");
	if (id < 100)
		ft_strcat(str, " ");
}

void	add_action(enum e_state state, char *str)
{
	static char	*action[6] = {
		" is thinking",
		" is eating",
		" is sleeping",
		" died",
		" has taken a fork",
		" has had their fill"
	};

	ft_strcat(str, action[state]);
}

/***
 *@brief add color depending on the philosopher id
 */
void	add_color(int id, char *str)
{
	if (id == -1)
		ft_strcat(str, RESET);
	else
	{
		ft_strcat(str, "\033[38;5;");
		ft_custom_itoa(id + 1, str + ft_strlen(str));
		ft_strcat(str, "m");
	}
}

void	add_emoji(enum e_state state, char *str)
{
	if (state == THINKING)
		ft_strcat(str, "🤔 ");
	else if (state == EATING)
		ft_strcat(str, "🍝 ");
	else if (state == SLEEPING)
		ft_strcat(str, "😴 ");
	else if (state == DIED)
		ft_strcat(str, "💀 ");
	else if (state == FORK)
		ft_strcat(str, "🍴 ");
	else if (state == END)
		ft_strcat(str, "🏁 ");
	else if (state == TEST)
		ft_strcat(str, "🎉 ");
}

/***
 * @brief genereate the message and add it to the queue
 * 
 * @param *philo the philosopher structure
 * @param state the state of the philosopher
 * @param now the time of the event
 */
void	annonce_action(t_data *data, enum e_state state, long now)
{
	long	time;
	char	str[100];

	time = now - data->start;
	build_str(str, time, state, data);
	sem_wait(data->sem_print);
	write(1, str, ft_strlen(str));
	sem_post(data->sem_print);
}
