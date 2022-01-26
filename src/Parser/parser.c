#include <unistd.h>
#include "minishell.h"
#include "functions.h"
#include "common.h"
#include "parser.h"

void    ft_parser(t_info *info)
{
    int     status;
    pid_t   pid;

    status = 1;
    ft_parse_cmd(info, &info->cmd, &status);
	if (status == MALLOC_FAIL)
		ft_error_message(info, "Malloc failed\n", 1);
	if (status == BAD_PARSING)
		ft_error_message(info, "Parser error : Bad parsing\n", 0);
    if (status == UNCLOSE_QUOTE)
        ft_error_message(info, "Parser error : Unclose quote\n", 0);
    if (status != 1)
        return ;
    if (ft_strcmp(info->cmd.cmd, "exit") == 0)
    {
        info->exit_value = 0;
        ft_exit(info);
    }
    else if (ft_strcmp(info->cmd.cmd, "pwd") == 0)
        ft_pwd(info);
    else if (ft_strcmp(info->cmd.cmd, "echo") == 0)
        ft_echo(info);
    else if (ft_strcmp(info->cmd.cmd, "cd") == 0)
        ft_cd(info);
    else if (ft_strcmp(info->cmd.cmd, "export") == 0)
        ft_export(info);
    else if (ft_strcmp(info->cmd.cmd, "unset") == 0)
        ft_unset(info);
    else if (ft_strcmp(info->cmd.cmd, "env") == 0)
        ft_env(info);
    else {
        pid = fork();    
        if (pid == 0)
        {
            if (info->cmd.cmd[0] == '/')
                info->cmd.is_absolute = 1;
            ft_builtin(0, info);
        }
        waitpid(pid, &status, 0);
        info->exit_value = WEXITSTATUS(status);
    }
    ft_free_tabs(info->cmd.args);
}