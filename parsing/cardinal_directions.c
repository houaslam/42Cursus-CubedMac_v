/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cardinal_directions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookair <macbookair@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 23:10:25 by macbookair        #+#    #+#             */
/*   Updated: 2023/10/04 23:28:13 by macbookair       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	return (ret);
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
	return (spl);
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
	return (ea_and_colors(str, dir, s, i));
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
			break ;
		j++;
	}
	*end = j;
	ret = ft_substr(map, start, *end - start);
	while (map[j] == ' ' || map[j] == '\t')
		j++;
	*end = j;
	return (ret);
}

void	cardinal_directions(t_map **map, int *s)
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
