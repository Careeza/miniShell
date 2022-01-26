#include <stdlib.h>
#include "parser.h"
#include "minishell.h"

void    *ft_parse_cmd(t_info *info, t_cmd *cmd, int *status)
{
    char    **args;
    int     i;

    i = 0;
    args = ft_split_args(info->line_read, status);
    if (args == NULL)
		return (NULL);
    while (args[i])
    {
        args[i] = ft_parse_arg(info, args[i], status);
        if (args[i] == NULL)
            return (NULL);
        args[i] = ft_delete_quote(args[i]);
        if (!args[i])
            return (ft_return_error(status, MALLOC_FAIL));
        i++;
    }
    cmd->args = args;
    cmd->cmd = args[0];
    return (NULL);
}