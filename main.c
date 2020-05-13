/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaude <mnaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 14:45:32 by mnaude            #+#    #+#             */
/*   Updated: 2020/05/13 18:47:59 by mnaude           ###   ########.fr       */
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
	t_struct2	*s_infos;

	i = 0;
	error = 0;
	line = NULL;
	(void)ac;
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
		free(line);
		i++;
	}
	tab[i] = 0;
	free(line);
	if (ft_check_parsing(tab, error) == 1)
	{
		close(fd);
		tab = ft_clear_tab(tab);
		return (0);
	}
	if (!(s_infos = malloc(sizeof(t_struct2))))
		return (0);
	s_infos = ft_fill_infos(s_infos, tab, 0);
	close(fd);
	tab = ft_clear_tab(tab);
	void *init;
	void *win;
	if ((init = mlx_init()) == NULL)
		return (0);
	win = mlx_new_window(init, s_infos->x, s_infos->y, "Falut fa va");
	if (win == NULL)
		return (0);
	mlx_loop(init);
	ft_clear_struct2(s_infos);
	return (0);
}
