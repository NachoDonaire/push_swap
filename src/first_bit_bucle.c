/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_bit_bucle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 13:08:18 by ndonaire          #+#    #+#             */
/*   Updated: 2022/07/26 20:16:24 by ndonaire         ###   ########.fr       */
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
	while (a[i] != -1 && n_push > 0)
	{
		if ((a[i] + 1) % 2 != 0)
		{
			real_rotate(a, i, count, arg);
			write(1, "pb\n", 3);
			push(a, b, arg);
			count++;
		}
		i++;
		if (count != 0)
			i = 0;
		count = 0;
	}
}
