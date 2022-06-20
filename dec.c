#include "pushswaplib.h"

int	digits(int a)
{
	int	i;
	int	k;

	i = 0;
	k = a;
	if (k == 1)
		return (1);
	while (k != 0)
	{
		i++;
		k = k / 10;
	}
	return (i);
}


int	dec_converter(int a)
{
	int	i;
	int	amount;
	int	sol;
	int	m;

	sol = 0;
	i = 0;
	m = a;
	amount = digits(a);
	while (i <= amount)
	{
		if (m % 10 != 0 && i == 0)
			sol = sol + 1;
		if (m % 10 != 0 && i != 0)
			sol = sol + pot_ten(2, i);
		i++;
		/*if (m == 1)
			sol = sol + 2 * (i - 1);*/
		m = m / 10;
	}
	return (sol);
}
/*
int main()
{
	int i = 1;
	*int aux;

	aux = bin_converter(i);
	printf("binario: %d\n", aux);
	aux = dec_converter(aux);
	printf("decimal: %d", aux);
	
	printf("%d", digits(i));
	return (0);
}



*/
