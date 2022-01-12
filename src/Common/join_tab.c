#include "common.h"
#include <stdlib.h>

char	**join_tab_cut(int i, char **tab, char **tab2, int size2)
{
	int	j;

	j = 0;
	while (j < size2)
	{
		tab[i + j] = tab2[j];
		j++;
	}
	tab[i + j] = NULL;
	if (tab2)
		free(tab2);
	return (tab);
}

char	**join_tab(char **tab1, char **tab2)
{
	char	**tab;
	int		size1;
	int		size2;
	int		i;

	size1 = ft_tablen(tab1);
	size2 = ft_tablen(tab2);
	tab = malloc(sizeof(char *) * (size1 + size2 + 1));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (i < size1)
	{
		tab[i] = tab1[i];
		i++;
	}
	if (tab1)
		free(tab1);
	return (join_tab_cut(i, tab, tab2, size2));
}