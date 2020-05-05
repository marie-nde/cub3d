/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaude <mnaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 15:02:43 by mnaude            #+#    #+#             */
/*   Updated: 2020/05/05 15:10:20 by mnaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_other_char(char *str)
{
	int i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] && str[i] != '1' && str[i] != '0' && str[i] != '2' && str[i]
			!= 'N' && str[i] != 'S' && str[i] != 'W' && str[i] != 'E')
			return (1);
		i++;
	}
	return (0);
}

t_struct	*ft_check_map_2(t_struct *s_parse, int dup, char *str)
{
	if (dup > 1)
		s_parse->map_dup = 1;
	if (dup == 0)
		s_parse->map_no_pos = 1;
	if (str != 0)
		s_parse->map_end = 1;
	return (s_parse);
}

t_struct	*ft_check_map(char **map, t_struct *s_parse, int i, int dup)
{
	if (map[0] == 0)
		s_parse->no_map = 1;
	else
	{
		while (map && map[i] && (map[i][0] == '1' || map[i][0] == '0' ||
			map[i][0] == '2'))
		{
			if ((i == 0 && ft_map_wall(map[i]) == 1) || ft_wall_around(map[i])
				== 1)
				s_parse->map_wall = 1;
			if (map[i + 1] == 0)
				if (ft_map_wall(map[i]) == 1)
					s_parse->map_wall = 1;
			if (i > 0 && map[i + 1] != 0 && ft_around(map[i - 1], map[i],
				map[i + 1]) == 1)
				s_parse->map_wall = 1;
			if (ft_other_char(map[i]) == 1)
				s_parse->map_wg_char = 1;
			if (ft_is_pos(map[i]) > 0)
				dup = dup + ft_is_pos(map[i]);
			i++;
		}
		s_parse = ft_check_map_2(s_parse, dup, map[i]);
	}
	return (s_parse);
}
