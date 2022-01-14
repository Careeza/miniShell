#include "common.h"
#include <errno.h>
#include <string.h>
#include <unistd.h>

void    ft_print_errno(char *msg_before, char *msg_after)
{
    char    *error_msg;

    (void)error_msg;
    error_msg = strerror(errno);
    write(2, msg_before, ft_strlen(msg_before));
    write(2, ": ", 2);
    write(2, error_msg, ft_strlen(error_msg));
    write(2, ": ", 2);
    write(2, msg_after, ft_strlen(msg_after));
    write(2, "\n", 1);
    //dprintf(2, "%s: %s: %s\n", msg_before, error_msg, msg_after);
}