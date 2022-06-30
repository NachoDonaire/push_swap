/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:25:55 by ndonaire          #+#    #+#             */
/*   Updated: 2022/06/30 17:22:44 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

int	main(int arg, char **args)
{
	int	*a;
	int	*b;
	int	i;
	int	y;

	if (arg == 1)
		return (0);
	b = malloc(sizeof(int) * arg);
	i = 1;
	y = 0;
	while (args[i])
		b[y++] = ft_atoi(args[i++]);
	a = map(b, arg - 1);
	if (no_repeat(a) == 1 || num_check(args, arg) == 1 || is_max(args, arg) == 1)
		return (error_check(a, b));
	menos_fill(arg - 1, b);
/*	if (arg <= 6 && is_sorted(a) != 1)
	{
		less_five(a, b, arg - 1);
		return (0);
	}*/
	i = 0;
	while (a[i] != -1)
	{
		a[i] = bin_converter(a[i]);
		i++;
	}
	i = 0;
/*	while (a[i] != -1)
		printf("%d\n", a[i++]);
*/	
	push_swap(a, b, arg);
	return (0);
}
