/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_bit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:56:12 by ndonaire          #+#    #+#             */
/*   Updated: 2022/06/21 13:08:14 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

void	general_bit_bucle(int *a, int *b, int arg, int ref)
{
	int	i;
	int	count;
	int	magic;

	i = 0;
	count = 0;
	magic = 0;
	while (a[i] != -1)
	{
		magic = (a[i] / pot_ten(10, digits(a[i]) - 1)) + 1;
		if (digits(a[i]) == ref && magic % 2 != 0)
		{
			real_rotate(a, i, count);
			count = real_push(a, b, arg, count);
		}
		if (((a[i] / pot_ten(10, ref)) + 1) % 2 != 0 || digits(a[i]) < ref)
		{
			real_rotate(a, i, count);
			count = real_push(a, b, arg, count);
		}
		i++;
		if (count != 0)
			i = 0;
		count = 0;
	}
}

void	general_bit(int *a, int *b, int arg, int amount)
{
	int	ref;
	int	help;

	ref = 1;
	help = 0;
	while (ref < amount)
	{
		help = find_first_to_rotate(a, ref);
		general_bit_bucle(a, b, arg, ref);
		connect(a, b, arg, help);
		ref++;
	}
}
