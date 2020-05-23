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

char		**ft_split(char const *s, char c)
{
	size_t	i;
	char	**splits;
	size_t	j;
	int		w_in;

	if (!s || !(splits = malloc((wmeter(s, c) + 1) * sizeof(char *))))
		return (0);
	if (!splits)
		return (0);
	i = 0;
	j = 0;
	w_in = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && w_in < 0)
			w_in = i;
		else if ((s[i] == c || i == ft_strlen(s)) && w_in >= 0)
		{
			splits[j++] = wfill(s, w_in, i);
			w_in = -1;
		}
		i++;
	}
	splits[j] = 0;
	return (splits);
}
