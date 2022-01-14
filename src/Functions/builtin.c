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
	i = 0;
	if (absolute_path)
	{
		execve(info->cmd.cmd, info->cmd.args, info->env);
		if (errno == EACCES)
			ft_print_errno("", info->cmd.cmd);
	}
	else
	{
		while (all_paths[i])
		{
			cmd_path = ft_strjoin3(all_paths[i], "/", info->cmd.cmd);

			execve(cmd_path, info->cmd.args, info->env);
			if (errno == EACCES)
            {
				ft_print_errno("", info->cmd.cmd);
                return ;
            }
			i++;
		}
        dprintf(2, "command not found: %s\n", info->cmd.cmd);
	}
}
//bool absolute_path
//char *path