/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 09:55:36 by ndonaire          #+#    #+#             */
/*   Updated: 2022/06/29 15:57:14 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswaplib.h"

void	swap(int *a)
{
	int	aux;

	aux = a[0];
	a[0] = a[1];
	a[1] = aux;
}

void	push(int *a, int *b, int arg)
{
	int	i;
	int	*aux;

	aux = malloc(sizeof(int) * arg);
	aux[0] = a[0];
	aux_push(b, aux);
	i = 0;
	while (aux[i] != -1)
	{
		b[i] = aux[i];
		i++;
	}
	b[i] = -1;
	free(aux);
	i = 0;
	while (a[i] != -1)
	{
		a[i] = a[i + 1];
		i++;
	}
}

void	rotate(int *a)
{
	int	i;
	int	aux;

	i = 0;
	aux = a[0];
	while (a[i] != -1)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[i - 1] = aux;
	a[i] = -1;
}

void	reverse_rotate(int *a, int arg)
{
	int	i;
	int	*aux;

	aux = malloc(sizeof(int) * arg);
	i = 0;
	while (a[i] != -1)
	{
		aux[i] = a[i];
		i++;
	}
	i = 1;
	while (a[i] != -1)
	{
		a[i] = aux[i - 1];
		i++;
	}
	a[0] = aux[i - 1];
	a[i] = -1;
}

void	rotate_both(int *a, int *b)
{
	rotate(a);
	rotate(b);
}
