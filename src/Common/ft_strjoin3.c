#include "common.h"

char	*ft_strjoin3(char const *s1, char const *s2, char const *s3)
{
	char	*str;
	char	*str_final;

	str = ft_strjoin(s1, s2);
	if (str == NULL)
		return (NULL);
	str_final = ft_strjoin(str, s3);
	free(str);
	return (str_final);
}