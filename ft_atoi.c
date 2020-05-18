# include "libft.h"

int	ft_atoi(const char *str)
{
	int i;
	int n;
	int v;

	i = 0;
	n = 0;
	v = 1;
	while ((str[i] == ' ') || (str[i] > 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		v *= -1;
		i++;
	}
	if (str[i] == '+')
		i++;
	while ((str[i] != '\0') && str[i] <= '9' && str[i] >= '0')
	{
		n = n * 10 + str[i] - '0';
		i++;
	}
	return (n * v);
}
