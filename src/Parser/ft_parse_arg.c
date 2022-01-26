#include "parser.h"
#include "common.h"
#include "minishell.h"

char    *ft_parse_arg(t_info *info, char *arg, int *status)
{
    char    *tmp;
	int     is_in_quote;
	int     is_in_double_quote;
    int     i;

	is_in_quote = 0;
	is_in_double_quote = 0;
    i = 0;
    if (arg[0] == '~')
    {
        if (arg[1] != '/' && arg[1] != '\0')
        {
			*status = BAD_PARSING;
            return (NULL);
        }
        tmp = arg;
        arg = ft_replace(arg, "~", getenv("HOME"), &i);
        free(tmp);
        if (!arg)
            return (ft_return_error(status, MALLOC_FAIL));
    }
    while (arg[i])
    {
        if (!is_in_double_quote && arg[i] == '\'')
            is_in_quote = !is_in_quote;
        if (!is_in_quote && arg[i] == '"')
            is_in_double_quote = !is_in_double_quote;
        if (!is_in_quote && arg[i] == '$')
        {
            tmp = arg;
            arg = ft_parse_env_name(info, arg, &i);
            free(tmp);
            if (!arg)
                return (ft_return_error(status, MALLOC_FAIL));
            i--;
        }
        i++;
    }
    return (arg);
}