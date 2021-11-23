#include "minishell.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

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
    int		status;

    info.argc = argc;
    info.argv = argv;
    info.env = env;
    test_echo(&info);
    test_pwd(&info);
    wait(&status);
    printf("\n");
    return (0);
}