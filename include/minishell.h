#ifndef MINISHELL_H

# define MINISHELL_H

#include "common.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_cmd
{
    char    **args;
    char    *cmd;
    int     is_absolute;
} t_cmd;

typedef struct s_info
{
    char	**env;
    int		exit_value;
	char	*line_read;
    t_cmd   cmd;
} t_info;

void    ft_parser(t_info *info);
char    *ft_parse_path(char *str);
char	**ft_split_args(char const *s);
char    *ft_getpwd();

#endif