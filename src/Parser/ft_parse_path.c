#include "parser.h"
#include <stdlib.h>

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