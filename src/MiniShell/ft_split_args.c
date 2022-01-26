#include "common.h"
#include "minishell.h"
#include <unistd.h>

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

static	int	nbstring(char const *s)
{
	int	i;
	int	strcount;
	int is_in_quote;
	int is_in_double_quote;

	i = 0;
	strcount = 1;
	is_in_quote = 0;
	is_in_double_quote = 0;
	while (s[i] && s[i] == ' ')
		i++;
	if (!(s[i]))
		return (0);
	while (s[i])
	{
		if (!is_in_double_quote && s[i] == '\'')
			is_in_quote = !is_in_quote;
		if (!is_in_quote && s[i] == '"')
			is_in_double_quote = !is_in_double_quote;
		if (!is_in_quote && !is_in_double_quote)
		{
			if (s[i] == ' ')
			{
				while (s[i] == ' ')
					i++;
				if (!(s[i]))
					return (strcount);
				i--;
				strcount++;
			}
		}
		i++;
	}
	if (is_in_quote || is_in_double_quote)
		return (-1);
	return (strcount);
}

static	int	nbchar(char const *s, int save)
{
	int	charcount;
	int is_in_quote;
	int is_in_double_quote;

	is_in_quote = 0;
	is_in_double_quote = 0;
	charcount = 0;
	while (s[save])
	{
		if (!is_in_double_quote && s[save] == '\'')
			is_in_quote = !is_in_quote;
		if (!is_in_quote && s[save] == '"')
			is_in_double_quote = !is_in_double_quote;
		if (!is_in_double_quote && !is_in_quote && s[save] == ' ')
			break;
		charcount++;
		save++;
	}
	return (charcount);
}

static	char	**fill(char const *s, char **str, int nbstring)
{
	int	i;
	int	j;
	int	k;
	int is_in_quote;
	int is_in_double_quote;

	is_in_quote = 0;
	is_in_double_quote = 0;
	i = 0;
	j = 0;
	while (s[i] && j < nbstring)
	{
		k = 0;
		while (s[i] == ' ')
			i++;
		str[j] = malloc(sizeof(char) * (nbchar(s, i) + 1));
		if (str[j] == NULL)
			return (freestr(str));
		while (s[i])
		{
			if (!is_in_double_quote && s[i] == '\'')
				is_in_quote = !is_in_quote;
			if (!is_in_quote && s[i] == '"')
				is_in_double_quote = !is_in_double_quote;
			if (!is_in_double_quote && !is_in_quote && s[i] == ' ')
				break;
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

char	**ft_split_args(char const *s, int *status)
{
	int		i;
	char	**str;

	if (!(s))
		return (NULL);
	i = nbstring(s);
	if (i == -1)
		return (ft_return_error(status, UNCLOSE_QUOTE));
	str = malloc(sizeof(char *) * (i + 1));
	if (str == NULL)
		return (ft_return_error(status, MALLOC_FAIL));
	str = fill(s, str, i);
	if (!str)
		return (ft_return_error(status, MALLOC_FAIL));
	return (str);
}