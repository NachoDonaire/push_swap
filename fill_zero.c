#include "pushswaplib.h"

void	fill_left_zero(int *a)
{
	int		i;
	char	*k;
	int		amount;
	int		y;
	int		aux;

	i = 0;
	y = 0;
	amount = amount_digits(a);
	printf("--%d--", amount);
	k = malloc(sizeof(char) * (amount + 1));
	while (a[i] != -1)
	{
		if (digits(a[i]) < amount)
		{
			aux = amount - digits(a[i]);
			while (aux > 0)
			{
				k[y++] = 48;
				aux--;
			}
			aux = a[i];
			while (aux > 0)
			{
				k[y++] = (aux % 10) + 48;
				aux = aux / 10;
			}
			k[y] = '\0';
			printf("//%s//", k);
			a[i] = ft_atoi(k);
			printf("$$%d$$", a[i]);
		}
		y = 0;
		i++;
	}
}

int main()
{
	int *a;
	int	i;

	i = 0;
	a = malloc(sizeof(int) * 5);
	a[0] = 1;
	a[1] = 23;
	a[2] = 45;
	a[3] = 13;
	a = map(a, 4);
	i = 0;
	while (a[i] != -1)
	{
		a[i] = bin_converter(a[i]);
		i++;
	}
	fill_left_zero(a);
	i = 0;
	while (a[i] != -1)
		printf("%d\n", a[i++]);
	return (0);
}




	

