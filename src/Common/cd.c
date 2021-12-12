//#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
/*
void	ft_cd(t_info *info)
{
	(void)info;
}
*/
/*
struct dirent {
	ino_t          d_ino;       // numéro d'inœud
	off_t          d_off;       // décalage jusqu'à la dirent suivante
	unsigned short d_reclen;    // longueur de cet enregistrement
	unsigned char  d_type;      // type du fichier
	char           d_name[256]; // nom du fichier
};
*/
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		len1;
	int		len2;
	char	*str;

	if (s1 && s2)
	{
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		str = (char*)malloc(sizeof(char) * (len1 + len2 + 1));
		if (str == NULL)
			return (NULL);
		i = -1;
		while (s1[++i])
			str[i] = s1[i];
		i = -1;
		while (s2[++i])
		{
			str[len1] = s2[i];
			len1++;
		}
		str[len1] = '\0';
		return (str);
	}
	return (NULL);
}

static char	**ft_malloc_error(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static unsigned int	ft_get_nb_strs(char const *s, char c)
{
	unsigned int	i;
	unsigned int	nb_strs;

	if (!s[0])
		return (0);
	i = 0;
	nb_strs = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			nb_strs++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		nb_strs++;
	return (nb_strs);
}

static void		ft_get_next_str(char **next_str, unsigned int *next_str_len,
					char c)
{
	unsigned int	i;

	*next_str += *next_str_len;
	*next_str_len = 0;
	i = 0;
	while (**next_str && **next_str == c)
		(*next_str)++;
	while ((*next_str)[i])
	{
		if ((*next_str)[i] == c)
			return ;
		(*next_str_len)++;
		i++;
	}
}

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	i;

	src_len = 0;
	while (src[src_len] != '\0')
	{
		src_len++;
	}
	if (dstsize == 0)
	{
		return (src_len);
	}
	i = 0;
	while (src[i] != '\0' && i < (dstsize - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	**ft_split(char const *s, char c)
{
	char			**tab;
	char			*next_str;
	unsigned int	next_str_len;
	unsigned int	nb_strs;
	unsigned int	i;

	if (!s)
		return (NULL);
	nb_strs = ft_get_nb_strs(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (nb_strs + 1))))
		return (NULL);
	i = 0;
	next_str = (char *)s;
	next_str_len = 0;
	while (i < nb_strs)
	{
		ft_get_next_str(&next_str, &next_str_len, c);
		if (!(tab[i] = (char *)malloc(sizeof(char) * (next_str_len + 1))))
			return (ft_malloc_error(tab));
		ft_strlcpy(tab[i], next_str, next_str_len + 1);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
/*//////////////////////////////////////////////////////////////////////////////////////////////////*/

int	ft_strpos(char *s, char *tocheck)
{
	int		i;
	int		j;
	int		tmp;

	i = 0;
	while (s[i])
	{
		if (s[i] == tocheck[0])
		{
			tmp = i;
			j = 0;
			while (tocheck[j] && s[tmp])
			{
				if (tocheck[j] != s[tmp])
					break ;
				j++;
				tmp++;
			}
			if (!tocheck[j])
				return (i);
		}
		i++;
	}
	return (-1);
}

char	*arg_replace(char *env, char **argv, int pos)
{
	int	i;
	int	j;
	int	k;
	char *final_path;

	i = 0;
	j = 0;
	k = 0;
	final_path = malloc(sizeof(char *) * ((ft_strlen(env) - ft_strlen(argv[1]) + ft_strlen(argv[2])) + 1));
	if (final_path == NULL)
		exit(EXIT_FAILURE);
	while(env[i])
	{
		if (i >= pos && k < ft_strlen(argv[2]))
		{
			final_path[j] = argv[2][k];
			k++;
		}
		else if (k == ft_strlen(argv[2]))
		{
			i = i + ft_strlen(argv[1]);
			j--;
			k++;
		}
		else
		{
			final_path[j] = env[i];
			i++;
		}
		j++;
	}
	final_path[j] = '\0';
	return (final_path);
}

int ft_skip(char *env)
{
	///PAS SUR DE CELLE CI... Comportement chelou
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (env[i] && count <= 2)
	{
		if (env[i] == '/')
			count++;
		i++;
	}
	return (i - 1);
}

int	main(int argc, char *argv[])
{
	DIR				*dp;
	struct dirent	*dirp;
	char			*final_path;

	if (argc > 3)
	{
		printf("cd: too many arguments\n");
		exit(EXIT_FAILURE);
	}
	if (argc == 3)
	{
		if (ft_strpos(getenv("PWD"), argv[1]) >= 0)
			final_path = arg_replace(getenv("PWD"), argv, ft_strpos(getenv("PWD"), argv[1]));
		else
		{
			printf("cd: string not in pwd: %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}
	}
	if (argc == 1)
		dp = opendir(getenv("HOME"));
	else
	{
		if (final_path == NULL)
			dp = opendir(argv[1]);
		else
			dp = opendir(final_path);
	}
	if (dp == NULL)
	{
		if (final_path == NULL)
			printf("cd: no such file or directory: %s", argv[1]);
		else
			printf("cd: no such file or directory: %s", final_path);
		return (0);
	}
	dirp = readdir(dp);
	//PRINT A ENLEVER JUSTE POUR PROUVER QUE L'ONT EST BIEN DANS LE NOUVEAU DOSSIER EN FAISANT UN LS DE CELUI-CI///////
	while (dirp != NULL)
	{
		printf("%s\n", dirp->d_name);
		dirp = readdir(dp);
	}
	///////////////
	closedir(dp);
	if (final_path != NULL)
	{
		printf("~%s\n", (final_path + ft_skip(final_path)));
		free(final_path);
	}
	exit(0);
}
