#include "minishell.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

void    test_cd(t_info* info)
{
    (void)info;
}

void    test_echo(t_info* info)
{
    char *arg[] = {"echo", "TRISTAN EST UNE SALOPE", NULL};
    char *cmd = "/bin/echo";

    if (fork() == 0)
        execve(cmd, arg, info->env);
}

void    test_env(t_info* info)
{
    (void)info;
}

void    test_exit(t_info* info)
{
    (void)info;
}

void    test_export(t_info* info)
{
    (void)info;
}

void    test_pwd(t_info* info)
{
    char *arg[] = {"pwd", NULL};
    char *cmd = "/bin/pwd";
    
    if (fork() == 0)
        execve(cmd, arg, info->env);
}

void    test_unset(t_info* info)
{
    (void)info;
}

int     main(int argc, char **argv, char **env) 
{
    t_info  info;

    info.argc = argc;
    info.argv = argv;
    info.env = env;
    //ft_pwd(&info);
    //printf("\n");
    while (1)
    {
        info.line_read = readline("minishell> ");
        if (ft_strncmp(info.line_read, "exit", 4) == 0)
        {
            info.exit_value = 0;
            ft_exit(&info);
        }
        if (ft_strncmp(info.line_read, "pwd", 3) == 0)
            ft_pwd(&info);
        if (ft_strncmp(info.line_read, "echo", 4) == 0)
            ft_echo(&info);
    }
    return (0);
}