#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "pushswaplib.h"
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

void    push(int a[FOPEN_MAX], int b[FOPEN_MAX])
{
        int i;
        int aux[FOPEN_MAX];
        int aux_off;

        aux[0] = a[0];
        i = 1;
        while ((char)(b[i]) != '\0')
        {
                aux[i++] = b[aux_off++];
        }
        i = 0;
        while ((char)(aux[i]))
        {
                b[i] = aux[i];
                i++;
        }
}

int main(int arg, char **args)
{
	int a[arg - 1];
	//int b[FOPEN_MAX];
	int i;
	int y;
	
	i = 0;
	y = 1;
	while (i < arg - 1)
	{
		a[i] = ft_atoi(args[y]);
		i++;
		y++;
	}
	//int b[5] = {3, 1, 4, 5, 6};
	i = 0;
	y = 1;
	//reverse_rotate(arg - 1, a);
	//rotate(a);
	//rotate(a);
	while (y < arg - 1)
	{
		if (a[y] < a[i])
			i = y;
		y++;
	}
	if (i <= ((arg - 1) / 2))
	{
		while (i > 0)
		{
			write(1, "r\n", 2);
			rotate(arg - 1, a);
			i--;
		}
	}
	else if (i > ((arg - 1) / 2))
	{
		while (i < arg - 1)
		{
			write(1, "rr\n", 3);
			reverse_rotate(arg - 1, a);
			i++;
		}
	}
	i = 0;
	while (i < arg - 1)
	{
		printf("%d\n", a[i++]);
	}	
	return (0);
}


	
