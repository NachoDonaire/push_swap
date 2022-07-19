/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 10:15:36 by ndonaire          #+#    #+#             */
/*   Updated: 2022/07/19 19:37:29 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

int	find_max(int *a)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (i < lens(a))
	{
		if (a[i] > a[y])
			y = i;
		i++;
	}
	return (y);
}

void	sort_a(int *a, int arg)
{
	int	y;

	if (is_sorted_dec(a) == 1)
		return ;
	y = find_max(a);
	if (y != lens(a) - 1)
	{
		while (y < lens(a) - 1)
		{
			write(1, "rra\n", 4);
			reverse_rotate(a, arg);
			y++;
		}
	}
	if (lens(a) == 3 && is_sorted_dec(a) == 0)
	{
		write(1, "sa\n", 3);
		swap(a);
	}
}

int	sortieo(int *a, int *b, int arg)
{
	sort_a(a, arg);
	free(a);
	free(b);
	return (0);
}
