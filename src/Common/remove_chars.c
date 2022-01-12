#include "common.h"

void	remove_chars(char *str, char c1, char c2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != c1 && str[i] != c2)
		{
			str[j] = str[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
}