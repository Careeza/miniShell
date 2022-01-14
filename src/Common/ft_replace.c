#include "common.h"
#include <stdio.h>

char    *ft_replace(char *str, char *to_replace, char *replace_by, int *index)
{
    int		i;
	int		size;
	int		tmp;
	char	*new_str;

	i = 0;
	tmp = *index;
	new_str = malloc(sizeof(char) * (ft_strlen(str) - ft_strlen(to_replace) + ft_strlen(replace_by) + 1));
	if (new_str == NULL)
		return (NULL);
	while (i < *index)
	{
        new_str[i] = str[i];
		i++;
	}
	i = 0;
	size = ft_strlen(replace_by);
	while (i < size)
	{
		new_str[*index] = replace_by[i];
		(*index)++;
		i++;
	}
    i = tmp + ft_strlen(to_replace);
	size = 0;
	while(str[i])
    {
        new_str[*index + size] = str[i];
		size++;
		i++;
    }
	new_str[*index + size] = '\0';
    return (new_str);
}