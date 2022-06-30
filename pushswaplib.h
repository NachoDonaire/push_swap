/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswaplib.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndonaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 13:09:17 by ndonaire          #+#    #+#             */
/*   Updated: 2022/06/30 15:30:30 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAPLIB_H
# define PUSHSWAPLIB_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int		ft_atoi(const char *str);
int		find_mid_value(int *a);
void	check_higher(int *a);
void	rotate(int *a);
void	touch_chunk(int *chunk);
void	general_push(int *chunk, int *a, int *b, int arg);
int		lens(int *a);
void	push(int *a, int *b, int arg);
int		find_chunk_mid(int *chunk, int *b, int arg);
void	last_push(int *b, int *a, int arg);
void	general_push_no_pair(int *chunk, int *a, int *b, int arg);
void	check_higher_no_pair(int *a, int arg);
void	swap(int *a);
void	reverse_rotate(int *a, int arg);
void	treat_chunk(int *chunk, int *a, int *b, int arg);
void	last_push_due(int *b, int *a, int arg);
int		bin_converter(int a);
void	first_bit(int *a, int *b, int arg);
int		amount_digits(int *a);
int		pot_ten(int base, int exp);
void	general_bit(int *a, int *b, int arg, int amount);
int		dec_converter(int a);
int		digits(int a);
int		*map(int *a, int arg);
int		check_ref(int *chunk, int refy, int arg);
void	desmap(int *a, int *chunk, int arg);
void	aux_push(int *b, int *aux);
void	connect(int *a, int *b, int arg, int help, int ref);
int		real_push(int *a, int *b, int arg, int count);
void	general_bit_bucle(int *a, int *b, int arg, int ref);
void	real_rotate(int *a, int i, int count, int arg);
int		find_first_to_rotate(int *a, int ref);
void	first_bit_bucle(int *a, int *b, int arg);
int		refy_zero(int *chunk, int arg);
int		no_repeat(int *a);
int		is_sorted(int *a);
int		digits_bin(int a);
int		lil_free(int y, int *dec);
void	push_swap(int *a, int *b, int arg);
int		error_check(int *a, int *b);
void	menos_fill(int arg, int *b);
int		find_mid_value(int *a);
void	push_high_mid(int *a, int *b, int arg, int mid);
void	b_empty(int *b, int *a, int arg);
void	less_five(int *a, int *b, int arg);
void	plus_than_half(int *a, int arg, int i);
int		num_check(char	**args, int arg);
int		finder(char *s, char *coin);
int		is_max(char **args, int arg);
int		lensy(char *s);
void	sort_a(int *a, int arg);
int		is_sorted_dec(int *a);
void	check_b(int *a, int *b, int arg, int ref);
int	number_push(int *a, int ref);

#endif
