/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usoares- <usoares-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 12:53:31 by usoares-          #+#    #+#             */
/*   Updated: 2020/05/22 12:53:32 by usoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	n;
	size_t	len_dest;

	n = 0;
	len_dest = ft_strlen(dest);
	if (size <= len_dest)
		return (size + ft_strlen(src));
	while ((n < size - len_dest - 1) && (src[n] != '\0'))
	{
		dest[len_dest + n] = src[n];
		n++;
	}
	dest[len_dest + n] = '\0';
	return (len_dest + ft_strlen(src));
}
