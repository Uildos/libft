# include "libft.h"

char *ft_strtrim(char const *s1, char const *set)
{
	int i;
	int j;

	i = 0;
	if (!s1 || !set)
		return (0);
	j = ft_strlen(s1) - 1;
	while((s1[i] != '\0') && (ft_strchr(set, s1[i])))
		i++;
	while((j > i ) && (ft_strchr(set, s1[j])))
		j--;
	return(ft_substr(s1, i,j - i + 1));
}
