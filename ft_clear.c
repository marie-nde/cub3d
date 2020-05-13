/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaude <mnaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 16:59:29 by mnaude            #+#    #+#             */
/*   Updated: 2020/05/13 17:19:08 by mnaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_struct2	*ft_clear_struct2(t_struct2 *s_infos)
{
	free(s_infos->north);
	free(s_infos->south);
	free(s_infos->west);
	free(s_infos->east);
	free(s_infos->sprite);
	free(s_infos->floor);
	free(s_infos->ceiling);
	s_infos->map = ft_clear_tab(s_infos->map);
	free(s_infos);
	return (s_infos);
}

char		**ft_clear_tab(char **tab)
{
	int i;

	i = 0;
	while (tab && tab[i])
		free(tab[i++]);
	free(tab);
	return (tab);
}
