#include "minishell.h"

void    ft_pwd(t_info *info)
{
	int		i;
	char	*path;

	i = 0;
	while (info->env[i])
	{
		if (ft_strncmp(info->env[i], "PWD=", 4) == 0)
		{
			path = ft_substr(info->env[i], 4, ft_strlen(info->env[i]) - 4);
			ft_putstr(path);
			free(path);
			ft_putchar('\n');
			return ;
		}
		i++;
	}
}