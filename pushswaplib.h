# ifndef PUSHSWAPLIB_H
#define PUSHSWAPLIB_H
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void    reverse_rotate(int arg, int a[]);
void    reverse_rotate_both(int arg, int a[], int b[]);
void    rotate(int arg, int a[]);
//void    rotate_both(int a[], int b[]);
void    swap(int a[FOPEN_MAX]);
void    swap_both(int a[], int b[]);
void    push(int a[FOPEN_MAX], int b[FOPEN_MAX]);
int     ft_atoi(const char *str);

#endif
