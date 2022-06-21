/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   desmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:44:13 by ndonaire          #+#    #+#             */
/*   Updated: 2022/06/21 12:50:42 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

int	refy_zero(int *chunk, int arg)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (i < arg)
	{
		if (chunk[i] < chunk[y])
			y = i;
		i++;
	}
	return (chunk[y]);
}

int	check_ref(int *chunk, int refy, int arg)
{
	int	i;
	int	y;
	int	ref;

	i = 0;
	y = 0;
	ref = 0;
	if (refy == 0)
		return (refy_zero(chunk, arg));
	while (refy != ref)
	{
		while (i < arg)
		{
			if (chunk[y] > chunk[i])
				ref++;
			i++;
		}
		y++;
		i = 0;
		if (ref != refy)
			ref = 0;
		else
			return (chunk[y - 1]);
	}
	return (0);
}

void	desmap(int *a, int *chunk, int arg)
{
	int	i;
	int	y;
	int	ref;
	int	aux;

	i = 0;
	y = 0;
	ref = 0;
	aux = 0;
	while (y < arg)
	{
		a[y] = check_ref(chunk, y, arg);
		y++;
	}
}
