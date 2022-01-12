#ifndef MINISHELL_H

# define MINISHELL_H

#include "common.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_info
{
    char	**args;
    char	**env;
    int		exit_value;
	char	*line_read;
    int		nb_args;
} t_info;

void    ft_parser(t_info *info);

#endif