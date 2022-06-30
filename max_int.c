#include "pushswaplib.h"

int	finder(char *s, char *coin)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (s[i])
	{
		while (s[i] == coin[y])
		{
			i++;
			y++;
			if (coin[y] == '\0')
				return (1);
		}
		i++;
	}
	return (0);
}

int	lensy(char *s)
{
	int	i;

	i =  0;
	while (s[i])
		i++;
	return (i);
}

int	is_max(char **args, int arg)
{
	int	i;
	int	y;

	y = 0;
	i = 1;
	while (i < arg)
	{
		if (lensy(args[i]) > 10)
			return (1);
		if (lensy(args[i]) == 10)
		{
			y = ft_atoi(args[i]);
			if (y <= 0)
				return (1);
		}
		i++;
	}
	return (0);
}

