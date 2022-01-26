#include "functions.h"
#include <stdlib.h>

void    ft_unset(t_info *info)
{
    char    **tmp;
    int     i;
    int     j;

    if (ft_tablen(info->cmd.args) == 1)
    {
        ft_error_message(info, "unset: not enough arguments\n", 0);
        return ;
    }
    i = 1;
    while (info->cmd.args[i])
    {
        j = ft_contain_env_name(info->env, info->cmd.args[i]);
        if (j != -1)
        {
            tmp = info->env;
            info->env = ft_delete_elem_tab(info->env, j);
            free(tmp);
            if (!info->env)
                ft_error_message(info, "Malloc failed\n", 1);
        }
        i++;
    }
    info->exit_value = 0;
}