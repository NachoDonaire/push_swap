#include "pushswaplib.h"


void	push(int *a, int *b)
{
	int i;
	int y;

	i = 0;
	y = 0;
	while (b[i] != -1)
	{
		b[i + 1] = b[i];
		i++;
	}
	b[0] = a[0];
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
	int *aux;

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

void	menos_fill(int arg, int *b)
{
	int i;

	i = 0;
	while (i < arg)
		b[i++] = -1;
}

int		*map(int	*a, int arg)
{
	int i;
	int y;
	int	pos;
	int	*sol;

	i = 0;
	y = 0;
	pos = 0;
	sol = malloc(sizeof(int) * (arg + 1));
	while (y < arg && i < arg)
	{
		if (a[i] > a[y])
			pos++;
		y++;
		if (y == arg)
		{
			sol[i] = pos;
			y = 0;
			i++;
			pos = 0;
		}
	}
	sol[i] = -1; 
	return (sol);
}


int main(int arg, char **args)
{
	int *a;
	int	*b;
	int i;
	int y;

	a = malloc(sizeof(int) * arg);
	b = malloc(sizeof(int) * arg - 1);
	i = 1;
	y = 0;
	while (args[i])
	{
		a[y++] = ft_atoi(args[i]);
		i++;
	}
	a = map(a, arg - 1);
	menos_fill(arg - 1, b);
	reverse_rotate(a, arg - 1);
	i = 0;
	while (a[i] != -1)
		printf("%d", a[i++]);
	return (0);
}


	

