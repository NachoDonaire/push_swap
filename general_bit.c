/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_bit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:56:12 by ndonaire          #+#    #+#             */
/*   Updated: 2022/07/01 10:13:54 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

int	number_push(int *a, int ref)
{
	int	i;
	int	n_push;
	int	magic;

	i = 0;
	magic = 0;
	n_push = 0;
	while (a[i] != -1)
	{
		magic = (a[i] / pot_ten(10, digits(a[i]) - 1)) + 1;
		if (digits(a[i]) == ref && magic % 2 != 0)
			n_push++;
		if (((a[i] / pot_ten(10, ref)) + 1) % 2 != 0 || digits(a[i]) < ref)
			n_push++;
		i++;
	}
	return (n_push);
}

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
			real_rotate(a, i, count, arg);
			count = real_push(a, b, arg, count);
		}
		if (((a[i] / pot_ten(10, ref)) + 1) % 2 != 0 || digits(a[i]) < ref)
		{
			real_rotate(a, i, count, arg);
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

	help = 0;
	ref = 1;
	while (ref < amount && is_sorted(a) != 1)
	{
		help = find_first_to_rotate(a, ref);
		general_bit_bucle(a, b, arg, ref);
		connect(a, arg, help);
		check_b(a, b, arg, ref);
		if (ref + 1 == amount)
		{
			while (b[0] != -1)
			{
				write(1, "pa\n", 3);
				push(b, a, arg);
			}
		}
		ref++;
	}
}
