# include "libft.h"

size_t	ft_strlcpy(char *dest,const char *src, size_t size)
{
	size_t	n;

	n = 0;
	while (n < size -1)
	{
		dest[n] = src[n];
		n++;
	}
	dest[n] = '\0';
	return (ft_strlen(src));
}

