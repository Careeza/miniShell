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
		return (NULL);
	ft_strncpy(path, final_path, pos);
	ft_strcpy(arg2, final_path + pos);
	ft_strcpy(path + pos + ft_strlen(arg1), final_path + pos + ft_strlen(arg2));
	return (final_path);
}

int		ft_is_after_home(char *path)
{
	char *home;
	
	home = getenv("HOME");
	if (ft_strlen(home) == 0)
		return (0);
	if (ft_strncmp(home, path, ft_strlen(home)) == 0)
		return (1);
	else
		return (0);
}

void	ft_cd(t_info *info)
{
	char 	*final_path;
	char	*tmp;
	int		nb_args;

	nb_args = ft_tablen(info->cmd.args);

	if (nb_args == 1)
	{
		final_path = ft_strdup(getenv("HOME"));
		if (!final_path)
			ft_error_message(info, "Malloc failed\n", 1);
	}
	else if (nb_args == 2)
	{
		final_path = ft_parse_path(info->cmd.args[1]);
	}
	else if (nb_args == 3)
	{
		tmp = ft_getpwd();
		if (!tmp)
		{
			ft_error_message(info, "Can't get the cwd\n", 0);
			return ;
		}
		if (ft_strpos(tmp, info->cmd.args[1]) >= 0)
		{
			final_path = arg_replace(tmp, info->cmd.args[1], info->cmd.args[2],
				ft_strpos(getenv("PWD"), info->cmd.args[1]));
			if (!final_path)
				ft_error_message(info, "Malloc failed\n", 1);
			if (ft_is_after_home(final_path))
				printf("~%s\n", final_path + ft_strlen(getenv("HOME")));
			else
				printf("%s\n", final_path);
		}
		else
		{
			ft_error_message(info, "cd: string not in pwd: ", 0);
			write(2, info->cmd.args[1], ft_strlen(info->cmd.args[1]));
			write(2, "\n", 1);
			return ;
		}
	}
	else
	{
		ft_error_message(info, "cd: too many arguments\n", 0);
		return ;
	}
	if (chdir(final_path) == -1)
	{
		ft_print_errno("cd", final_path);
		info->exit_value = 1;
	}
	else
	{
		setenv("PWD", final_path, 1);
		info->exit_value = 0;
	}
	free(final_path);
}