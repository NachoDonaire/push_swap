#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
void	reverse_rotate(int a[])
{
	int	i;
	int	u;
	int	*sol;

	i = 0;
	while ((char)(a)[i])
		i++;
	sol = malloc(sizeof(int) * (i + 1));
	i = 0;
	u = 1;
	while ((char)(a)[i])
	{
		sol[u++] = a[i++];
	}
	sol[0] = a[i - 1];
	sol[u - 1] = '\0';
	i = 0;
	while ((char)(sol[i]))
	{
		a[i] = sol[i];
		i++;
	}
}

void	reverse_rotate_both(int a[], int b[])
{
	reverse_rotate(a);
	reverse_rotate(b);
}

void	rotate(int a[])
{
	int	i;
	int	y;
	int	*sol;

	i = 0;
	while ((char)(a)[i])
		i++;
	sol = malloc(sizeof(int) * (i + 1));
	i = 1;
	y = 0;
	while ((char)(a)[i])
	{
		sol[y++] = a[i++];
	}
	sol[y++] = a[0];
	sol[y] = '\0';
	y = 0;
	while ((char)(sol[y]))
	{
		a[y] = sol[y];
		y++;
	}
}

void	rotate_both(int a[], int b[])
{
	rotate(a);
	rotate(b);
}

int main()
{
	int a[54] = {1, 2, 3, 4};
	int b[54] = {4, 3, 2, 1};
	int i;
	i = 0;
	reverse_rotate_both(a, b);
	while (b[i])
		printf("%d", b[i++]);
	return (0);
}


	
