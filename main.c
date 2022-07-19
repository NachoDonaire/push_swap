/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:25:55 by ndonaire          #+#    #+#             */
/*   Updated: 2022/07/19 19:38:28 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

int	nnum(char **args)
{
	int		i;
	int		y;
	int		count;
	char	**rec;

	i = 1;
	y = 0;
	count = 0;
	while (args[i])
	{
		rec = ft_split(args[i], ' ');
		while (rec[y])
		{
			count++;
			free(rec[y]);
			y++;
		}
		free(rec);
		y = 0;
		i++;
	}
	return (count + 1);
}

int	*extra_err(int *b, int pos)
{
	b[pos] = -1;
	return (b);
}

int	*gest_err(char **args)
{	
	int		i;
	int		y;
	int		pos;
	int		*b;
	char	**rec;

	i = 1;
	y = 0;
	b = malloc(sizeof(int) * nnum(args));
	pos = 0;
	while (args[i])
	{
		rec = ft_split(args[i], ' ');
		while (rec[y])
		{
			b[pos] = ft_atoi(rec[y]);
			free(rec[y]);
			pos++;
			y++;
		}
		y = 0;
		i++;
		free(rec);
	}
	return (extra_err(b, pos));
}

int	check_is_sorted(int *a, int *b)
{
	bin_conversion(a);
	if (is_sorted(a) == 1)
	{
		dec_conversion(a);
		free(a);
		free(b);
		return (1);
	}
	else
	{
		dec_conversion(a);
		return (0);
	}
}

void	leaks(void)
{
	system("leaks push_swap");
}

int	main(int arg, char **args)
{
	int	*a;
	int	*b;
	int	nnumy;

	atexit(leaks);
	if (arg == 1)
		return (0);
	b = gest_err(args);
	nnumy = nnum(args);
	a = map(b, nnumy - 1);
	if (no_repeat(a) == 1 || num_check(args, nnumy) == 1)
		return (error_check(a, b));
	if (is_max(args, nnumy) == 1)
		return (error_check(a, b));
	if (check_is_sorted(a, b) == 1)
		return (0);
	if (nnumy <= 4)
		return (sortieo(a,b,  nnumy));
	menos_fill(nnumy - 1, b);
	if (nnumy <= 6 && is_sorted(a) != 1)
		return (less_five_main(a, b, nnumy));
	bin_conversion(a);
	push_swap(a, b, nnumy);
	return (0);
}
