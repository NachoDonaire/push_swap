#include "pushswaplib.h"


int	bin_converter(int a)
{
	int ref;
	int	count;
	char *sol;

	count = 0;
	ref = a;
	while (ref > 0)
	{
		ref = ref / 2;
		count++;
	}
	sol = malloc(sizeof(char) * (count + 1));
	ref = a;
	count--;
	while (ref > 0)
	{
		sol[count] = (ref % 2) + 48;
		//write(1, &sol[count], 1);
		ref = ref / 2;
		count--;
	}
	ref = ft_atoi(sol);
	return (ref);
}
/*
int main()
{
	int k;

	k = 36;
	k = bin_converter(k);
	printf("%d", k);
}*/
