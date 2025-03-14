/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:38:17 by kearmand          #+#    #+#             */
/*   Updated: 2025/03/13 09:55:39 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
void	ft_strcpy(char *dst, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
}

void	ft_strcat(char *dst, char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dst[i])
		i++;
	while (src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = 0;
}

static void	complete_with_space(char *str, int nb)
{
	int i;

	i = 0;
	while (i < nb)
	{
		*str = ' ';
		str++;
		i++;
	}
}

void	ft_custom_itoa(int n, char *str)
{
	int i;
	char tmp[100];

	i = 0;
	if (n == 0)
	{
		str[0] = '0';
		str[1] = 0;
		return ;
	}
	while (n > 0)
	{
		tmp[i] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	i--;
	if (i < 3)
		complete_with_space(str, 3 - i);
	while (i >= 0)
	{
		*str = tmp[i];
		str++;
		i--;
	}
}
