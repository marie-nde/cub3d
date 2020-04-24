/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaude <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:29:47 by mnaude            #+#    #+#             */
/*   Updated: 2019/11/15 12:14:36 by mnaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_isnl(char *str, char c)
{
	int i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		ft_move(char **post_buffer, char **line, char c)
{
	void *temp;

	temp = *post_buffer;
	*line = ft_strdup(*post_buffer, c);
	*post_buffer = ft_strcut(*post_buffer, c);
	free(temp);
	if (c == '\n')
		return (GNL_NL);
	else if (c == '\0')
		return (GNL_EOF);
	return (GNL_ERROR);
}

int		ft_read(char **post_buffer, char **line, int fd)
{
	char	buff[BUFFER_SIZE + 1];
	int		ret;

	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		if (ret == -1)
			break ;
		buff[ret] = '\0';
		*post_buffer = ft_strjoin(*post_buffer, buff);
		if (ft_isnl(buff, '\n') == 1)
			break ;
	}
	if (ret >= 0 && ft_isnl(*post_buffer, '\n') == 1)
		return (ft_move(post_buffer, line, '\n'));
	if (ret == 0 && BUFFER_SIZE > 0)
		return (ft_move(post_buffer, line, '\0'));
	return (GNL_ERROR);
}

int		get_next_line(int fd, char **line)
{
	static char *post_buffer[200000];

	if (line == NULL)
		return (GNL_ERROR);
	if (fd >= 0 && !(post_buffer[fd]))
	{
		if (!(post_buffer[fd] = (char*)malloc(1)))
			return (GNL_ERROR);
		post_buffer[fd][0] = '\0';
	}
	if (fd >= 0 && ft_isnl(post_buffer[fd], '\n') == 1)
		return (ft_move(&post_buffer[fd], line, '\n'));
	if (fd >= 0)
		return (ft_read(&post_buffer[fd], line, fd));
	return (GNL_ERROR);
}
