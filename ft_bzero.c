#include "libft.h"

void ft_bzero(void *s, size_t len)
{
	if (len)
	{
		ft_memset(s,0,len);
	}
}

