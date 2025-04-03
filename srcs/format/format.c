/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:10:52 by kearmand          #+#    #+#             */
/*   Updated: 2025/04/03 10:23:58 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		" is thinking     ",
		" is eating       ",
		" is sleeping     ",
		" died            ",
		" has taken a fork",
		" has had their fill"
	};

	ft_strcat(str, action[state]);
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
	long	time;
	long	msg;

	time = now - philo->data->start;
	msg = encode_msg(philo->id, state, time);
	add_msg(philo->data->shared.tab_msg + philo->id, msg);
}
