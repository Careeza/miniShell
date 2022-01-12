#include "functions.h"

void    ft_echo(t_info *info)
{
    int		i;
	int		count_1;
	int		count_2;

	i = 0;
	count_1 = 0;
	count_2 = 0;
	info->line_read += 5;
	while (info->line_read[i])
	{
		if (info->line_read[i] == '"')
			count_1++;
		else if (info->line_read[i] == '\'')
			count_2++;
		i++;
	}
	i = 0;
	if (count_1 % 2 == 0 && count_2 % 2 == 0)
	{
		remove_chars(info->line_read, '"', '\'');
		ft_putstr(info->line_read);
	}
	//else impair
    ft_putchar('\n');
}