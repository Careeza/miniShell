#include "functions.h"

void    ft_pwd(t_info *info)
{
	char	*pwd;

	(void)info;
	pwd = ft_getpwd();
	if (pwd)
		printf("%s\n", getenv("PWD"));
	else
		dprintf(2, "Error\n"); //TODO
}