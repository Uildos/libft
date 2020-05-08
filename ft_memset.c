
#include <unistd.h>
#include <stdio.h>

void *memset(void *s, int c, size_t len)
{
	size_t	i;
	unsigned	char	*ptr;
	
	ptr = (unsigned char *)s;
	i = 0;
	while (i < len)
	{
		*ptr = (unsigned char)c;
		ptr++;
		i++;
	}
	return(s);
}
