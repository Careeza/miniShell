#include "minishell.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		count;
	char	*str;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	count = i + j;
    printf("count pour malloc = %d\n", count);
	str = malloc(sizeof(char) * (count + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	while (s1 && s1[++i])
		str[i] = s1[i];
	j = 0;
	while (s2 && s2[j])
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = '\0';
	return (str);
}