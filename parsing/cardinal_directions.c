
#include "parsing.h"

char	*ft_dup(char *str)
{
	char	*tmp;
	char	*tmp1;
	char	*ret;

	tmp1 = ft_strtrim(str, " ");
	tmp = ft_strtrim(tmp1, "\t");
	free(tmp1);
	ret = ft_strdup(tmp);
	free(tmp);
	return(ret);
}

char	**split_it(char *map)
{
	char	**spl;

	spl = NULL;
	spl = ft_split(map, '\t');
	if (str_lenght(spl) == 1)
	{
		ft_free(spl);
		spl = ft_split(map, ' ');
	}
	return(spl);
}

int	directions_compar(char *str, t_directions *dir, int *s, int i)
{
	if (!str)
		return (0);
	if (!ft_strcmp(str, "NO"))
	{
		if (dir->no)
			put_error("TOO MANY CARDINAL DIRECTIONS");
		return (NO);
	}
	else if (!ft_strcmp(str, "SO"))
	{
		if (dir->so)
			put_error("TOO MANY CARDINAL DIRECTIONS");
		return (SO);
	}
	else if (!ft_strcmp(str, "WE"))
	{
		if (dir->we)
			put_error("TOO MANY CARDINAL DIRECTIONS");
		return (WE);
	}
	else
		return (ea_and_colors(str, dir, s, i));
	return (0);
}

char	*parse_arg(char *map, int *end)
{
	int		j;
	int		start;
	char	*ret;

	j = 0;
	while (map[j] == ' ' || map[j] == '\t')
		j++;
	start = j;
	while (map[j])
	{
		if (map[j] == ' ' || map[j] == '\t')
			break;
		j++;
	}
	*end = j;
	ret = ft_substr(map, start , *end - start);
	while (map[j] == ' ' || map[j] == '\t')
		j++;
	*end = j;
	return (ret);
}

void	cardinal_directions(t_map **map, int *s)//// after read last note
{
	char	*crdl;
	char	*content;
	int		i;
	int		j;
	int		index;

	i = 0;
	index = 0;
	crdl = NULL;
	content = NULL;
	while ((*map)->map[i])
	{
		crdl = parse_arg((*map)->map[i], &j);
		index = directions_compar(crdl, (*map)->directions, s, i);
		content = ft_substr((*map)->map[i], j, ft_strlen((*map)->map[i]));
		fill_struct(&(*map)->directions, content, index);
		free(crdl);
		free(content);
		i++;
	}
}
//// [DONE]..fill directions with null and whenever it takes a value check if it has null first {split + lenght == 2}
//// [DONE]at the end before i start with map check if my struct has no nall
//// [DONE]don't forget to write "error\n" first
//// [DONE]what if we added a line that has str_lenght == 3
//// [DONE]wtb if we had tabs and spaces
//// [DONE]when i start with map start checkin '0' if it's surronded by space == error first/last line and colones
//// [DONE]check if map has another character !(0 && 1 && E && W && S && N)
//// [DONE]check empty line
//// [DONE]resize map
//// [DONE]m_y and m_x
//// [DONE]check textures in parsing(strtrim(" " && "\t"))
//// [DONE]TEST this -> F    	220,100,0
//// [DONE]I should use substr in parsing
//// [DONE]RGB   
//// [DONE]change gnl
//// [DONE]check leaks
//// I should free when there is an error
//// check norm
//// IF I EDITED IN -> "C 233,   20 8 ,200\n F    0,   100,0" space on g in ceiling changes the color of floor