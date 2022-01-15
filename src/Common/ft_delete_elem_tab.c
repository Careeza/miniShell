#include "common.h"

char    **ft_delete_elem_tab(char **tab, int index)
{
    int     len;
    int     i;
    int     j;
    char    **res;

    len = ft_tablen(tab);
    if (index >= len)
        ;//TODO ERROR;
    res = malloc(sizeof(char*) * len);
    if (!res)
        ;//TODO ERROR
    i = 0;
    j = 0;
    while (tab[i])
    {
        if (i != index)
        {
            res[j] = tab[i];
            j++;
        }
        i++;
    }
    res[j] = NULL;
    return (res);
}