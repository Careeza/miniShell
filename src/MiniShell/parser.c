#include "minishell.h"
#include "functions.h"
#include "common.h"

void    ft_parser(t_info *info)
{
    info->args = ft_split(info->line_read, ' ');
    info->nb_args = ft_tablen(info->args);
    if (ft_strcmp(info->line_read, "exit") == 0)
    {
        info->exit_value = 0;
        ft_exit(info);
    }
    else if (ft_strcmp(info->args[0], "pwd") == 0)
        ft_pwd(info);
    else if (ft_strcmp(info->args[0], "echo") == 0)
        ft_echo(info);
    else if (ft_strcmp(info->args[0], "cd") == 0)
        ft_cd(info);
    else {
        dprintf(2, "command not found: %s%s%s\n", CSI_RED, info->args[0], CSI_RESET);
    }
    ft_free_tabs(info->args);
    //else if ()
}