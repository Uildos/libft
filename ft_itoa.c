/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usoares- <usoares-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 12:29:09 by usoares-          #+#    #+#             */
/*   Updated: 2020/05/22 12:29:26 by usoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*strcopy(char *dest, const char *src, size_t size)
{
	size_t	n;

	n = 0;
	if (!src || !dest)
		return (0);
	if (size != 0)
	{
		while ((n < size - 1) && (src[n] != '\0'))
		{
			dest[n] = src[n];
			n++;
		}
		dest[n] = '\0';
	}
	return (dest);
}

static	int	real_len_nbr(int n)
{
	int div;
	int len;

	len = 1;
	div = n / 10;
	while (div != 0)
	{
		div = div / 10;
		len++;
	}
	if (n < 0)
		len++;
	return (len);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = real_len_nbr(n);
	if (!(str = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	if (n == -2147483648)
	{
		str = (strcopy(str, "-2147483648", 12));
		return (str);
	}
	if (n < 0)
	{
		str[0] = '-';
		str[1] = '\0';
		str = ft_strjoin(str, ft_itoa(-n));
	}
	else if (n >= 10)
		str = ft_strjoin(ft_itoa(n / 10), ft_itoa(n % 10));
	else if (n < 10 && n >= 0)
	{
		str[0] = n + '0';
		str[1] = '\0';
	}
	return (str);
}
