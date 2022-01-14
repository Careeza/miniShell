#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <readline/readline.h>

int	ft_nb_size(long nb)
{
	int	size;
	int	i;

	size = 1;
	i = 1;
	if (nb < 0)
    {
        i++;
        nb = -nb;
    }
	while(nb / size >= 10)
	{
		size *= 10;
		i++;
	}
    return (i);

}

char	*ft_itoa(int nb)
{
    long	nbr;
	char	*str;
	int		i;
	int		size;

	nbr = nb;
	size = ft_nb_size(nbr);
	str = malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
    i = 0;
    if (nbr < 0)
    {
        nbr = -nbr;
        str[i] = '-';
		i++;
    }
    str[size] = '\0';
	while (size > i)
	{
		str[size - 1] = (nbr % 10) + '0';
        nbr /= 10;
		size--;
	}
    return (str);
}

int     main(void)
{
    //readline("\033[38;5;14m/Users/fredericbecerril/projet/Louis/miniShell/test \033[38;5;197m➜\033[38;5;14m minishell \033[38;5;11;01m∆ \033[0m");
    
    //printf("%s\n", "\033[38;2;0;0;200m TEST\033[0m LUL");
    return (0);

}