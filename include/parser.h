#ifndef PARSER_H

# define PARSER_H

# include "minishell.h"

char    *ft_delete_quote(char *str);
char    *ft_parse_arg(t_info *info, char *arg, int *status);
void    *ft_parse_cmd(t_info *info, t_cmd *cmd, int *status);
char    *ft_parse_env_name(t_info *info, char *str, int *index);
char    *ft_parse_path(char *str);

#endif