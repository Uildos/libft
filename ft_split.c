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

static char	*wfill(const char *str, int start, int finish)
{
	char	*w;
	int		i;

	i = 0;
	w = malloc((finish - start) * sizeof(char));
	while (start < finish)
		w[i++] = str[start++];
	w[i] = '\0';
	return (w);
}

static char	**splitter(char const *s, char **splits, size_t len_s, char c)
{
	size_t	i;
	size_t	j;
	int		w_in;

	i = 0;
	j = 0;
	w_in = -1;
	while (i <= len_s)
	{
		if (s[i] != c && w_in < 0)
			w_in = i;
		else if ((s[i] == c || i == len_s) && w_in >= 0)
		{
			splits[j++] = wfill(s, w_in, i);
			w_in = -1;
		}
		i++;
	}
	splits[j] = NULL;
	return (splits);
}
	
char		**ft_split(char const *s, char c)
{
	char	**splits;
	size_t	len_s;
	int	nb_w;

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
	len_s = ft_strlen(s);
	if (s == NULL)
		splits[0] = NULL;
	else if (c == '\0')
	{
		splits[0] = ft_strdup(s);
		splits[1] = NULL;
	}
	else
		splits = splitter(s, splits, len_s, c);
	return (splits);
}
