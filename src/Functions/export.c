#include "functions.h"

int     ft_contain(char *str, char c)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == c)
            break;
        i++;
    }
    return (i != ft_strlen(str));
}

void    ft_export(t_info *info)
{
    char	**tmp;
    char    *str;
    int     i;
    int     j;

    if (ft_tablen(info->cmd.args) == 1)
    {
        ft_env(info);
        return ;
    }
    i = 1;
    while (info->cmd.args[i])
    {
        str = info->cmd.args[i];
        if (str[0] == '=')
            ;//TODO ERROR
        else if (ft_contain(str, '='))
        {
            j = ft_contain_env_name(info->env, str);
            if (j == -1)
            {
                tmp = info->env;
                info->env = ft_join_tab_str(info->env, str);
                ft_free_tabs(tmp);
            } 
            else
            {
                free(info->env[j]);
                info->env[j] = ft_strdup(str);
            }
        }
        i++;
    }
}