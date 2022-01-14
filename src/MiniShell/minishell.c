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

char	*ft_get_exec_name()
{
    return (ft_strjoin3("(minishell) \033[38;5;46m➜ \033[38;5;14m", ft_get_pos(), " \033[38;5;11m∆ \033[0m"));
}

int     main(int argc, char **argv, char **env) 
{
    t_info  info;
	char	*exec_name;

    (void)argv;
    (void)argc;
    info.env = env;
    while (1)
    {
        exec_name = ft_get_exec_name();
        info.line_read = readline(exec_name);
        if (ft_strlen(info.line_read) > 0)
        {
            add_history(info.line_read);
            ft_parser(&info);
        }
    }
    return (0);
}

//implement the last exit