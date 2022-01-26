#include "functions.h"
#include <errno.h>
#include <unistd.h>

void	ft_builtin(int absolute_path, t_info *info)
{
	char	**all_paths;
	char	*cmd_path;
	int		i;

    absolute_path = 0;
	all_paths = ft_split(getenv("PATH"), ':');
	if (!all_paths)
		ft_error_message(info, "Malloc failed\n", 1);
	i = 0;
	if (absolute_path)
	{
		execve(info->cmd.cmd, info->cmd.args, info->env);
		if (errno == EACCES)
		{
			ft_print_errno("", info->cmd.cmd);
			exit(1);
		}
	}
	else
	{
		while (all_paths[i])
		{
			cmd_path = ft_strjoin3(all_paths[i], "/", info->cmd.cmd);
			if (!cmd_path)
				ft_error_message(info, "Malloc failed\n", 1);
			execve(cmd_path, info->cmd.args, info->env);
			if (errno == EACCES)
            {
				ft_print_errno("", info->cmd.cmd);
				exit(1);
            }
			i++;
		}
		ft_error_message(info, "command not found: ", 0);
		write(2, info->cmd.cmd, ft_strlen(info->cmd.cmd));
		write(2, "\n", 1);
		exit(1);
	}
}
//bool absolute_path
//char *path