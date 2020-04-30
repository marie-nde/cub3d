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

void	ft_print_error_map(t_struct *s_parse)
{
	if (s_parse->map_wall == 1)
		ft_putstr("Warning: The map is not surrounded by walls\n");
	if (s_parse->map_wg_char == 1)
		ft_putstr("Warning: One or more wrong characters have been found in the map\n");
	if (s_parse->map_end == 1)
		ft_putstr("Warning: The map is not at the end of the file\n");
	if (s_parse->map_dup == 1)
		ft_putstr("Warning: Two or more positions have been found in the map\n");
	if (s_parse->map_no_pos == 1)
		ft_putstr("Warning: No position have been found in the map\n");
}
