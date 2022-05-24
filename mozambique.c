#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

void	swap(int a[FOPEN_MAX])
{
	int i;

	i = a[0];
	a[0] = a[1];
	a[1] = i;
}

void	push(int a[FOPEN_MAX], int b[FOPEN_MAX])
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

void	rotate(int a[FOPEN_MAX])
{
	int	z[FOPEN_MAX];
	int 	i;

	i = 1;
	z[0] = 1;
	while ((char)(a[i]) != '\0')
	{
		z[i] = a[i - 1];
		i++;
	}
	z[0] = a[i - 1];
	z[i] = '\0';
	i = 0;
	while ((char)(z[i]) != '\0')
	{
		a[i] = z[i];
		i++;
	}
}

int main(int arg, char **args)
{
/*	int i;
	int y;
	int a[OPEN_MAX];
	int b[OPEN_MAX];

	i = 1;
	y = 0;
	while (i < arg)
		a[y++] = args[i++][0];
*/

	int i;
	int t[FOPEN_MAX] = {1, 2, 3, 4, 3, 2};
	int n[FOPEN_MAX] = {2, 3, 4};

	i = 0;
	push(n, t);
	while (i < 6)
	{
		printf("%d", t[i++]);
	}
	printf("\n");
	rotate(t);
	i = 0;
	while (i < 6)
		printf("%d", t[i++]);
	return (0);
}

