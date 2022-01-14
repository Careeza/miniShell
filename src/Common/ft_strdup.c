#include "common.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*cpy;

	i = 0;
	len = 0;
	while (s1[len])
		len++;
	cpy = malloc(sizeof(char) * (len + 1));
	if (cpy == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}