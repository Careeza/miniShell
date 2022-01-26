#include <stdlib.h>
#include "parser.h"

char    *ft_delete_quote(char *str)
{
	int     is_in_quote;
	int     is_in_double_quote;
    int     i;
    int     size;
    char    *new_str;

	is_in_quote = 0;
	is_in_double_quote = 0;
    i = 0;
    size = 0;
    while (str[i])
    {
        if (!is_in_double_quote && str[i] == '\'')
            is_in_quote = !is_in_quote;
        else if (!is_in_quote && str[i] == '"')
            is_in_double_quote = !is_in_double_quote;
        else
            size++;
        i++;
    }
    new_str = malloc(sizeof(char) * (size + 1));
    if (new_str == NULL)
        return (NULL);
    i = 0;
    size = 0;
    while (str[i])
    {
        if (!is_in_double_quote && str[i] == '\'')
            is_in_quote = !is_in_quote;
        else if (!is_in_quote && str[i] == '"')
            is_in_double_quote = !is_in_double_quote;
        else
        {
            new_str[size] = str[i];
            size++;
        }
        i++;
    }
    new_str[size] = '\0';
    free(str);
    return (new_str);
}