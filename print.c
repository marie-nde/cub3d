/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaude <mnaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 15:15:03 by mnaude            #+#    #+#             */
/*   Updated: 2020/05/05 16:41:51 by mnaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str && str[i])
		ft_putchar(str[i++]);
}

void	ft_print_error_map(t_struct *s_parse, int error)
{
	if (error == 0 && s_parse->map_wall == 1)
		ft_putstr("Warning: The map is not surrounded by walls\n");
	if (error == 0 && s_parse->map_wg_char == 1)
		ft_putstr("Warning: Wrong characters have been found in the map\n");
	if (error == 0 && s_parse->map_end == 1)
		ft_putstr("Warning: The map is not at the end of the file\n");
	if (error == 0 && s_parse->map_dup == 1)
		ft_putstr("Warning: Too much positions have been found in the map\n");
	if (error == 0 && s_parse->map_no_pos == 1)
		ft_putstr("Warning: No position have been found in the map\n");
}

void	ft_print_no_values(t_struct *s_parse, int error)
{
	if (error == 0 && s_parse->resol == 0)
		ft_putstr("Warning: No resolution\n");
	if (error == 0 && s_parse->north == 0)
		ft_putstr("Warning: No north texture\n");
	if (error == 0 && s_parse->south == 0)
		ft_putstr("Warning: No south texture\n");
	if (error == 0 && s_parse->west == 0)
		ft_putstr("Warning: No west texture\n");
	if (error == 0 && s_parse->east == 0)
		ft_putstr("Warning: No east texture\n");
	if (error == 0 && s_parse->sprite == 0)
		ft_putstr("Warning: No sprite texture\n");
	if (error == 0 && s_parse->floor == 0)
		ft_putstr("Warning: No floor color\n");
	if (error == 0 && s_parse->ceiling == 0)
		ft_putstr("Warning: No ceiling color\n");
	if (error == 0 && s_parse->no_map == 1)
		ft_putstr("Warning: No map\n");
}

void	ft_print_wrong_text(t_struct *s_parse, int error)
{
	if (error == 0 && s_parse->north == 3)
		ft_putstr("Warning: Wrong north texture file\n");
	if (error == 0 && s_parse->south == 3)
		ft_putstr("Warning: Wrong south texture file\n");
	if (error == 0 && s_parse->west == 3)
		ft_putstr("Warning: Wrong west texture file\n");
	if (error == 0 && s_parse->east == 3)
		ft_putstr("Warning: Wrong east texture file\n");
	if (error == 0 && s_parse->sprite == 3)
		ft_putstr("Warning: Wrong sprite texture file\n");
}
