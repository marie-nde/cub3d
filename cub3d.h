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

typedef struct	s_parse
{
	char *resol;
	char *north;
	char *south;
	char *west;
	char *east;
	char *sprite;
	char *floor;
	char *ceiling;
	char **map;
}				t_struct;

void	ft_putchar(char c);
void	ft_putstr(char *str);
char	*ft_check_parsing(t_struct *s_parse, char *line);
int		get_next_line(int fd, char **line);
int		ft_strlen(char *str, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *post_buffer, char c);
char	*ft_strcut(char *post_buffer, char c);
int		ft_isnl(char *str, char c);


#endif
