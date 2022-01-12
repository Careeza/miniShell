#ifndef FUNCTIONS_H

# define FUNCTIONS_H
# include "minishell.h"
# include "common.h"

void    ft_cd(t_info *info);
void    ft_echo(t_info *info);
void    ft_env(t_info *info);
void    ft_exit(t_info *info);
void    ft_export(t_info *info);
void    ft_pwd(t_info *info);
void    ft_unset(t_info *info);

#endif