#include "functions.h"

void    ft_pwd(t_info *info)
{
	char	*pwd;

	(void)info;
	pwd = getenv("PWD");
	if (pwd)
	{
		printf("%s\n", getenv("PWD"));
    	exit(0);
	}
	else
	{
		dprintf(2, "Error\n"); //TODO
	    exit(1);
	}
}