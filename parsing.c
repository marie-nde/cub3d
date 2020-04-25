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

int			ft_check_parsing(t_struct *s_parse, char **tab)
{
	s_parse = ft_init_struct(s_parse);
	s_parse = ft_get_error(s_parse, tab);
}
