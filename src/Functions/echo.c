#include "functions.h"

void    ft_echo(t_info *info)
{
	int 	i;
	int		print_n;
	char	**args;


	print_n = 1;
	args = info->cmd.args;
	i = 1;
	if (args[1] && ft_strcmp(args[1], "-n") == 0)
	{
		i = 2;
		print_n = 0;
	}
	while (args[i])
	{
		printf("%s", args[i]);
		i++;
		if (args[i])
			printf(" ");
	}
	if (print_n)
		printf("\n");
}