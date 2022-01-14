#include "minishell.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

//ft_getpwd();
//getenv("PWD");
char	*ft_get_exec_name()
{
    char	*exec_name;

    exec_name = ft_strjoin(ft_getpwd(), " \033[32m➜ \033[96;01mminishell ");
    exec_name = ft_strjoin("\033[21m", exec_name);
    exec_name = ft_strjoin(exec_name, "\033[0m");
    return (exec_name);
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