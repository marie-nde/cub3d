#include "cub3d.h"

int		ft_check_cub(char *str)
{
	int i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '.' && str[i + 1] == 'c' && str[i + 2] == 'u' && str[i + 3] == 'b' && str[i + 4] == '\0')
			return (0);
		i++;
	}
	return (1);
}

int		ft_check_resol(char *str)
{
	int i;

	i = 2;
	if (str && str[i])
	{
		if (ft_atoi(str + i) > 0)
		{
			while (str[i] && str[i] >= '0' && str[i] <= '9')
				i++;
			if (str[i] && str[i] == ' ')
			{
				i++;
				if (ft_atoi(str + i) > 0)
					return (1);
			}
		}
	}
	return (3);
}

int		ft_check_file(char *str, int i)
{
	int fd;

	fd = open(str + i, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		return (3);
	}
	close(fd);
	return (1);
}

int		ft_check_color(char *str, int i)
{
	if (str && str[i])
	{
		if (ft_atoi(str + i) >= 0 && ft_atoi(str + i) <= 255)
		{
			while (str[i] && str[i] >= '0' && str[i] <= '9')
				i++;
			if (str[i] && str[i] == ',')
			{
				i++;
				if (ft_atoi(str + i) >= 0 && ft_atoi(str + i) <= 255)
				{
					while (str[i] && str[i] >= '0' && str[i] <= '9')
						i++;
					if (str[i] && str[i] == ',')
					{
						i++;
						if (ft_atoi(str + i) >= 0 && ft_atoi(str + i) < 255)
						{
							while (str[i] && str[i] >= '0' && str[i] <= '9')
								i++;
							if (str[i] == '\0')
								return (1);
						}
					}
				}
			}
		}
	}
	return (3);
}
