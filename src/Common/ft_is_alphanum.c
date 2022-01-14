#include "common.h"

int		ft_is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		ft_is_alpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

int		ft_is_alpha_num(char c)
{
	if (ft_is_num(c) || ft_is_alpha(c))
		return (1);
	return (0);
}