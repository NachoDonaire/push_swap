/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:59:03 by ndonaire          #+#    #+#             */
/*   Updated: 2023/05/10 16:08:18 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

int	lil_free(int y, int *dec)
{
	if (dec[y] == -1)
	{
		free(dec);
		return (1);
	}
	//free(dec);
	return (0);
}

int	is_sorted(int *a)
{
	int	i;
	int	y;
	int	*dec;

	i = 0;
	y = 1;
	dec = malloc(sizeof(int) * lens(a) + 1);
	while (a[i] != -1)
	{
		dec[i] = dec_converter(a[i]);
		i++;
	}
	dec[i] = -1;
	i = 0;
	while (dec[i] != -1)
	{
		if (dec[y] > dec[i] && dec[y] != -1)
			y++;
		i++;
	}
	return (lil_free(y, dec));
}

int	is_sorted_dec(int *a)
{
	int	i;
	int	y;

	i = 0;
	y = 1;
	while (a[i] != -1)
	{
		if (a[y] > a[i] && a[y] != -1)
			y++;
		i++;
	}
	if (a[y] == -1)
		return (1);
	return (0);
}

void	dec_conversion(int *a)
{
	int	i;

	i = 0;
	while (a[i] != -1)
	{
		a[i] = dec_converter(a[i]);
		i++;
	}
}
