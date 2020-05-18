#include "libft.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	unsigned	char	*temp_dest;
	unsigned	char	*temp_src;
	
	temp_dest = (unsigned char *)dest;
	temp_src = (unsigned char *)src;
	if (dest == src)
		return (dest);
	i = 0;
	while (i < n)
	{
		*temp_dest = *temp_src;
		temp_dest++;
		temp_src++;
		i++;
	}
	return(dest);
}
