/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:38:58 by ndonaire          #+#    #+#             */
/*   Updated: 2022/06/30 18:04:12 by ndonaire         ###   ########.fr       */
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

	i = 0;
	lensb = lens(b);
	help = find_first_to_push(b, ref + 1);
	while (i < lensb)
	{
		if ((b[0] / pot_ten(10, ref + 1) + 1) % 2 != 0 || digits(b[0]) < ref + 1)
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
	while (b[0] != help)
	{
		write(1, "rb\n", 3);
		rotate(b);
	}
}

void	connect(int *a, int *b, int arg, int help, int ref)
{
	int	i;

	i = 0;
	if (ref == 0 && help == -45)
		return ;
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
		while(a[0] != help)
		{
			write(1, "rra\n", 4);
			reverse_rotate(a, arg);
		}
	}
	i = 0;
	//if (ref < amount_digits(a) - 1 && ref % 2 == 1)
	//	check_b(a, b, arg, ref);
	//else
	//{	
	check_b(a, b, arg, ref);
	//}
}

int	real_push(int *a, int *b, int arg, int count)
{
	write(1, "pb\n", 3);
	push(a, b, arg);
	count++;
	return (count);
}

void	real_rotate(int *a, int i, int count, int arg)
{
	if (i <= lens(a) / 2)
	{
		while (count < i)
		{
			write(1, "ra\n", 3);
			rotate(a);
			count++;
		}
	}
	else 
	{
		while (i < lens(a))
		{
			write(1, "rra\n", 4);
			reverse_rotate(a, arg);
			i++;
		}
	}
}
