#include "functions.h"
#include "common.h"
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <unistd.h>
#include <limits.h>

char	*arg_replace(char *path, char *arg1, char *arg2, int pos)
{
	char 	*final_path;

	final_path = malloc(sizeof(char *) * ((ft_strlen(path) - ft_strlen(arg1) + ft_strlen(arg2)) + 1));
	if (final_path == NULL)
		exit(EXIT_FAILURE);
	ft_strncpy(path, final_path, pos);
	ft_strcpy(arg2, final_path + pos);
	ft_strcpy(path + pos + ft_strlen(arg1), final_path + pos + ft_strlen(arg2));
	return (final_path);
}

int		ft_is_after_home(char *path)
{
	char *home;
	
	home = getenv("HOME");
	if (ft_strncmp(home, path, ft_strlen(home)) == 0)
		return (1);
	else
		return (0);
}

void	ft_cd(t_info *info)
{
	(void)info;
	// char	*final_path;
	// int		need_to_free;
	// int		i;

	// need_to_free = 0;
	// if (info->nb_args == 1)
	// 	final_path = getenv("HOME");
	// else if (info->nb_args == 2)
	// {
	// 	if (info->args[1][0] != '/' && info->args[1][0] != '~')
	// 	{
	// 		if (info->args[1][0] == '.')
	// 		{
	// 			final_path = getenv("PWD");
	// 			if (info->args[1][1] == '.')
	// 			{
	// 				i = ft_strlen(final_path);
	// 				while (i > 1 && final_path[i] != '/')
	// 					i--;
	// 				final_path[i] = '\0';
	// 			}
	// 		}
	// 		else
	// 		{
	// 			final_path = ft_strjoin3(getenv("PWD"), "/", info->args[1]);
	// 			need_to_free = 1;
	// 		}
	// 	}
	// 	else
	// 	{
	// 		if (info->args[1][0] == '~')
	// 		{
	// 			if (ft_strlen(info->args[1]) == 1)
	// 				final_path = getenv("HOME");
	// 			else
	// 			{
	// 				final_path = ft_strjoin(getenv("HOME"), info->args[1] + 1);
	// 				need_to_free = 1;
	// 			}
	// 		}
	// 		else
	// 			final_path = info->args[1];
	// 	}
	// }
	// else if (info->nb_args == 3)
	// {
	// 	if (ft_strpos(getenv("PWD"), info->args[1]) >= 0)
	// 	{
	// 		final_path = arg_replace(getenv("PWD"), info->args[1], info->args[2],
	// 			ft_strpos(getenv("PWD"), info->args[1]));
	// 		if (ft_is_after_home(final_path))
	// 			printf("~%s\n", final_path + ft_strlen(getenv("HOME")));
	// 		else
	// 			printf("%s\n", final_path);
	// 		need_to_free = 1;
	// 	}
	// 	else
	// 	{
	// 		printf("cd: string not in pwd: %s\n", info->args[1]);
	// 		exit(1);
	// 	}
	// }
	// else
	// {
	// 	dprintf(2, "cd: too many arguments\n");
	// 	exit(1);
	// }
	// if (chdir(final_path) == -1)
	// {
	// 	ft_print_errno("cd", final_path);
	// 	exit(1);
	// }
	// setenv("PWD", final_path, 1);
	// if (need_to_free)
	// 	free(final_path);
	// exit(0);
}