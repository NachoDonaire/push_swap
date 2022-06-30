/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_bit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:56:12 by ndonaire          #+#    #+#             */
/*   Updated: 2022/06/30 18:04:09 by ndonaire         ###   ########.fr       */
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
/*
void	general_bit_bucle(int *a, int *b, int arg, int ref)
{
	int	i;
	int	magic;

	i = 0;
	magic = 0;
	while (i < lens(a))
	{
		*if (digits(a[0]) == ref)
		{
			magic = a[0] / pot_ten(10, digits(a[0]) - 1) + 1;
			if (magic % 2 != 0)
			{
				write(1, "pb\n", 3);
				push(a, b, arg);
			}
			else
			{
				write(1, "ra\n", 3);
				rotate(a);
			}
		}
		if (((a[0] / pot_ten(10, ref)) + 1) % 2 != 0)
		{
			write(1, "pb\n", 3);
			push(a, b, arg);
		}
		else
		{
			write(1, "ra\n", 3);
			rotate(a);
		}
		i++;
	}
		magic = (a[0] / pot_ten(10, digits(a[0]) - 1)) + 1;
		if (digits(a[0]) == ref && magic % 2 != 0)
		{
			write(1, "pb\n", 3);
			push(a, b, arg);
		}
		else if (digits(a[0]) == ref && magic % 2 == 0)
		{
			write(1, "ra\n", 3);
			rotate(a);
		}
		if (((a[0] / pot_ten(10, ref)) + 1) % 2 != 0 && digits(a[0]) < ref)
		{
			write(1, "pb\n", 3);
			push(a, b, arg);
		}
		else if (((a[0] / pot_ten(10, ref)) + 1) % 2 == 0 && digits(a[0]) < ref)
		{
			write(1, "ra\n", 3);
			rotate(a);
		}
		i++;
}
*/
void	general_bit(int *a, int *b, int arg, int amount)
{
	int	ref;
	int	help;

	ref = 1;
	help = 0;
	while (ref < amount && is_sorted(a) != 1)
	{
		help = find_first_to_rotate(a, ref);
		general_bit_bucle(a, b, arg, ref);
		connect(a, b, arg, help, ref);
		ref++;
	}
}
