/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:50:49 by ndonaire          #+#    #+#             */
/*   Updated: 2022/08/02 13:01:02 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

int	lens(int *a)
{
	int	i;

	i = 0;
	while (a[i] != -1)
		i++;
	return (i);
}

void	menos_fill(int arg, int *b)
{
	int	i;

	i = 0;
	while (i < arg)
		b[i++] = -1;
}

int	*map(int	*a, int arg)
{
	int	i;
	int	y;
	int	pos;
	int	*sol;

	i = 0;
	y = 0;
	pos = 0;
	sol = malloc(sizeof(int) * (arg + 1));
	while (y < arg && i < arg)
	{
		if (a[i] > a[y])
			pos++;
		y++;
		if (y == arg)
		{
			sol[i] = pos;
			y = 0;
			i++;
			pos = 0;
		}
	}
	sol[i] = -1;
	return (sol);
}

int	error_check(int *a, int *b)
{
	free(b);
	free(a);
	write(1, "Error\n", 5);
	return (0);
}

void	push_swap(int *a, int *b, int arg)
{
	int	amount;

	if (is_sorted(a) == 1)
		return ;
	amount = amount_digits(a);
	first_bit(a, b, arg);
	general_bit(a, b, arg, amount);
	free(a);
	free(b);
}
