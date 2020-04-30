#include "cub3d.h"

int		ft_is_pos(char *str)
{
	int i;
	int error;

	i = 0;
	error = 0;
	while (str && str[i])
	{
		if (str[i] == 'N' || str[i] == 'S' || str[i] == 'W' || str[i] == 'E')
			error++;
		i++;
	}
	return (error);
}

int		ft_last_zero(char *str)
{
	int i;

	i = 0;
	while (str && str[i])
		i++;
	while (str && str[i] != '0')
		i--;
	return (i);
}

int		ft_around(char *s1, char *s, char *s2)
{
	int i;

	i = 0;
	while (s && s[i])
		i++;
	while (s && s[i] != '0')
		i--;
	if (i > ft_strlen(s1, '\0'))
		return (1);
	if (i > ft_strlen(s2, '\0'))
		return (1);
	return (0);
}
