# include "libft.h"

char *ft_strdup(const char *s)
{
	size_t	i;
	char	*cp_s;
	size_t	len;

	len = ft_strlen(s);
	cp_s = (char *)malloc((len + 1 * sizeof(char)));
	if (!cp_s)
		return(NULL);
	i = 0;
	while ((i < len) && (s[i] != '\0'))
	{
		cp_s[i] = s[i];
		i++;
	}
	cp_s[i] = '\0';
	if (sizeof(cp_s) == 0)
		return(NULL);
	else
		return(cp_s);
}

