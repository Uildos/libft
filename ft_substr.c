# include "libft.h"

char *ft_substr(char const *s, unsigned int start,size_t len)
{
	char *substr;
	unsigned	int	i;

	if (!s)
		return (NULL);
	
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (NULL);
	i = 0;
	while ((i < len) && (s[start + i] != '\0'))
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return(substr);
}
