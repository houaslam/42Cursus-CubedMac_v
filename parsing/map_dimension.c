/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dimension.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookair <macbookair@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 23:05:14 by macbookair        #+#    #+#             */
/*   Updated: 2023/10/04 23:28:19 by macbookair       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	end_of_map(t_map **map)
{
	int	i;
	int	j;

	i = (*map)->m_y;
	j = 0;
	while ((*map)->map[i] && !ft_strcmp((*map)->map[i], ";"))
	{
		i--;
		j++;
	}
	(*map)->m_y = (*map)->m_y - j;
}

char	*ft_join(char *ret, char c)
{
	if (c == '1')
		ret = ft_strjoin(ret, "1");
	else if (c == '0')
		ret = ft_strjoin(ret, "0");
	else if (c == 'N')
		ret = ft_strjoin(ret, "N");
	else if (c == 'E')
		ret = ft_strjoin(ret, "E");
	else if (c == 'S')
		ret = ft_strjoin(ret, "S");
	else if (c == 'W')
		ret = ft_strjoin(ret, "W");
	else if (c == ' ')
		ret = ft_strjoin(ret, " ");
	else if (c == '\t')
		ret = ft_strjoin(ret, "    ");
	else if (c == ';')
		ret = ft_strjoin(ret, ";");
	else if (c == 'D')
		ret = ft_strjoin(ret, "D");
	else
		put_error("INVALID CHARACTER");
	return (ret);
}

char	*ft_fill_it(char *str, t_map **map)
{
	char	*ret;
	int		i;

	ret = ft_strdup("");
	i = 0;
	while (str[i])
	{
		ret = ft_join(ret, str[i]);
		i++;
	}
	while (i < (*map)->m_x)
	{
		if ((int)ft_strlen(ret) < (*map)->m_x)
			ret = ft_strjoin(ret, " ");
		i++;
	}
	free(str);
	return (ret);
}

void	map_dimension(t_map **map, int i)
{
	while ((*map)->map[i])
	{
		(*map)->map[i] = ft_fill_it((*map)->map[i], map);
		i++;
	}
}
