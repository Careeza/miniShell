#include "common.h"
#include "minishell.h"
#include <unistd.h>

void    ft_error_message(t_info *info, char *message, int exit_value)
{
    write(2, CSI_RED, ft_strlen(CSI_RED));
    write(2, message, ft_strlen(message));
    write(2, CSI_RESET, ft_strlen(CSI_RESET));
    if (exit_value != 0)
        exit(exit_value); //TODO FREE
    info->exit_value = 1;
}