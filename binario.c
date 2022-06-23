/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binario.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:37:54 by ndonaire          #+#    #+#             */
/*   Updated: 2022/06/21 11:38:46 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

int	bin_converter(int a)
{
	int		ref;
	int		count;
	char	*sol;

	count = 0;
	ref = a;
	while (ref > 0)
	{
		ref = ref / 2;
		count++;
	}
	sol = malloc(sizeof(char) * (count + 1));
	ref = a;
	count--;
	while (ref > 0)
	{
		sol[count] = (ref % 2) + 48;
		ref = ref / 2;
		count--;
	}
	ref = ft_atoi(sol);
	free(sol);
	return (ref);
}
