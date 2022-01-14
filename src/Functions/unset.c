#include "functions.h"
#include <stdlib.h>

void    ft_unset(t_info *info)
{
    printf("JE UNSET %s\n", info->cmd.args[1]);
    unsetenv(info->cmd.args[1]);
    printf("LOUIS=%s\n", getenv(info->cmd.args[1]));
}