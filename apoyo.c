#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "pushswaplib.h"

int lens(int a[])
{
	int i;

	i = 0;
	while (a[i])
		i++;
	return (i);
}

void	reverse_rotate(int arg, int a[])
{
	int	i;
	int	u;
	int	sol[arg];

	i = 0;
	i = 0;
	u = 1;
	while (i < arg)
	{
		sol[u++] = a[i++];
	}
	sol[0] = a[i - 1];
	sol[u - 1] = '\0';
	i = 0;
	while (i < arg)
	{
		a[i] = sol[i];
		i++;
	}
}

void	reverse_rotate_both(int arg, int a[], int b[])
{
	reverse_rotate(arg, a);
	reverse_rotate(arg, b);
}

void	rotate(int arg, int a[])
{
	int	y;
	int	sol[arg];
	int	aux;
	int	pos;

	aux = a[0];
	pos = 1;
	y = 0;
	while (pos < arg)
	{
		sol[y++] = a[pos++];
	}
	sol[y] = aux;
	y = 0;
	while (y < arg)
	{
		a[y] = sol[y];
		y++;
	}
}
/*
void	rotate_both(int a[], int b[])
{
	rotate(a);
	rotate(b);
}
*/
void    swap(int a[FOPEN_MAX])
{
        int i;

        i = a[0];
        a[0] = a[1];
        a[1] = i;
}

void	swap_both(int a[], int b[])
{
	swap(a);
	swap(b);
}

void	push(int arg, int a[], int b[])
{
        int i;
        int aux[arg + 1];
        int aux_off;
	int re_aux[arg - 1];

        aux[0] = a[0];
        i = 1;
	aux_off = 0;
        while (i < lens(b) + 1)
        {
                aux[i++] = b[aux_off++];
        }
        i = 0;
        while (i < lens(b) + 1)
        {
                b[i] = aux[i];
                i++;
        }
	i = 1;
	while (i < lens(a) - 1)
	{
		re_aux[i - 1] = a[i];
		i++;
	}
	i = 0;
	while (i < lens(a) - 1)
	{
		a[i] = re_aux[i];
		i++;
	}
	a[i] = '\0';

}

int	find_mid_value(int arg, int a[arg])
{
	int	i;
	int	y;
	int	max;
	int	min;

	i = 0;
	y = 0;
	while (i < arg)
	{
		if (a[y] > a[i])
			y = i;
		i++;
	}
	min = a[y];
	i = 0;
	y = 0;
	while (i < arg)
	{
		if (a[y] < a[i])
			y = i;
		i++;
	}
	max = a[y];

//	printf("--max%d--", max);
//	printf("--min%d--", min);
	i = (max + min) / 2;
	if (i % 2 != 0)
		i++;
	return (i);
}

void first_push(int arg, int a[arg], int b[arg])
{
	int	i;
	int	mid;
	int	count;

	i = 0;
	count = 0;
	mid = find_mid_value(arg - 1, a);
	while (a[i] != -1)
	{
		if (a[i] < mid)
		{
			while (count <= i)
			{
				write(1, "r\n", 2);
				rotate(a);
				count++;
			}
			count = 0;
			i = 0;
			write(1, "p\n", 2);
			push(a, b);
		}




int main(int arg, char **args)
{
	int *a;
	int b[arg - 1];
	int i;
	int y;
	//int mid;
	
	i = 0;
	y = 1;
	a = malloc(sizeof(int) * (arg - 1));
	while (i < arg - 1)
	{
		a[i] = ft_atoi(args[y]);
		i++;
		y++;
	}
	//first_push(arg - 1, a, b, mid);
	//push(arg - 1, a, b);
	//rotate(arg - 1, a);
	i = 0;
	while (i < arg - 1)
	{
		printf("%d", a[i++]);
	}
	return (0);
}


	
