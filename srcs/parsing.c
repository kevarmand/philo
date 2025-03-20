/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:18:12 by kearmand          #+#    #+#             */
/*   Updated: 2025/03/19 09:34:31 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	custom_atoi(char *str, long *number)
{
	long	n;
	int		i;

	i = 0;
	if (*str == '-')
		return (1);
	n = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		if (n > 2147483648)
			return (1);
		n = 10 * n + (str[i] - '0');
		i++;
	}
	if (str[i] != 0 || i == 0 || (n > 2147483647))
		return (1);
	*number = n;
	return (0);
}


int		parsing(t_data *data, int ac, char **av)
{
	if (ac != 5 && ac != 6)
		return (error_msg(WRONG_NB_ARG));
	if (!ft_strcmp(av[1], "-c")) //On ajoute un flag
	{
		data->flag = 1;
		printf("flag = %d\n", data->flag);
		av++;
		ac--;
	}
	if (custom_atoi(av[1], &data->nb_philo)
		|| custom_atoi(av[2], &data->time_to_die)
		|| custom_atoi(av[3], &data->time_to_eat)
		|| custom_atoi(av[4], &data->time_to_sleep))
		return (error_msg(WRONG_ARG));
	if (ac == 6)
	{
		if (custom_atoi(av[5], &data->nb_eat))
			return (error_msg(WRONG_ARG));
	}
	else
		data->nb_eat = -1;
	if (data->nb_philo < 1 || data->time_to_die < 60 || data->time_to_eat < 60
		|| data->time_to_sleep < 60 || (ac == 6 && data->nb_eat < 1))
		return (error_msg(WRONG_ARG));
	return (0);
}
