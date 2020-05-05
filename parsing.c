/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 16:36:40 by user42            #+#    #+#             */
/*   Updated: 2020/05/05 16:18:18 by mnaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_error(t_struct *s_parse)
{
	if (s_parse->resol != 1 || s_parse->north != 1 || s_parse->south != 1 ||
		s_parse->west != 1 || s_parse->east != 1 || s_parse->sprite != 1 ||
		s_parse->floor != 1 || s_parse->ceiling != 1 || s_parse->no_map != 0 ||
		s_parse->map_wg_char != 0 || s_parse->map_end != 0 || s_parse->map_wall
		!= 0 || s_parse->map_dup != 0 || s_parse->map_no_pos != 0 ||
		s_parse->wrong_line != 0)
		return (1);
	return (0);
}

t_struct	*ft_get_error(t_struct *s_parse, char **tab, int i)
{
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
		else if (ft_is_it(tab[i]) == 9)
			s_parse->wrong_line = 1;
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
	if (error > 0 || s_parse->resol != 1 || s_parse->north != 1 ||
		s_parse->south != 1 || s_parse->west != 1 || s_parse->east != 1
		|| s_parse->sprite != 1 || s_parse->floor != 1 || s_parse->ceiling
		!= 1 || s_parse->map_wg_char == 1 || s_parse->map_end == 1 ||
		s_parse->map_wall == 1 || s_parse->map_dup == 1 ||
		s_parse->map_no_pos == 1 || s_parse->no_map == 1 ||
		s_parse->wrong_line == 1)
		ft_putstr("Error\n");
	if (error == 1)
		ft_putstr("Warning: No such file or directory\n");
	else if (error == 2)
		ft_putstr("Warning: Wrong file extension\n");
	ft_print_no_values(s_parse, error);
	if (s_parse->wrong_line == 1 && error == 0)
		ft_putstr("Warning: One or more unidentified lines have been found\n");
	if (error == 0 && (s_parse->resol == 2 || s_parse->north == 2 ||
		s_parse->south == 2 || s_parse->west == 2 || s_parse->east == 2 ||
		s_parse->sprite == 2 || s_parse->floor == 2 || s_parse->ceiling == 2))
		ft_putstr("Warning: Duplications have been found in the map file\n");
	if (s_parse->resol == 3 && error == 0)
		ft_putstr("Warning: Wrong resolution\n");
	ft_print_wrong_text(s_parse, error);
	if (error == 0 && (s_parse->floor == 3 || s_parse->ceiling == 3))
		ft_putstr("Warning: Wrong color format\n");
	ft_print_error_map(s_parse, error);
}

int			ft_check_parsing(char **tab, int error)
{
	char		**values;
	char		**map;
	t_struct	*s_parse;

	if (!(s_parse = malloc(sizeof(t_struct))))
		return (0);
	if (!(values = (char**)malloc(sizeof(char*) * 9)))
		return (0);
	s_parse = ft_init_struct(s_parse);
	s_parse = ft_get_error(s_parse, tab, 0);
	values = ft_fill_values(tab, s_parse, values, 0);
	map = ft_fill_map(tab);
	s_parse = ft_check_error(values, s_parse);
	s_parse = ft_check_map(map, s_parse, 0, 0);
	ft_print_error(error, s_parse);
	free(map);
	free(values);
	if (ft_error(s_parse) == 1)
	{
		free(s_parse);
		return (1);
	}
	free(s_parse);
	return (0);
}
