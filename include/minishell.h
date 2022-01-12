#ifndef MINISHELL_H

# define MINISHELL_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_info
{
    int		argc;
    char	**argv;
    char	**env;
    int		exit_value;
	char	*line_read;
} t_info;

void	remove_chars(char *str, char c1, char c2);
char	**join_tab(char **tab1, char **tab2);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strlen(const char *str);
void	ft_putstr(char *str);
void	ft_putchar(char c);
void    ft_cd(t_info *info);
void    ft_echo(t_info *info);
void    ft_env(t_info *info);
void    ft_exit(t_info *info);
void    ft_export(t_info *info);
void    ft_pwd(t_info *info);
void    ft_unset(t_info *info);

#endif