#include "functions.h"

void    ft_env(t_info *info)
{
    int     i;

    i = 0;
    while (info->env && info->env[i])
    {
        printf("%s\n", info->env[i]);
        i++;
    }
    info->exit_value = 0;
}