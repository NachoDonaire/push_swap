#include "pushswaplib.h"

int	no_repeat(int *a)
{
	int	i;
	int	y;

	i = 1;
	y = 0;
	while (a[y] != -1)
	{
		while (a[i] != -1)
		{
			if (a[y] == a[i])
				return (1);
			i++;
		}
		y++;
		i = y + 1;
	}
	return (0);
}
/*
int main()
{
	int a[4] = {3, 2, 0, -1};
	printf("%d", no_repeat(a));
	return (0);
}
*/
	
