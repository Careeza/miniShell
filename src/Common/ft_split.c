#include "common.h"
#include <stdlib.h>

static	char	**freestr(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static	int	nbstring(char const *s, char c)
{
	int	i;
	int	strcount;

	i = 0;
	strcount = 1;
	while (s[i] && s[i] == c)
		i++;
	if (!(s[i]))
		return (0);
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] == c)
				i++;
			if (!(s[i]) && strcount > 1)
				return (strcount);
			i--;
			strcount++;
		}
		i++;
	}
	return (strcount);
}

static	int	nbchar(char const *s, char c, int save)
{
	int	charcount;

	charcount = 0;
	while (s[save] && s[save] != c)
	{
		charcount++;
		save++;
	}
	return (charcount);
}

static	char	**fill(char const *s, char **str, char c, int nbstring)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i] && j < nbstring)
	{
		k = 0;
		while (s[i] == c)
			i++;
		str[j] = malloc(sizeof(char) * (nbchar(s, c, i) + 1));
		if (str[j] == NULL)
			return (freestr(str));
		while (s[i] && s[i] != c)
		{
			str[j][k] = s[i];
			k++;
			i++;
		}
		str[j][k] = '\0';
		j++;
	}
	str[j] = 0;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**str;

	if (!(s))
		return (NULL);
	i = nbstring(s, c);
	str = malloc(sizeof(char *) * (i + 1));
	if (str == NULL)
		return (NULL);
	return (fill(s, str, c, i));
}