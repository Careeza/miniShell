#include "common.h"

char    **ft_copy_tabs(char **tab)
{
    char    **res;
    int		i;
	int		len;

	i = 0;
	len = ft_tablen(tab);
	res = malloc(sizeof(char *) * (len + 1));
	if (!res)
		return (NULL);
	while (i < len)
	{
		res[i] = ft_strdup(tab[i]);
		if (!res[i])
			return (NULL);
		i++;
	}
	res[i] = NULL;
	return (res);
}