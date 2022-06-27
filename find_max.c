/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:53:10 by ndonaire          #+#    #+#             */
/*   Updated: 2022/06/27 18:05:30 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

int	amount_digits(int *a)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (a[i] != -1)
	{
		if (digits(a[i]) > digits(a[y]))
			y = i;
		i++;
	}
	return (digits(a[y]));
}

int	pot_ten(int base, int exp)
{
	int	i;
	int	sol;

	i = 0;
	sol = 1;
	if (exp == 0)
		return (1);
	while (i < exp)
	{
		sol = sol * base;
		i++;
	}
	return (sol);
}
