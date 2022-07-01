/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   few_nums.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 09:05:29 by ndonaire          #+#    #+#             */
/*   Updated: 2022/07/01 10:26:00 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

int	find_mid_value(int *a)
{
	int	mid;
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (a[i] != -1)
	{
		if (a[i] > a[y])
			y = i;
		i++;
	}
	mid = a[y] / 2;
	return (mid);
}

void	push_high_mid(int *a, int *b, int arg, int mid)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (a[i] != -1)
	{
		if (is_sorted(a) == 1 && lens(a) == arg)
			return ;
		if (a[i] < mid)
		{
			real_rotate(a, i, count, arg);
			if (is_sorted(a) == 1 && lens(a) == arg)
				return ;
			count = real_push(a, b, arg, count);
		}
		i++;
		if (count != 0)
			i = 0;
		count = 0;
	}
}

void	plus_than_half(int *a, int arg, int i)
{
	int	aux;

	aux = a[i];
	while (a[0] != aux)
	{
		write(1, "rra\n", 4);
		reverse_rotate(a, arg);
	}
}

void	b_empty(int *b, int *a, int arg)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (b[i] != -1)
	{
		if (b[i] >= 1)
			count = a_while_for_b(b, i, arg, a);
		i++;
		if (count != 0)
			i = 0;
		count = 0;
	}
	i = 0;
	while (b[i] != -1)
	{
		write(1, "pa\n", 3);
		push(b, a, arg);
	}
}

void	less_five(int *a, int *b, int arg)
{
	int	mid;

	mid = find_mid_value(a);
	push_high_mid(a, b, arg, mid);
	sort_a(a, arg);
	b_empty(b, a, arg);
}
