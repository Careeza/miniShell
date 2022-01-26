#include "common.h"
#include <stdio.h>

char    **ft_join_tab_str(char **tab, char *str)
{
    char    **res;
    int     len1;
    int     i;

    len1 = ft_tablen(tab);
    res = malloc(sizeof(char *) * (len1 + 2));
    if (!res)
        return (NULL);
    i = 0;
    while (i < len1)
    {
        res[i] = ft_strdup(tab[i]);
        if (!res[i])
            return (NULL);
        i++;
    }
    res[len1] = ft_strdup(str);
    if (!res[len1])
        return (NULL);
    res[len1 + 1] = NULL;
    return (res);
}