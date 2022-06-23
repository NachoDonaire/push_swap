#include "pushswaplib.h"

int	is_sorted(int *a)
{
	int	i;
	int	y;
	int	*dec;

	i = 0;
	y = 1;
	dec = malloc(sizeof(int) * lens(a) + 1);
	while (a[i] != -1)
	{
		dec[i] = dec_converter(a[i]);
		i++;
	}
	dec[i] = -1;
	i = 0;
	while (dec[i] != -1)
	{
		if (dec[y] > dec[i] && dec[y] != -1)
			y++;
		i++;
	}
	if (dec[y] == -1)
		return (1);
	return (0);
}
/*
int	main()
{
	int a[7] = {1, 2, 4, 5, 7,  -1};
	printf("%d", is_sorted(a));
	return (0);
}*/
