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

}				t_struct;

void		ft_putchar(char c);
void		ft_putstr(char *str);
int			get_next_line(int fd, char **line);
int			ft_strlen(char *str, char c);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(char *post_buffer, char c);
char		*ft_strcut(char *post_buffer, char c);
int			ft_isnl(char *str, char c);
t_struct	*ft_init_struct(t_struct *s_parse);
int			ft_double(int a);
int			ft_is_it(char *str);
int			ft_check_parsing(t_struct *s_parse, char **tab, int error);
char		**ft_fill_values(char **tab, t_struct *s_parse);
int			ft_check_cub(char *str);
int			ft_atoi(char *str);
int			ft_check_resol(char *str);
int			ft_check_file(char *str, int i);
int			ft_check_color(char *str, int i);
char		**ft_fill_map(char **tab, t_struct *s_parse);
t_struct	*ft_check_map(char **map, t_struct *s_parse);
int			ft_map_wall(char *str);
int			ft_wall_around(char *str);
int			ft_other_char(char *str);
int			ft_is_pos(char *str);
int			ft_around(char *s1, char *s, char *s2);

#endif
