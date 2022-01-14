#include "functions.h"

void    ft_export(t_info *info)
{
    char	**values;

    values = ft_split(info->cmd.args[1], '=');
    setenv(values[0], values[1], 1);
    exit(0);
}