/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:38:58 by ndonaire          #+#    #+#             */
/*   Updated: 2022/07/26 20:16:01 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

void	first_bit(int *a, int *b, int arg)
{
	first_bit_bucle(a, b, arg);
	while (b[0] != -1)
	{
		write(1, "pa\n", 3);
		push(b, a, arg);
	}
}

int	find_first_to_rotate(int *a, int ref)
{
	int	i;

	i = 0;
	while (a[i] != -1)
	{
		if (((a[i] / pot_ten(10, ref)) + 1) % 2 == 0)
			return (a[i]);
		i++;
	}
	return (0);
}

int	find_first_to_push(int *a, int ref)
{
	int	i;

	i = 0;
	while (a[i] != -1)
	{
		if (((a[i] / pot_ten(10, ref)) + 1) % 2 != 0)
			return (a[i]);
		i++;
	}
	return (0);
}

void	check_b(int *a, int *b, int arg, int ref)
{
	int	i;
	int	lensb;
	int	help;
	int	magic;

	i = 0;
	lensb = lens(b);
	help = find_first_to_push(b, ref + 1);
	magic = 0;
	while (i < lensb)
	{
		magic = (b[0] / pot_ten(10, ref + 1) + 1);
		if (magic % 2 != 0 || digits(b[0]) < ref + 1)
		{
			write(1, "rb\n", 3);
			rotate(b);
		}
		else
		{
			write(1, "pa\n", 3);
			push(b, a, arg);
		}
		i++;
	}
	b_bucle(help, b);
}

void	connect(int *a, int arg, int help)
{
	int	i;

	i = 0;
	while (a[i] != help)
		i++;
	if (i <= lens(a) / 2)
	{
		while (a[0] != help)
		{
			write(1, "ra\n", 3);
			rotate(a);
		}
	}
	else if (i > lens(a) / 2)
	{
		while (a[0] != help)
		{
			write(1, "rra\n", 4);
			reverse_rotate(a, arg);
		}
	}
	i = 0;
}
