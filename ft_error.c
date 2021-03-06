/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaude <mnaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 14:53:25 by mnaude            #+#    #+#             */
/*   Updated: 2020/05/05 15:56:38 by mnaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_is_it(char *str)
{
	int i;

	i = 0;
	if (str && str[i])
	{
		if (str[i] == 'R' && str[i + 1] == ' ')
			return (1);
		else if (str[i] == 'N' && str[i + 1] == 'O')
			return (2);
		else if (str[i] == 'S' && str[i + 1] == 'O')
			return (3);
		else if (str[i] == 'W' && str[i + 1] == 'E')
			return (4);
		else if (str[i] == 'E' && str[i + 1] == 'A')
			return (5);
		else if (str[i] == 'S' && str[i + 1] == ' ')
			return (6);
		else if (str[i] == 'F' && str[i + 1] == ' ')
			return (7);
		else if (str[i] == 'C' && str[i + 1] == ' ')
			return (8);
		else if (ft_is_diff(str[i]) == 1)
			return (9);
	}
	return (0);
}

int			ft_double(int a)
{
	if (a == 1 || a == 2)
		return (2);
	return (1);
}

t_struct	*ft_init_struct(t_struct *s_parse)
{
	s_parse->resol = 0;
	s_parse->north = 0;
	s_parse->south = 0;
	s_parse->west = 0;
	s_parse->east = 0;
	s_parse->sprite = 0;
	s_parse->floor = 0;
	s_parse->ceiling = 0;
	s_parse->map_wg_char = 0;
	s_parse->map_end = 0;
	s_parse->map_wall = 0;
	s_parse->map_dup = 0;
	s_parse->map_no_pos = 0;
	s_parse->no_map = 0;
	s_parse->wrong_line = 0;
	return (s_parse);
}

int			ft_map_wall(char *str)
{
	int i;

	i = 0;
	while (str && str[i] && str[i] == ' ')
		i++;
	while (str && str[i] && str[i] == '1')
		i++;
	if (str && str[i] == '\0')
		return (0);
	return (1);
}

int			ft_wall_around(char *str)
{
	int i;

	i = 0;
	while (str && str[i] && str[i] == ' ')
		i++;
	if (str && str[i] && str[i] != '1')
		return (1);
	while (str && str[i])
		i++;
	i--;
	if (str && str[i] != '1')
		return (1);
	return (0);
}
