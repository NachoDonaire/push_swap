/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:55:51 by ndonaire          #+#    #+#             */
/*   Updated: 2022/06/30 17:25:22 by ndonaire         ###   ########.fr       */
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
