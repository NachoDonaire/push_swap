#include "pushswaplib.h"

void	check_higher(int *a)
{
	if (a[0] > a[1])
	{
		write(1, "sa\n", 3);
		swap(a);
	}
}

void	check_higher_no_pair(int *a, int arg)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (a[i] != -1)
	{
		if (a[i] > a[y])
			y = i;
		i++;
	}
	i = 0;
	if (y == 0)
	{
		write(1, "ra\n", 3);
		rotate(a);
		check_higher(a);
	}
	else if (y == 1)
	{
		write(1, "rra\n", 4);
		reverse_rotate(a, arg);
		check_higher(a);
	}
	else if (y == 2)
		check_higher(a);
}
void	touch_chunk(int *chunk)
{
	int	i;

	i = 0;
	//rotate(chunk);
	while (chunk[i] != -1)
		i++;
	if (i - 1 >= 0)
		chunk[i - 1] = -1;
}

void	general_push(int *chunk, int *a, int *b, int arg)
{
	treat_chunk(chunk, a, b, arg);
}

int	find_highest_chunk(int *chunk, int *b)
{
	int	y;
	int	i;
	int aux;

	y = 0;
	i = 0;
	while (chunk[y] != -1)
		y++;
	y--;
	while (i < chunk[y])
	{
		if (b[i] > aux)
			aux = b[i];
		i++;
	}
	return (aux);
}



void	treat_chunk(int *chunk, int *a, int *b, int arg)
{
	int	i;
	int	mid;
	int	y;
	int	count;
	int	aux;

	i = 0;
	y = 0;
	aux = 0;
	count = 0;
	mid = 0;
	while (chunk[y] !=  -1)
		y++;
	y--;
	while (chunk[y] >= 0)
	{
		mid = find_chunk_mid(chunk, b, arg);
		while (i < chunk[y])
		{
			printf("//%d//", chunk[y]);
			if (b[i] == find_highest_chunk(chunk, b))
			{
				printf("$%d$", find_highest_chunk(chunk, b));
				aux++;
				while (count < i)
				{
					write(1, "rb\n", 3);
					count++;
					rotate(b);
					aux++;
				}
				write(1, "pb\n", 3);
				push(b, a, arg);
				chunk[y]--;
				while (count > 0)
				{
					write(1, "rrb\n", 4);
					reverse_rotate(b, arg);
					count--;
				}
			}
			if (aux > 0)
				i = 0;
			else
				i++;
			aux = 0;
			/*i++;
			if (aux == 0 && y == 1)
				i = 0;
			if (aux == 0 && y == 1)
				i--;
			aux = 0;
			y = 0;*/
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
	treat_chunk(chunk, a, b, arg);
}

void	last_push_due(int *b, int *a, int arg)
{
	write(1, "pb\n", 3);
	push(b, a, arg);
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

