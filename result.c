/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:38:58 by ndonaire          #+#    #+#             */
/*   Updated: 2022/06/21 11:52:58 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

void	first_bit(int *a, int *b, int arg)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
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

void	connect(int *a, int *b, int arg, int help)
{
	while (a[0] != help)
	{
		write(1, "ra\n", 3);
		rotate(a);
	}
	while (b[0] != -1)
	{
		write(1, "pa\n", 3);
		push(b, a, arg);
	}
}

int	real_push(int *a, int *b, int arg, int count)
{
	write(1, "pb\n", 3);
	push(a, b, arg);
	count++;
	return (count);
}

void	real_rotate(int *a, int i, int count)
{
	while (count < i)
	{
		write(1, "ra\n", 3);
		rotate(a);
		count++;
	}
}
