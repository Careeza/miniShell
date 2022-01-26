#ifndef MINISHELL_H

# define MINISHELL_H

# include "common.h"
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>

# define MALLOC_FAIL -1
# define UNCLOSE_QUOTE -2
# define BAD_PARSING -3

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

void    ft_error_message(t_info *info, char *message, int exit_value);
void    ft_parser(t_info *info);
char    *ft_parse_path(char *str);
char	**ft_split_args(char const *s, int *status);
char    *ft_getpwd();

#endif