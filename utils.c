#include "cub3d.h"

int		ft_atoi(char *str)
{
	long	nb;
	int		i;
	int		neg;

	nb = 0;
	i = 0;
	neg = 1;
	if (!str)
		return (0);
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		nb = nb * 10 + (str[i++] - '0');
	if ((unsigned)nb > 2147483647 && neg == 1)
		return (-1);
	return (nb * neg);
}
