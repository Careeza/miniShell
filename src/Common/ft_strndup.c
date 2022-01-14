#include "common.h"

char	*ft_strndup(const char *s1, int n)
{
	int		i;
	char	*cpy;

	cpy = malloc(sizeof(char) * (n + 1));
	if (cpy == NULL)
		return (NULL);
	i = 0;
	while (s1[i] && i < n)
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}