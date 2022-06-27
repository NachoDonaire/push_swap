/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:59:03 by ndonaire          #+#    #+#             */
/*   Updated: 2022/06/27 18:11:53 by ndonaire         ###   ########.fr       */
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
	else
	{
		free(dec);
		return (0);
	}
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
