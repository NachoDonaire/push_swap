# ifndef PUSHSWAPLIB_H
#define PUSHSWAPLIB_H
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

//void    reverse_rotate(int arg, int a[]);
//void    reverse_rotate_both(int arg, int a[], int b[]);
//void    rotate(int arg, int a[]);
//void    rotate_both(int a[], int b[]);
//void    swap(int a[FOPEN_MAX]);
//void    swap_both(int a[], int b[]);
//void    push(int a[FOPEN_MAX], int b[FOPEN_MAX]);
int     ft_atoi(const char *str);
int	find_mid_value(int *a);
void	check_higher(int *a);
void	rotate(int *a);
void	touch_chunk(int *chunk);
void	general_push(int *chunk, int *a, int *b, int arg);
int	lens(int *a);
void    push(int *a, int *b, int arg);
int     find_chunk_mid(int *chunk, int *b, int arg);
void	last_push(int *b, int *a, int arg);
void	general_push_no_pair(int *chunk, int *a, int *b, int arg);
void	check_higher_no_pair(int *a);
void	swap(int *a);


#endif
