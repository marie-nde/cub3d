#include "cub3d"

int		ft_check_resol(char **values, int a)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (a == 2)
		return (2);
	while (values[i])
	{
		if (values[i][0] == 'R')
		{
			j = 2;
			if (values[i][j] && ft_atoi(values[i] + j > 0))
			{
				while (values[i][j] && values[i][j] >= '0' && values[i][j] <= '9')
				{
					j++;
					if (values[i][j] && values[i][j] == ' ')
					{
						j++;
						if (values[i][j] && ft_atoi(values[i] + j > 0))
							return (1);
					}
				}
			}
		}
		i++;
	}
	return (2);
}
