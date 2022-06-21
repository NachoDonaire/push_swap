/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:43:34 by ndonaire          #+#    #+#             */
/*   Updated: 2022/06/21 12:44:10 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

int	digits(int a)
{
	int	i;
	int	k;

	i = 0;
	k = a;
	if (k == 1)
		return (1);
	while (k != 0)
	{
		i++;
		k = k / 10;
	}
	return (i);
}

int	dec_converter(int a)
{
	int	i;
	int	amount;
	int	sol;
	int	m;

	sol = 0;
	i = 0;
	m = a;
	amount = digits(a);
	while (i <= amount)
	{
		if (m % 10 != 0 && i == 0)
			sol = sol + 1;
		if (m % 10 != 0 && i != 0)
			sol = sol + pot_ten(2, i);
		i++;
		m = m / 10;
	}
	return (sol);
}
