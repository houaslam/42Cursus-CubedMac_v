
#include "parsing.h"

void	check_wall_sides(char *map)
{
	int	i;

	i = ft_strlen(map) - 1;
	while (ft_is_space(map[i]) && i >= 0)
		i--;
	if (map[i] != '1')
		put_error("MAP ISN'T SURROUNDED BY WALLS");
}

void	check_wall_inside(char **map, int i, int j)
{
	if (map[i][j - 1] == ' ' || map[i][j + 1] == ' ' || map[i - 1][j] == ' '
		|| map[i + 1][j] == ' ')
		put_error("MAP ISN'T SURROUNDED BY WALLS");
}

void	check_sides_wall(char *map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		if (!ft_is_player(map[i]))
			put_error("MAP ISN'T SURROUNDED BY WALLS");
		i++;
	}
}

void	check_empty_line(char **str)
{
	int	i;
	int	s;

	i = 0;
	s = 0;
	while (str[i])
	{
		if (str[i][0] == ';' || skipp_spaces(str[i], '1') == -1)
			s = 1;
		else if (str[i][0] != ';' && s)
			put_error("THERE IS AN EMPTY LINE");
		i++;
	}
}

void	map_parsing(t_map **map)
{
	int	j;
	int	i;

	i = 0;
	if ((*map)->map[i])
		check_sides_wall((*map)->map[i]);
	while ((*map)->map[i])
	{
		j = 0;
		while ((*map)->map[i][j])
		{
			if (!ft_is_player((*map)->map[i][j]))
				check_wall_inside((*map)->map, i, j);
			j++;
		}
		i++;
	}
	if ((*map)->map[i])
	{
		i--;
		check_sides_wall((*map)->map[i]);
	}
	check_empty_line((*map)->map);
}
