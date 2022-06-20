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
	//printf("//%d//", amount);
	while (ref < amount)
	{
		while (a[i] != -1)
		{
			if (digits(a[i]) == ref)
			{
			if (((a[i] / pot_ten(10, digits(a[i]) - 1)) + 1) % 2 != 0)
			{
				while (count < i)
				{
					write(1, "ra\n", 3);
					rotate(a);
					count++;
				}
				while (count > 0)
				{
					write(1, "rra\n", 4);
					reverse_rotate(a, arg);
					count--;
				}
				write(1, "pa\n", 3);
				push(a, b, arg);
				while (count > 0)
				{
					write(1, "rra\n", 4);
					reverse_rotate(a, arg);
					count--;
				}
				count++;
			}
			}
			if (((a[i] / pot_ten(10, ref)) + 1) % 2 != 0 || digits(a[i]) < ref)
			{
				while (count < i)
				{
					write(1, "ra\n", 3);
					rotate(a);
					count++;
				}
				write(1, "pa\n", 3);
				push(a, b, arg);
				while (count > 0)
				{
					write(1, "rra\n", 4);
					reverse_rotate(a, arg);
					count--;
				}
				count++;
			}
			i++;
			if (count != 0)
				i--;
			count = 0;
		}
		i = 0;
		while (b[0] != -1)
		{
			write(1, "pb\n", 3);
			push(b, a, arg);
		}
		ref++;
	}
}
	
