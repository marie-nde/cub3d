#include "cub3d.h"

char	**ft_fill_values(char **tab, t_struct *s_parse)
{
	int i;
	int j;
	char **values;

	i = 0;
	j = 0;
	if (!(values = (char**)malloc(sizeof(char*) * 9)))
		return (NULL);
	while (tab[i])
	{
		if (ft_is_it(tab[i]) == 1 && s_parse->resol == 1)
			values[j++] = ft_strdup(tab[i], '\0');
		else if (ft_is_it(tab[i]) == 2 && s_parse->north == 1)
			values[j++] = ft_strdup(tab[i], '\0');
		else if (ft_is_it(tab[i]) == 3 && s_parse->south == 1)
			values[j++] = ft_strdup(tab[i], '\0');
		else if (ft_is_it(tab[i]) == 4 && s_parse->west == 1)
			values[j++] = ft_strdup(tab[i], '\0');
		else if (ft_is_it(tab[i]) == 5 && s_parse->east == 1)
			values[j++] = ft_strdup(tab[i], '\0');
		else if (ft_is_it(tab[i]) == 6 && s_parse->sprite == 1)
			values[j++] = ft_strdup(tab[i], '\0');
		else if (ft_is_it(tab[i]) == 7 && s_parse->floor == 1)
			values[j++] = ft_strdup(tab[i], '\0');
		else if (ft_is_it(tab[i]) == 8 && s_parse->ceiling == 1)
			values[j++] = ft_strdup(tab[i], '\0');
		i++;
	}
	values[j] = 0;
	return (values);
}

char	**ft_fill_map(char **tab, t_struct *s_parse)
{
	int i;
	int j;
	char **map;

	i = 0;
	j = 0;
	if (!(map = (char**)malloc(sizeof(char*) * 100)))
		return (NULL);
	while (tab && tab[i])
	{
		if (tab[i][0] == '1' || tab[i][0] == '0' || tab[i][0] == '2')
		{
			while (tab[i])
				map[j++] = ft_strdup(tab[i++], '\0');
			map[j] = 0;
			break ;
		}
		i++;
	}
	return (map);
}
