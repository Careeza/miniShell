#ifndef COMMON_H

# define COMMON_H

# include <stdlib.h>
# define CSI             "\033["
# define CSI_GREEN CSI   "32;01m"
# define CSI_WHITE CSI   "37;01m"
# define CSI_BLUE CSI    "34;01m"
# define CSI_CYAN CSI    "96;01m"
# define CSI_YELLOW CSI  "33;01m"
# define CSI_MAGENTA CSI "35;01m"
# define CSI_PURPLE CSI  "92;01m"
# define CSI_RED CSI     "31m"
# define CSI_RESET CSI   "0m"

int		ft_is_alpha_num(char c);
int		ft_is_num(char c);
int		ft_is_alpha(char c);
char	*ft_strdup(const char *s1);
char	*ft_strndup(const char *s1, int n);
void    ft_print_errno(char *msg_before, char *msg_after);
void	ft_free_tabs(char **tab);
void	ft_strcpy(char *src, char *dest);
void	ft_strncpy(char *src, char *dest, int n);
void	remove_chars(char *str, char c1, char c2);
char	**join_tab(char **tab1, char **tab2);
int	    ft_tablen(char **tab);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin3(char const *s1, char const *s2, char const *s3);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strlen(const char *str);
void	ft_putstr(char *str);
void	ft_putchar(char c);
int     ft_strpos(char *s, char *tocheck);
char    *ft_replace(char *str, char *to_replace, char *replace_by, int *index);
char    *ft_itoa(int nb);

#endif