/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_bit_bucle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 13:08:18 by ndonaire          #+#    #+#             */
/*   Updated: 2022/06/30 17:24:13 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

void	first_bit_bucle(int *a, int *b, int arg)
{
	int	i;
	int	count;
	int	n_push;

	count = 0;
	i = 0;
	n_push = number_push(a, 0);
	if (is_sorted(a) == 1)
		return ;
	while (a[i] != -1 &&  n_push > 0)
	{
		if ((a[i] + 1) % 2 != 0)
		{
		//	real_rotate(a, i, count, arg);
			if (i > lens(a) / 2)
			{
				while (i < lens(a))
				{
					write(1, "rra\n", 4);
					reverse_rotate(a, arg);
					i++;
					count++;
				}
			}
			else if (i <= lens(a) / 2)
			{
				while (count < i)
				{
					write(1, "ra\n", 3);
					rotate(a);
					count++;
				}
			}
			/*
			while (count < i)
			{
				write(1, "ra\n", 3);
				rotate(a);
				count++;
			}*/
			write(1, "pb\n", 3);
			push(a, b, arg);
	//		n_push--;
		}
		i++;
		if (count != 0)
			i = 0;
		count = 0;
	}
}
