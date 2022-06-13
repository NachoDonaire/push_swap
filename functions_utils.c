#include "pushswaplib.h"

void	check_higher(int *a)
{
	if (a[0] > a[1])
	{
		write(1, "ra\n", 3);
		rotate(a);
	}
}

void	check_higher_no_pair(int *a)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (a[i] != -1)
	{
		if (a[i] < a[y])
			y = i;
		i++;
	}
	i = 0;
	while (i < y)
	{
		write(1, "ra\n", 3);
		rotate(a);
		i++;
	}
	if (a[0] > a[1])
	{
		write(1, "sa\n", 3);	
		swap(a);
	}
}
void	touch_chunk(int *chunk)
{
	int	i;

	i = 0;
	while (chunk[i] != -1)
		i++;
	chunk[i - 1] = -1;
}

void	general_push(int *chunk, int *a, int *b, int arg)
{
	int	i;
	int	mid;
	int	y;
	int	count;

	i = 0;
	y = 0;
	count = 0;
	mid = 0;
	while (lens(b) > 2)
	{
		mid = find_chunk_mid(chunk, b, arg);
		while (i < chunk[y])
		{
			if (b[i] > mid)
			{
				while (count < i)
				{
					write(1, "rb\n", 3);
					rotate(b);
					count++;
				}
				i = 0;
				count++;
				write(1, "pb\n", 3);
				push(b, a, arg);
			}
			i++;
			if (count != 0)
				i = 0;
			count = 0;
		}
		i = 0;
		touch_chunk(chunk);
	}
}

void	general_push_no_pair(int *chunk, int *a, int *b, int arg)
{
	int	i;
	int	mid;
	int	y;
	int	count;

	i = 0;
	y = 0;
	count = 0;
	mid = 0;
	while (lens(b) > 3)
	{
		mid = find_chunk_mid(chunk, b, arg);
		while (i < chunk[y])
		{
			if (b[i] > mid)
			{
				while (count < i)
				{
					write(1, "rb\n", 3);
					rotate(b);
					count++;
				}
				i = 0;
				count++;
				write(1, "pb\n", 3);
				push(b, a, arg);
			}
			i++;
			if (count != 0)
				i = 0;
			count = 0;
		}
		i = 0;
		touch_chunk(chunk);
	}
}

void	last_push(int *b, int *a, int arg)
{
	if (b[0] > b[1])
	{
		write(1, "pb\n", 3);	
		push(b, a, arg);
		write(1, "pb\n", 3);	
		push(b, a, arg);
	}
	else
	{
		write(1, "rb\n", 3);
		rotate(b);
		write(1, "pb\n", 3);
		push(b, a, arg);
		write(1, "pb\n", 3);
		push(b, a, arg);
	}
}


