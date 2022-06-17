#include "pushswaplib.h"

void	first_bit(int *a, int *b, int arg)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (a[i] != -1)
	{
		if ((a[i] + 1) % 2 != 0)
		{
			while (count < i)
			{
				write(1, "ra\n", 3);
				rotate(a);
				count++;
			}
			write(1, "pa\n", 3);
			push(a, b, arg);
		}
		i++;
		if (count != 0)
			i = 0;
		count = 0;
	}
	while (b[0] != -1)
	{
		write(1, "pb\n", 3);
		push(b, a, arg);
	}
}


void	general_bit(int *a, int *b, int arg, int amount)
{
	int	i;
	int	count;
	int	ref;

	i = 0;
	count = 0;
	ref = 1;
	while (ref < amount)
	{
		while (a[i] != -1)
		{
			if (((a[i] / pot_ten(10, ref)) + 1) % 2 != 0)
			{
				while (count < i)
				{
					write(1, "ra\n", 3);
					rotate(a);
					count++;
				}
				write(1, "pa\n", 3);
				push(a, b, arg);
			}
			i++;
			if (count != 0)
				i = 0;
			count = 0;
		}
		while (b[0] != -1)
		{
			write(1, "pb\n", 3);
			push(b, a, arg);
		}
		ref++;
	}
}
	
