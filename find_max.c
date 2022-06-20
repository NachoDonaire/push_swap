#include "pushswaplib.h"

int	amount_digits(int *a)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (a[i] != -1)
	{
		if (digits(a[i]) > digits(a[y]))
			y = i;
		i++;
	}
	//bin = bin_converter(a[y]);
/*	bin = a[y];
	i = 0;
	while (bin / 10 != 0)
	{
		i++;
		bin = bin / 10;
	}*/
	return (digits(a[y]));
}

int	pot_ten(int base, int exp)
{
	int i;
	int	sol;

	i = 0;
	sol = 1;
	if (exp == 0)
		return (1);
	while (i < exp)
	{
		sol = sol * base;
		i++;
	}
	return (sol);
}

/*
int main()
{
	int *d;
	int y;

	d = malloc(sizeof(int) * 4);
	d[0] = 23;
	d[1] = 2;
	d[3] = -1;
	y = 23;
	y = bin_converter(y);
	printf("--%d--", y);
	y = amount_digits(d);
	printf("%d", y);
	
	printf("%d", pot_ten(4));
}*/

	
