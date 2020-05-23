/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usoares- <usoares-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 12:55:10 by usoares-          #+#    #+#             */
/*   Updated: 2020/05/22 12:55:14 by usoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *lit, size_t len)
{
	size_t	b;
	size_t	l;

	b = 0;
	if (lit[0] == '\0')
		return ((char *)big);
	while (big[b] != '\0' && b < len)
	{
		l = 0;
		while ((b + l) < len && big[b + l] == lit[l] && lit[l] != '\0')
			l++;
		if (lit[l] == '\0')
			return ((char *)big + b);
		b++;
	}
	return (NULL);
}
