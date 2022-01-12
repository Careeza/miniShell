#include "minishell.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

int     main(int argc, char **argv, char **env) 
{
    t_info  info;

    (void)argv;
    (void)argc;
    info.env = env;
    //ft_pwd(&info);
    while (1)
    {
        info.line_read = readline("minishell> ");
        if (ft_strlen(info.line_read) > 0)
            add_history(info.line_read);
        ft_parser(&info);
    }
    return (0);
}