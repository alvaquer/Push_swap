/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaquer <alvaquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:31:34 by alvaquer          #+#    #+#             */
/*   Updated: 2024/02/26 12:41:25 by alvaquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	while (i < len && (start + i < ft_strlen(s)))
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	**freem(char **res, int k)
{
	int	i;

	i = 0;
	if (k > 0)
	{
		while (i <= k)
		{
			free(res[i]);
			i++;
		}
	}
	free(res);
	return (NULL);
}

static int	countwords(char const *s1, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] != c && (i == 0 || s1[i - 1] == c))
		{
			words++;
		}
		i++;
	}
	return (words);
}

static int	nextword(char const *s, char c, int i, char **res)
{
	int	k;

	k = i;
	while (s[i] != c && s[i] != '\0')
		i++;
	*res = ft_substr(s, k, i - k);
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = (char **)malloc((countwords(s, c) + 1) * sizeof(char *));
	if (res == NULL)
		return (freem(res, 0));
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			i = nextword(s, c, i, &res[j]);
			if (res[j] == NULL)
				return (freem(res, j));
			j++;
		}
		else
			i++;
	}
	res[j] = NULL;
	return (res);
}

/* La función `ft_split` divide la cadena `s` en palabras
 separadas por el carácter `c` y devuelve
  un arreglo de estas palabras. */