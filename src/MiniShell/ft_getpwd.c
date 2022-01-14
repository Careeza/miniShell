#include "minishell.h"
#include <unistd.h>

char *ft_getpwd()
{
    return (getcwd(NULL, 0));
}