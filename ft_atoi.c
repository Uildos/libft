# include "libft.h"

int	ft_atoi(const char *str)
{
	int i;
	long	int n;
	int v;

	i = 0;
	n = 0;
	v = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ||
			str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			v = -1;
		i++;
	}
	while ((str[i] != '\0') && str[i] <= '9' && str[i] >= '0')
	{
		n = n * 10 + str[i] - '0';
		i++;
	}
	return (n * v);
}
