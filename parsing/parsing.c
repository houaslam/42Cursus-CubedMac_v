/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookair <macbookair@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:55:19 by fadermou          #+#    #+#             */
/*   Updated: 2023/10/04 23:28:25 by macbookair       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	str_lenght(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	s_directions_initialization(t_map **map)
{
	(*map)->directions->f = -1;
	(*map)->directions->c = -1;
	(*map)->directions->ea = NULL;
	(*map)->directions->we = NULL;
	(*map)->directions->no = NULL;
	(*map)->directions->so = NULL;
	(*map)->directions->door = ft_strdup("textures/door.xpm");
}

void	fill_new_map(t_map **map, int s)
{
	char	**new;
	int		i;

	i = 0;
	new = malloc(sizeof(char *) * ((*map)->m_y + 1));
	while ((*map)->map[s] && i < (*map)->m_y + 1)
	{
		new[i] = ft_strdup((*map)->map[s]);
		s++;
		i++;
	}
	new[i] = NULL;
	ft_free((*map)->map);
	(*map)->map = new;
}

void	parsing(t_map *map, char **av)
{
	int	s;

	s = 0;
	read_map(&map, av);
	s_directions_initialization(&map);
	cardinal_directions(&map, &s);
	player_position(&map, s);
	map_dimension(&map, s);
	fill_new_map(&map, s);
	map_parsing(&map);
}
