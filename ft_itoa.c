# include "libft.h"

char	*strcopy(char *dest,const char *src, size_t size)
{
	size_t	n;

	n = 0;
	if (!src || !dest)
		return(0);
	if (size != 0)
	{
		while ((n < size -1) && (src[n] != '\0'))
		{
			dest[n] = src[n];
			n++;
		}
		dest[n] = '\0';
	}
	return (dest);
}
char *ft_itoa(int n)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	if (n == -2147483648)
		return (strcopy(str, "-2147483648", 12));
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
