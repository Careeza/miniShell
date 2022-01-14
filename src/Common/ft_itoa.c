#include "common.h"

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
    return (size);
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