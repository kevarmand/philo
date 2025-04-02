/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:10:52 by kearmand          #+#    #+#             */
/*   Updated: 2025/04/02 15:14:42 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	add_time(int time, char *str)
{
	int	ms_time;
	int	s_time;
	int m_time;

	ms_time = time / 1000;
	s_time = ms_time / 1000;
	m_time = s_time / 60;
	ms_time = ms_time % 1000;
	s_time = s_time % 60;
	if (m_time == 0)
		ft_strcat(str, "   ");
	else
	{
		ft_custom_itoa(m_time, str + ft_strlen(str));
		ft_strcat(str, ":");
	}
	if (s_time < 10)
		ft_strcat(str, " ");
	ft_custom_itoa(s_time, str + ft_strlen(str));
	ft_strcat(str, ".");
	if (ms_time < 100)
		ft_strcat(str, "0");
	if (ms_time < 10)
		ft_strcat(str, "0");
	ft_custom_itoa(ms_time, str + ft_strlen(str));
	ft_strcat(str, "\t");
}

void	add_vanilla_time(long time, char *str)
{
	int ms_time;

	ms_time = (int)(time / 1000);
	if (ms_time < 1000)
		ft_strcat(str, " ");
	if (ms_time < 10000)
		ft_strcat(str, " ");
	ft_custom_itoa(ms_time, str + ft_strlen(str));
	ft_strcat(str, "\t");
}

void	add_id(int id, char *str)
{
	ft_custom_itoa(id + 1, str + ft_strlen(str));
	ft_strcat(str, " ");
	if (id < 10)
		ft_strcat(str, " ");
	if (id < 100)
		ft_strcat(str, " ");
}

void	add_action(enum e_state state, char *str)
{
	if (state == THINKING)
		ft_strcpy(str + ft_strlen(str), "is thinking     ");
	else if (state == EATING)
		ft_strcpy(str + ft_strlen(str), "is eating       ");
	else if (state == SLEEPING)
		ft_strcpy(str + ft_strlen(str), "is sleeping     ");
	else if (state == DIED)
		ft_strcpy(str + ft_strlen(str), "died            ");
	else if (state == FORK)
		ft_strcpy(str + ft_strlen(str), "has taken a fork");
	else if (state == END)
		ft_strcpy(str + ft_strlen(str), "has had their fill");
}

/***
 * Il existe aussi des couleurs dans la palette étendue (256 couleurs).
 * Les codes de couleurs supplémentaires sont définis entre \033[38;5;Xm, 
 * où X est le numéro de couleur (de 0 à 255).
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

void	annonce_action(t_philo *philo, enum e_state state, long now)
{
	long time;
	long msg;

	time = now - philo->data->start;
	msg = encode_msg(philo->id, state, time);
	add_msg(philo->data->shared.tab_msg + philo->id, msg);
}
