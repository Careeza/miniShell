#include "functions.h"
#include <stdlib.h>

void    ft_unset(t_info *info)
{
    char    **tmp;
    int     i;
    int     j;

    if (ft_tablen(info->cmd.args) == 1)
        ;//TODO Error
    i = 1;
    while (info->cmd.args[i])
    {
        j = ft_contain_env_name(info->env, info->cmd.args[i]);
        if (j != -1)
        {
            tmp = info->env;
            info->env = ft_delete_elem_tab(info->env, j);
            free(tmp);
        }
        i++;
    }
}