# include "libft.h"

char *ft_strchr(const char *s, int c)
{
	const char *p;
	
	p = s;
	while ((*p != c) && (*p != '\0')) 
		p++;
	if (*p == c)
		return((char *)p);
	return (0);
}
