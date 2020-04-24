/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaude <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:10:29 by mnaude            #+#    #+#             */
/*   Updated: 2019/11/15 13:47:44 by mnaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_strlen(char *str, char c)
{
	int i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(new = (char*)malloc(sizeof(char) * ft_strlen(s1, '\0') +
	ft_strlen(s2, '\0') + 1)))
		return (NULL);
	while (s1 && s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
		new[i++] = s2[j++];
	new[i] = '\0';
	free(s1);
	return (new);
}

char	*ft_strdup(char *post_buffer, char c)
{
	char	*new;
	int		i;

	i = 0;
	if (!(new = (char*)malloc(sizeof(char) * ft_strlen(post_buffer, c) + 1)))
		return (NULL);
	while (post_buffer && post_buffer[i] && post_buffer[i] != c)
	{
		new[i] = post_buffer[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strcut(char *post_buffer, char c)
{
	int	i;

	i = 0;
	if (!(post_buffer))
		return (NULL);
	if (ft_isnl(post_buffer, c) == 0)
		return (NULL);
	while (post_buffer[i] != c)
		i++;
	i++;
	return (ft_strdup(post_buffer + i, '\0'));
}
