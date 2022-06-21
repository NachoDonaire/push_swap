/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:50:49 by ndonaire          #+#    #+#             */
/*   Updated: 2022/06/21 12:55:47 by ndonaire         ###   ########.fr       */
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

int	main(int arg, char **args)
{
	int	*a;
	int	*b;
	int	i;
	int	y;
	int	amount;

	a = malloc(sizeof(int) * arg);
	b = malloc(sizeof(int) * arg);
	i = 1;
	y = 0;
	while (args[i])
		a[y++] = ft_atoi(args[i++]);
	a = map(a, arg - 1);
	menos_fill(arg - 1, b);
	i = 0;
	while (a[i] != -1)
	{
		a[i] = bin_converter(a[i]);
		i++;
	}
	amount = amount_digits(a);
	first_bit(a, b, arg);
	general_bit(a, b, arg, amount);
	return (0);
}
