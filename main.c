/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 16:39:56 by user42            #+#    #+#             */
/*   Updated: 2020/05/04 16:46:08 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int ac, char **av)
{
	char		*line;
	char		**tab;
	int			i;
	int			fd;
	int			error;

	i = 0;
	error = 0;
	line = NULL;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		error = 1;
	else if (ft_check_cub(av[1]) == 1)
		error = 2;
	if (!(tab = (char**)malloc(sizeof(char*) * 100)))
		return (0);
	while (get_next_line(fd, &line) == 1)
	{
		tab[i] = ft_strdup(line, '\0');
		i++;
	}
	tab[i] = 0;
	ft_check_parsing(tab, error);
	close(fd);
	return (0);
}
