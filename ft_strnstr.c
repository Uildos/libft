# include "libft.h"

char	*ft_strnstr(const char *big,const char *little, size_t len)
{
	size_t	pos_b;
	size_t	pos_l;


	pos_b = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[pos_b] != '\0' && pos_b < len)
	{
		pos_l = 0;
		while ((pos_b + pos_l) < len && big[pos_b + pos_l] == little[pos_l] && little[pos_l] != '\0')
			pos_l++;
		if (little[pos_l] == '\0')
			return((char *)big + pos_b);
		pos_b++;
	}
	return(NULL);
}
