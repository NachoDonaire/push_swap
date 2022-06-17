#include "pushswaplib.h"

int	lens(int *a)
{
	int	i;

	i = 0;
	while (a[i] != -1)
		i++;
	return (i);
}

void	swap(int *a)
{
	int	aux;
	aux = a[0];
	a[0] = a[1];
	a[1] = aux;
}

void	push(int *a, int *b, int arg)
{
	int i;
	int *aux;

	//write(1, "--db--", 6);
	//write(2, &i, 1);
	aux = malloc(sizeof(int) * arg);
	i = 0;
	aux[0] = a[0];
	while (b[i] != -1)
	{
		aux[i + 1] = b[i];
		i++;
	}
	aux[i + 1] = -1;
	i = 0;
	while (aux[i] != -1)
	{
		b[i] = aux[i];
		i++;
	}
	b[i] = -1;
	free(aux);
	i = 0;
	while (a[i] != -1)
	{
		a[i] = a[i + 1];
		i++;
	}
}

void	rotate(int *a)
{
	int	i;
	int	aux;

	i = 0;
	aux = a[0];
	while (a[i] != -1)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[i - 1] = aux;
	a[i] = -1;
}

void	reverse_rotate(int *a, int arg)
{
	int	i;
	int *aux;

	aux = malloc(sizeof(int) * arg);
	i = 0;
	while (a[i] != -1)
	{
		aux[i] = a[i];
		i++;
	}
	i = 1;
	while (a[i] != -1)
	{
		a[i] = aux[i - 1];
	   i++;
	}
	a[0] = aux[i - 1];
	a[i] = -1;
}

void	rotate_both(int *a, int *b)
{
	rotate(a);
	rotate(b);
}

void	menos_fill(int arg, int *b)
{
	int i;

	i = 0;
	while (i < arg)
		b[i++] = -1;
}

int		*map(int	*a, int arg)
{
	int i;
	int y;
	int	pos;
	int	*sol;

	i = 0;
	y = 0;
	pos = 0;
	sol = malloc(sizeof(int) * (arg + 1));
	while (y < arg && i < arg)
	{
		if (a[i] > a[y])
			pos++;
		y++;
		if (y == arg)
		{
			sol[i] = pos;
			y = 0;
			i++;
			pos = 0;
		}
	}
	sol[i] = -1; 
	return (sol);
}


int	find_mid_value(int *a)
{
	int	i;
	int	y;
	int	min;
	int	max;

	i = 0;
	y = 0;
	while (a[i] != -1)
	{
		if (a[i] < a[y])
			y = i;
		i++;
	}
	min = a[y];
	i = 0;
	y = 0;
	while (a[i] != -1)
	{
		if (a[i] > a[y])
			y = i;
		i++;
	}
	max = (min + a[y]) / 2;
	return (max);
}

int	first_push(int arg, int *a, int *b)
{
        int     i;
        int     mid;
        int     count;
	int	chunk;

        i = 0;
        count = 0;
	chunk = 0;
        mid = find_mid_value(a);
        while (a[i] != -1)
        {
                if (a[i] < mid)
                {
                        while (count < i)
                        {
                                write(1, "ra\n", 3);
                                rotate(a);
                                count++;
                        }
                        i = 0;
			count++;
                        write(1, "pa\n", 3);
                        push(a, b, arg);
			chunk++;
                }
		i++;
		if (count != 0)
			i = 0;
		count = 0;
	}
	return (chunk);
}

int	find_chunk_mid(int *chunk, int *b, int arg)
{
	int	i;
	int	y;
	int	*aux;
	int	mid;
	int	re_chunk;

	i = 0;
	y = 0;
	aux = malloc(sizeof(int) * (arg));
	/*while (chunk[i] != -1)
		i++;
	i--;*/
	re_chunk = chunk[i];
	while (re_chunk >= 0)
	{
		aux[y] = b[y];
		y++;
		re_chunk--;
	}
	aux[y] = -1;
	mid = find_mid_value(aux);
	free(aux);
	return (mid);
}

/*
int main(int arg, char **args)
{
	int *a;
	int	*b;
	int i;
	int y;
	int	amount;
	int	*chunk;

	a = malloc(sizeof(int) * arg);
	b = malloc(sizeof(int) * arg);
	chunk = malloc(sizeof(int) * arg);
	i = 1;
	y = 0;
	while (args[i])
	{
		a[y++] = ft_atoi(args[i]);
		i++;
	}
	a = map(a, arg - 1);
	amount = amount_digits(a);
	i = 0;
//	while (a[i] != -1)
//		printf("%d", a[i++]);
	menos_fill(arg - 1, b);
	menos_fill(arg - 1, chunk);
	i = 0;
	y = 0;
	while (a[i] != -1)
	{
		a[i] = bin_converter(a[i]);
		i++;
	}
	first_bit(a, b, arg);
	general_bit(a, b, arg, amount);
//	printf("--%d--", find_mid_value(a));
	while (lens(a) > 2 && (arg - 1) % 2 == 0)
		chunk[y++] = first_push(arg, a, b);
	while (lens(a) > 3 && (arg - 1) % 2 == 1)
		chunk[y++] = first_push(arg, a, b);
		y = 0;
		printf("//%d//", arg - 1);
	while (chunk[y] != -1)
		printf("//%d//", chunk[y++]);
	*//*
	y--;
	touch_chunk(chunk);
	y--;
	printf("--%d--", chunk[y]);
	
	
	if ((arg - 1) % 2 == 0)
	{
		check_higher(a);
		general_push(chunk, a, b, arg);
		last_push_due(b, a, arg);
		//last_push(b, a, arg);
	}
	else
	{
		check_higher_no_pair(a, arg);
		general_push_no_pair(chunk, a, b, arg);
		last_push_due(b, a, arg);
		//last_push(b, a, arg);
	}
	//reverse_rotate(a, arg);*/
	//i = 0;
	/*while (a[i] != -1)
	{
		a[i] = dec_converter(a[i]);
		i++;
	}
	i = 0;
	while (a[i] != -1)
		printf("%d\n", a[i++]);

	return (0);
}*/


	

