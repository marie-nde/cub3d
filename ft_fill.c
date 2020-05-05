/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaude <mnaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 14:58:00 by mnaude            #+#    #+#             */
/*   Updated: 2020/05/05 16:26:48 by mnaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**ft_fill_values(char **tab, t_struct *s_parse, char **values, int i)
{
	int j;

	j = 0;
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

int		ft_space_before(char *str)
{
	int i;

	i = 0;
	if (str[i] == ' ')
	{
		while (str[i] == ' ')
		{
			if (str[i] == '1' || str[i] == '0' || str[i] == '2')
				return (1);
			i++;
		}
	}
	if (str[i] == '1' || str[i] == '0' || str[i] == '2')
		return (1);
	return (0);
}

char	**ft_fill_map(char **tab)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	j = 0;
	if (!(map = (char**)malloc(sizeof(char*) * 100)))
		return (NULL);
	while (tab && tab[i])
	{
		if (ft_space_before(tab[i]) == 1)
		{
			while (tab[i])
				map[j++] = ft_strdup(tab[i++], '\0');
			break ;
		}
		i++;
	}
	map[j] = 0;
	return (map);
}
