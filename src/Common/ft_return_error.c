#include "common.h"

void    *ft_return_error(int *status, int status_value)
{
    *status = status_value;
    return (NULL);
}