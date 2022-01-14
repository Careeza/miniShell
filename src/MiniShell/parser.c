#include "minishell.h"
#include "functions.h"
#include "common.h"
#include <unistd.h>

void    ft_cut_path(char *path)
{
    int i;

    i = ft_strlen(path) - 1;
    while (i >= 0 && path[i] != '/')
        i--;
    if (i < 0)
        return ;
    if (i == 0)
    {
        if (path[0] == '/')
            path[1] = '\0';
    }
    else
        path[i] = '\0';
}

char    *ft_parse_path(char *str)
{
    char    *path;
    char    **paths;
    char    *tmp;
    int     i;

    path = NULL;
    paths = ft_split(str, '/');                     
    if (str[0] != '/')
        path = ft_getpwd();
    i = 0;
    while (paths[i])
    {
        if (ft_strcmp(paths[i], "..") == 0)
        {
            ft_cut_path(path);
        }
        else if (ft_strcmp(paths[i], ".") == 0)
            ;
        else
        {
            tmp = path;
            path = ft_strjoin3(path, "/", paths[i]);
            if (tmp != NULL)
                free(tmp);
        }
        i++;
    }
    ft_free_tabs(paths);
    return (path);
}

char    *ft_parse_env_name(t_info *info, char *str, int *index)
{
    int     i;
    char    *name;

    if (str[*index + 1] == '?')
        return (ft_replace(str, "$?", ft_itoa(info->exit_value), index));
    else {
        i = 1;
        while (str[i + *index] && ft_is_alpha_num(str[i + *index]))
            i++;
        name = ft_strndup(str + *index, i);
        return (ft_replace(str, name, getenv(name + 1), index));
        free(name);
    }
}

char    *ft_parse_arg(t_info *info, char *arg)
{
    char    *tmp;
	int     is_in_quote;
	int     is_in_double_quote;
    int     i;

	is_in_quote = 0;
	is_in_double_quote = 0;
    i = 0;
    if (arg[0] == '~')
    {
        if (arg[1] != '/' && arg[1] != '\0')
        {
            dprintf(2, "Error\n");
            return (NULL);
            //TODO
        }
        tmp = arg;
        arg = ft_replace(arg, "~", getenv("HOME"), &i);
        free(tmp);
    }
    while (arg[i])
    {
        if (!is_in_double_quote && arg[i] == '\'')
            is_in_quote = !is_in_quote;
        if (!is_in_quote && arg[i] == '"')
            is_in_double_quote = !is_in_double_quote;
        if (!is_in_quote && arg[i] == '$')
        {
            tmp = arg;
            arg = ft_parse_env_name(info, arg, &i);
            free(tmp);
            i--;
        }
        i++;
    }
    return (arg);
}

char    *ft_delete_quote(char *str)
{
	int     is_in_quote;
	int     is_in_double_quote;
    int     i;
    int     size;
    char    *new_str;

	is_in_quote = 0;
	is_in_double_quote = 0;
    i = 0;
    size = 0;
    while (str[i])
    {
        if (!is_in_double_quote && str[i] == '\'')
            is_in_quote = !is_in_quote;
        else if (!is_in_quote && str[i] == '"')
            is_in_double_quote = !is_in_double_quote;
        else
            size++;
        i++;
    }
    new_str = malloc(sizeof(char) * (size + 1));
    if (new_str == NULL)
        return (NULL);
    i = 0;
    size = 0;
    while (str[i])
    {
        if (!is_in_double_quote && str[i] == '\'')
            is_in_quote = !is_in_quote;
        else if (!is_in_quote && str[i] == '"')
            is_in_double_quote = !is_in_double_quote;
        else
        {
            new_str[size] = str[i];
            size++;
        }
        i++;
    }
    new_str[size] = '\0';
    free(str);
    return (new_str);
}

void    ft_parse_cmd(t_info *info, t_cmd *cmd)
{
    char    **args;
    int     i;

    i = 0;
    args = ft_split_args(info->line_read);
    if (args == NULL)
        return ;
    while (args[i])
    {
        args[i] = ft_parse_arg(info, args[i]);
        if (args[i] == NULL)
        {
            return ;
            //TODO
        }
        args[i] = ft_delete_quote(args[i]);
        i++;
    }
    cmd->args = args;
    cmd->cmd = args[0];
}

void    ft_parser(t_info *info)
{
    int     status;
    pid_t   pid;

    ft_parse_cmd(info, &info->cmd);
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
    {
        unsetenv(info->cmd.args[1]);
        //ft_unset(info);
    }
    else {
        pid = fork();    
        if (pid == 0)
            ft_builtin(0, info);
        waitpid(pid, &status, 0);
    }
    ft_free_tabs(info->cmd.args);
}