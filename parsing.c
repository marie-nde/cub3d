#include "cub3d.h"

char	*ft_check_parsing(t_struct *s_parse, char *line)
{
	int i;

	i = 0;
	if (line[i] == 'R')
	{
		i = i + 2;
		if (s_parse->resol != NULL)
			return ("Error");
		return (ft_strdup(line + i, '\0'));
	}
	if (line[i] == 'N' && line[i + 1] == 'O')
	{
		i = i + 3;
		if (s_parse->north != NULL)
			return ("Error");
		return (ft_strdup(line + i, '\0'));
	}
	if (line[i] == 'S' && line[i + 1] == 'O')
	{
		i = i + 3;
		if (s_parse->south != NULL)
			return ("Error");
		return (ft_strdup(line + i, '\0'));
	}
	if (line[i] == 'W' && line[i + 1] == 'E')
	{
		i = i + 3;
		if (s_parse->west != NULL)
			return ("Error");
		return (ft_strdup(line + i, '\0'));
	}
	if (line[i] == 'E' && line[i + 1] == 'A')
	{
		i = i + 3;
		if (s_parse->east != NULL)
			return ("Error");
		return (ft_strdup(line + i, '\0'));
	}
	if (line[i] == 'S')
	{
		i = i + 2;
		if (s_parse->sprite != NULL)
			return ("Error");
		return (ft_strdup(line + i, '\0'));
	}
	if (line[i] == 'F')
	{
		i = i + 2;
		if (s_parse->floor != NULL)
			return ("Error");
		return (ft_strdup(line + i, '\0'));
	}
	if (line[i] == 'C')
	{
		i = i + 2;
		if (s_parse->ceiling != NULL)
			return ("Error");
		return (ft_strdup(line + i, '\0'));
	}
	return (NULL);
}
