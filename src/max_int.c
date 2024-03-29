/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 09:57:00 by ndonaire          #+#    #+#             */
/*   Updated: 2022/08/02 13:08:04 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

int	finder(char *s, char *coin)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (s[i])
	{
		while (s[i] == coin[y])
		{
			i++;
			y++;
			if (coin[y] == '\0')
				return (1);
		}
		i++;
	}
	return (0);
}

int	lensy(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	is_max(char **args, int arg)
{
	int		i;
	long	y;

	y = 0;
	i = 1;
	if (arg == 0)
		return (0);
	while (args[i])
	{
		if (lensy(args[i]) >= 10)
		{
			y = ft_atoi(args[i]);
			if (y > 2147483647 || y < -2147483648)
				return (1);
		}
		i++;
	}
	return (0);
}
