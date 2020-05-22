# include "libft.h"

size_t	ft_strlcpy(char *dest,const char *src, size_t size)
{
	size_t	n;
	size_t	size_src;

	n = 0;
	if (!src || !dest)
		return(0);
	size_src = ft_strlen(src);
	if ((size != 0) && (dest[n] != '\0'))
	{
		while ((n < size -1) && (src[n] != '\0'))
		{
			dest[n] = src[n];
			n++;
		}
		dest[n] = '\0';
	}
	return size_src;
}

