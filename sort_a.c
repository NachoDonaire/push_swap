#include "pushswaplib.h"

void	sort_a(int *a, int arg)
{
	int	i;
	int	y;

	if (is_sorted(a) == 1)
		return ;
	i = 0;
	y = 0;
	while (i < lens(a))
	{
		if (a[i] > a[y])
			y = i;
		i++;
	}
	i = 0;
	if (y != lens(a) - 1)
	{
		while (y < lens(a) - 1)
		{
			write(1, "rra\n", 4);
			reverse_rotate(a, arg);
			y++;
		}
	}
	if (lens(a) == 3 && is_sorted_dec(a) == 0)
	{
		write(1, "sa\n", 3);
		swap(a);
	}
}


