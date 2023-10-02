/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookair <macbookair@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 09:57:05 by fadermou          #+#    #+#             */
/*   Updated: 2023/09/22 13:10:49 by macbookair       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ft_player(t_map *map, int i, int j, int h)
{
	if (map->map[i][j] == 'N' || map->map[i][j] == 'S' \
	|| map->map[i][j] == 'E' || map->map[i][j] == 'W')
	{
		map->p.x = j;
		map->p.y = i - h;
		return (1);
	}
	return (0);
}

void	check_player(int s)
{
	if (!s)
		put_error("WE NEED A PLAYER");
	if (s > 1)
		put_error("TEHRE IS MORE THAN ONE PLAYER");
}

int	ft_len(char *str)
{
	int	i;
	int	ret;

	ret = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\t')
			ret += 3;
		ret++;
		i++;
	}
	return (ret);
}

void	player_position(t_map **map, int i)
{
	int	j;
	int	h;
	int	s;

	s = 0;
	h = i;
	(*map)->m_x = 0;
	while ((*map)->map[i])
	{
		j = 0;
		while ((*map)->map[i][j])
		{
			if (ft_player(*map, i, j, h))
				s++;
			j++;
		}
		if ((int)ft_strlen((*map)->map[i]) > (*map)->m_x)
			(*map)->m_x = ft_len((*map)->map[i]) + 1;
		i++;
	}
	(*map)->m_y = i - h;
	check_player(s);
}

void	check_cardinal(t_directions *dir)
{
	if (!dir->no)
		put_error("NORTH TEXTURE IS MISSING");
	if (!dir->so)
		put_error("SOUTH TEXTURE IS MISSING");
	if (!dir->we)
		put_error("WEST TEXTURE IS MISSING");
	if (!dir->ea)
		put_error("EAST TEXTURE IS MISSING");
	if (dir->c == -1)
		put_error("C COLOR IS MISSING");
	if (dir->f == -1)
		put_error("F COLOR IS MISSING");////remove comment
}
