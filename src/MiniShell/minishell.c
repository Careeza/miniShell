#include "minishell.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

//ft_getpwd();
//getenv("PWD");

char    *ft_get_pos()
{
    char    *pwd;
    int     i;

    pwd = ft_getpwd();
    i = ft_strlen(pwd) - 1;
    while (i >= 0 && pwd[i] != '/')
        i--;
    if (i == 0)
        return (pwd);
    else
        return (pwd + i + 1);
}

char	*ft_get_exec_name(t_info *info)
{
    if (info->exit_value == 0)
        return (ft_strjoin3("(minishell) \033[38;5;46m➜ \033[38;5;14m", ft_get_pos(), " \033[38;5;11m∆ \033[0m"));
    return (ft_strjoin3("(minishell) \033[38;5;9m➜ \033[38;5;14m", ft_get_pos(), " \033[38;5;11m∆ \033[0m"));
}

int     main(int argc, char **argv, char **env) 
{
    t_info  info;
	char	*exec_name;

    (void)argv;
    (void)argc;
    info.env = ft_copy_tabs(env);
    info.exit_value = 0;
    if (!info.env)
    {
        printf("HERE\n");
        ft_error_message(&info, "malloc failed\n", 1);
    }
    exec_name = NULL;
    while (1)
    {
        if (exec_name)
            free(exec_name);
        exec_name = ft_get_exec_name(&info);
        if (!exec_name)
            ft_error_message(&info, "malloc failed\n", 1);
        info.line_read = readline(exec_name);
        if (ft_strlen(info.line_read) > 0)
        {
            add_history(info.line_read);
            ft_parser(&info);
        }
    }
    return (0); //TODO IMPLEMENT FREE HISTORY !
}

//implement the last exit