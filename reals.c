/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reals.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 10:21:42 by ndonaire          #+#    #+#             */
/*   Updated: 2022/07/01 10:27:58 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

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
			count++;
		}
	}
}
