/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_bit_bucle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 13:08:18 by ndonaire          #+#    #+#             */
/*   Updated: 2022/06/21 13:08:33 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

void	first_bit_bucle(int *a, int *b, int arg)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (a[i] != -1)
	{
		if ((a[i] + 1) % 2 != 0)
		{
			while (count < i)
			{
				write(1, "ra\n", 3);
				rotate(a);
				count++;
			}
			write(1, "pb\n", 3);
			push(a, b, arg);
		}
		i++;
		if (count != 0)
			i = 0;
		count = 0;
	}
}
