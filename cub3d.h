/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaude <mnaude@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 14:45:45 by mnaude            #+#    #+#             */
/*   Updated: 2020/05/05 15:16:52 by mnaude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define GNL_ERROR -1
# define GNL_NL 1
# define GNL_EOF 0
# define BUFFER_SIZE 4096

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>

typedef struct	s_parse
{
	int resol;
	int north;
	int south;
	int west;
	int east;
	int sprite;
	int floor;
	int ceiling;
	int map_wg_char;
	int map_end;
	int map_wall;
	int map_dup;
	int map_no_pos;
	int no_map;
	int wrong_line;

}				t_struct;

void			ft_putchar(char c);
void			ft_putstr(char *str);
int				get_next_line(int fd, char **line);
int				ft_strlen(char *str, char c);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strdup(char *post_buffer, char c);
char			*ft_strcut(char *post_buffer, char c);
int				ft_isnl(char *str, char c);
t_struct		*ft_init_struct(t_struct *s_parse);
int				ft_double(int a);
int				ft_is_it(char *str);
int				ft_check_parsing(char **tab, int error);
char			**ft_fill_values(char **tab, t_struct *s_parse, char **values,
int i);
int				ft_check_cub(char *str);
int				ft_atoi(char *str);
int				ft_check_resol(char *str);
int				ft_check_file(char *str, int i);
int				ft_check_color(char *str, int i);
char			**ft_fill_map(char **tab, t_struct *s_parse);
t_struct		*ft_check_map(char **map, t_struct *s_parse, int i, int dup);
int				ft_map_wall(char *str);
int				ft_wall_around(char *str);
int				ft_other_char(char *str);
int				ft_is_pos(char *str);
int				ft_around(char *s1, char *s, char *s2);
void			ft_print_error_map(t_struct *s_parse, int error);
void			ft_print_no_values(t_struct *s_parse, int error);
void			ft_print_wrong_text(t_struct *s_parse, int error);
int				ft_is_diff(char c);

#endif
