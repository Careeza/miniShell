#include "parser.h"
#include "minishell.h"

char    *ft_parse_env_name(t_info *info, char *str, int *index)
{
    int     i;
    char    *name;
    char    *res;
    char    *exit_value;

    if (str[*index + 1] == '?')
    {
        exit_value = ft_itoa(info->exit_value);
        if (!exit_value)
            return (NULL);
        return (ft_replace(str, "$?", exit_value, index));
    }
    else {
        i = 1;
        while (str[i + *index] && ft_is_alpha_num(str[i + *index]))
            i++;
        name = ft_strndup(str + *index, i);
        if (!name)
            return (NULL);
        res = ft_replace(str, name, getenv(name + 1), index);
        free(name);
        return (res);
    }
}