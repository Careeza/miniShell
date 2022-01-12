#include "common.h"
#include <errno.h>
#include <string.h>
#include <stdio.h>

void    ft_print_errno(char *msg_before, char *msg_after)
{
    char    *error_msg;

    (void)error_msg;
    error_msg = strerror(errno);
    dprintf(2, "%s: %s: %s\n", msg_before, error_msg, msg_after);
}