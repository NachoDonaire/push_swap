/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:55:51 by ndonaire          #+#    #+#             */
/*   Updated: 2022/07/26 20:18:26 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

void	aux_push(int *b, int *aux)
{
	int	i;

	i = 0;
	while (b[i] != -1)
	{
		aux[i + 1] = b[i];
		i++;
	}
	aux[i + 1] = -1;
}

int	a_while_for_b(int *b, int i, int arg, int *a)
{
	int	count;

	count = 0;
	while (count < i)
	{
		write(1, "rb\n", 3);
		rotate(b);
		count++;
	}
	write(1, "pa\n", 3);
	push(b, a, arg);
	return (count);
}

int	less_five_main(int *a, int *b, int arg)
{
	less_five(a, b, arg - 1);
	return (0);
}

void	bin_conversion(int *a)
{
	int	i;

	i = 0;
	while (a[i] != -1)
	{
		a[i] = bin_converter(a[i]);
		i++;
	}
}

void	b_bucle(int help, int *b)
{
	while (b[0] != help)
	{
		write(1, "rb\n", 3);
		rotate(b);
	}
}
