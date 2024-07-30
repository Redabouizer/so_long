
#include "../so_long.h"

int ft_find_x(char **s, char c)
{
	int	i;
	int j;

	i = 0;
	while (s[i] != NULL)
	{
		j = 0;
		while (s[i][j] != '\0')
	    {
			if (s[i][j] == c)
				return (j);
			j++;
		}
		i++;
	}
	return (-1);
}

int ft_find_y(char **s, char c)
{
	int	i;
	int j;

	i = 0;
	while (s[i] != NULL)
	{
		j = 0;
		while (s[i][j] != '\0')
	    {
			if (s[i][j] == c)
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}