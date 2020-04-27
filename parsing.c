#include "cub3d.h"

t_struct	*ft_get_error(t_struct *s_parse, char **tab)
{
	int i;
	
	i = 0;
	while (tab[i])
	{
		if (ft_is_it(tab[i]) == 1)
			s_parse->resol = ft_double(s_parse->resol);
		else if (ft_is_it(tab[i]) == 2)
			s_parse->north = ft_double(s_parse->north);
		else if (ft_is_it(tab[i]) == 3)
			s_parse->south = ft_double(s_parse->south);
		else if (ft_is_it(tab[i]) == 4)
			s_parse->west = ft_double(s_parse->west);
		else if (ft_is_it(tab[i]) == 5)
			s_parse->east = ft_double(s_parse->east);
		else if (ft_is_it(tab[i]) == 6)
			s_parse->sprite = ft_double(s_parse->sprite);
		else if (ft_is_it(tab[i]) == 7)
			s_parse->floor = ft_double(s_parse->floor);
		else if (ft_is_it(tab[i]) == 8)
			s_parse->ceiling = ft_double(s_parse->ceiling);
		i++;
	}
	return (s_parse);
}

t_struct	*ft_check_error(char **values, t_struct *s_parse)
{
	int i;
	
	i = 0;
	while (values && values[i])
	{
		if (ft_is_it(values[i]) == 1 && s_parse->resol == 1)
			s_parse->resol = ft_check_resol(values[i]);
		else if (ft_is_it(values[i]) == 2 && s_parse->north == 1)
			s_parse->north = ft_check_file(values[i], 3);
		else if (ft_is_it(values[i]) == 3 && s_parse->south == 1)
			s_parse->south = ft_check_file(values[i], 3);
		else if (ft_is_it(values[i]) == 4 && s_parse->west == 1)
			s_parse->west = ft_check_file(values[i], 3);
		else if (ft_is_it(values[i]) == 5 && s_parse->east == 1)
			s_parse->east = ft_check_file(values[i], 3);
		else if (ft_is_it(values[i]) == 6 && s_parse->sprite == 1)
			s_parse->sprite = ft_check_file(values[i], 2);
		else if (ft_is_it(values[i]) == 7 && s_parse->floor == 1)
			s_parse->floor = ft_check_color(values[i], 2);
		else if (ft_is_it(values[i]) == 8 && s_parse->ceiling == 1)
			s_parse->ceiling = ft_check_color(values[i], 2);
		i++;
	}
	return (s_parse);
}

int			ft_check_parsing(t_struct *s_parse, char **tab, int error)
{
	char **values;

	s_parse = ft_init_struct(s_parse);
	s_parse = ft_get_error(s_parse, tab);
	values = ft_fill_values(tab, s_parse);
	s_parse = ft_check_error(values, s_parse);
	return (0);
}
