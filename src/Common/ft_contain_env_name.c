#include "common.h"

int     ft_contain_env_name(char **env, char *str)
{
    int i;
    int j;

    i = 0;
    while (str[i] && str[i] != '=')
        i++;
    j = 0;
    while (env[j])
    {
        if (ft_strncmp(env[j], str, i) == 0)
            return (j);
        j++;
    }
    return (-1);
}