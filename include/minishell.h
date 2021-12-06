#ifndef MINISHELL_H

# define MINISHELL_H

typedef struct s_info
{
    int argc;
    char **argv;
    char **env;
} t_info;

void    ft_cd(t_info *info);
void    ft_echo(t_info *info);
void    ft_env(t_info *info);
void    ft_exit(int exit_value);
void    ft_export(t_info *info);
void    ft_pwd(t_info *info);
void    ft_unset(t_info *info);

#endif