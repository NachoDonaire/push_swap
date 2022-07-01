/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_repeat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:28:00 by ndonaire          #+#    #+#             */
/*   Updated: 2022/07/01 09:58:18 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

int	no_repeat(int *a)
{
	int	i;
	int	y;

	i = 1;
	y = 0;
	while (a[y] != -1)
	{
		while (a[i] != -1)
		{
			if (a[y] == a[i])
				return (1);
			i++;
		}
		y++;
		i = y + 1;
	}
	return (0);
}

int	num_check(char	**args, int arg)
{
	int	i;
	int	y;

	y = 0;
	i = 1;
	while (i < arg)
	{
		while (args[i][y])
		{
			if ((args[i][y] < '0' || args[i][y] > '9') && args[i][y] != '-')
				return (1);
			y++;
		}
		y = 0;
		i++;
	}
	return (0);
}
