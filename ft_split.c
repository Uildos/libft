/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usoares- <usoares-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 12:52:16 by usoares-          #+#    #+#             */
/*   Updated: 2020/05/22 12:52:24 by usoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wmeter(char const *s, char c)
{
	size_t	i;
	int		nb_w;

	i = 0;
	nb_w = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			nb_w++;
			while ((s[i] != c) && (s[i] != '\0'))
				i++;
		}
		else
			i++;
	}
	return (nb_w);
}

static void	freeall(char **array, int i)
{
	while (i > -1)
	{
		free(array[i]);
		i--;
	}
	free(array);
}

static char	**splitter(char **splits, size_t len, const char *s, char c)
{
	size_t	i;
	size_t	start;
	size_t	end;

	i = 0;
	start = 0;
	while (i < len - 1)
	{
		while (s[start] == c)
			start++;
		end = start;
		while (s[end] != c && s[end] != '\0')
			end++;
		if (!(splits[i] = (char *)malloc((end - start + 1) * sizeof(char))))
		{
			freeall(splits, i - 1);
			return (NULL);
		}
		ft_strlcpy(splits[i], &s[start], end - start + 1);
		start = end;
		i++;
	}
	splits[len - 1] = NULL;
	return (splits);
}

char		**ft_split(char const *s, char c)
{
	char	**splits;
	int		nb_w;

	if (!s)
		return (NULL);
	if (*s == '\0')
		nb_w = 0;
	else if (c == '\0')
		nb_w = 1;
	else
		nb_w = wmeter(s, c);
	if (!(splits = malloc((nb_w + 1) * sizeof(char *))))
		return (NULL);
	if (*s == '\0')
		splits[0] = NULL;
	else if (c == '\0')
	{
		splits[0] = ft_strdup(s);
		splits[1] = NULL;
	}
	else
		splits = splitter(splits, nb_w + 1, s, c);
	return (splits);
}
