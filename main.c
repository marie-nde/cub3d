#include "cub3d.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	t_struct *s_parse;
	char *line;
	char **tab;
	int i;
	int fd;

	i = 0;
	line = NULL;
	fd = open(av[1], O_RDONLY);
	if (!(tab = (char**)malloc(sizeof(char*) * 100)))
		return (0);
	while (get_next_line(fd, &line) == 1)
	{
		tab[i] = ft_strdup(line, '\0');
		i++;
	}
	tab[i] = NULL;
	if (!(s_parse = malloc(sizeof(t_struct))))
		return (0);
/*	if (ft_check_parsing(s_parse, fill) == 1)
		return (0);*/
	close(fd);
	return (0);
}
