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

void		ft_print_error(int error, t_struct *s_parse)
{
	if (error > 0 || s_parse->resol != 1 || s_parse->north != 1 || s_parse->south != 1 || s_parse->west != 1 || s_parse->east != 1 || s_parse->sprite != 1 || s_parse->floor != 1 || s_parse->ceiling != 1)
		ft_putstr("Error\n");
	if (error == 1)
		ft_putstr("Warning: No such file or directory\n");
	else if (error == 2)
		ft_putstr("Warning: Wrong map file extension\n");
	if (s_parse->resol == 2 || s_parse->north == 2 || s_parse->south == 2 || s_parse->west == 2 || s_parse->east == 2 || s_parse->sprite == 2 || s_parse->floor == 2 || s_parse->ceiling == 2)
		ft_putstr("Warning: Duplications have been found in the map file\n");
	if (s_parse->resol == 3)
		ft_putstr("Warning: Wrong resolution\n");
	if (s_parse->north == 3 || s_parse->south == 3 || s_parse->west == 3 || s_parse->east == 3)
		ft_putstr("Warning: Wrong texture file(s)\n");
	if (s_parse->floor == 3 || s_parse->ceiling == 3)
		ft_putstr("Warning: Wrong color format\n");
}

int			ft_check_parsing(t_struct *s_parse, char **tab, int error)
{
	char **values;
	char **map;

	s_parse = ft_init_struct(s_parse);
	s_parse = ft_get_error(s_parse, tab);
	values = ft_fill_values(tab, s_parse);
	map = ft_fill_map(tab, s_parse);
	s_parse->map = ft_parse_map(map);
	printf("%d", s_parse->map);
	s_parse = ft_check_error(values, s_parse);
	ft_print_error(error, s_parse);
	return (0);
}
