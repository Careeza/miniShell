#include "functions.h"

void    ft_pwd(t_info *info)
{
	char	*pwd;

	(void)info;
	pwd = ft_getpwd();
	if (pwd)
	{
		info->exit_value = 0;
		printf("%s\n", getenv("PWD"));
	}
	else
		ft_error_message(info, "Can't get the cwd\n", 0);
}