#include "cub3d.h"

int		ft_other_char(char *str)
{
	int i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] && str[i] != '1' && str[i] != '0' && str[i] != 'N' && str[i] != 'S' && str[i] != 'W' && str[i] != 'E')
			return (1);
		i++;
	}
	return (0);
}
