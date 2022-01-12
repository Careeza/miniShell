#include "common.h"

int	ft_strpos(char *s, char *tocheck)
{
	int		i;
	int		j;
	int		tmp;

	i = 0;
	while (s[i])
	{
		if (s[i] == tocheck[0])
		{
			tmp = i;
			j = 0;
			while (tocheck[j] && s[tmp])
			{
				if (tocheck[j] != s[tmp])
					break ;
				j++;
				tmp++;
			}
			if (!tocheck[j])
				return (i);
		}
		i++;
	}
	return (-1);
}