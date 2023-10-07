/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distances.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookair <macbookair@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:02:14 by houaslam          #+#    #+#             */
/*   Updated: 2023/10/04 22:58:24 by macbookair       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int	check_case_h(t_map *map)
{
	map->n_h = 1;
	if (map->h.y < 0 || map->h.x / UNIT >= map->m_x || map->h.x < 0 || map->h.y
		/ UNIT >= map->m_y)
		return (0);
	map->n_h = 0;
	if (map->map[(int)(map->h.y - map->r.up) / UNIT][(int)map->h.x
		/ UNIT] == '1')
		return (0);
	else if (map->map[(int)(map->h.y - map->r.up) / UNIT][(int)map->h.x
		/ UNIT] == 'D')
		return (0);
	return (1);
}

int	check_case_v(t_map *map)
{
	map->n_v = 1;
	if (map->v.y < 0 || map->v.x / UNIT >= map->m_x || map->v.x / UNIT < 0
		|| map->v.y / UNIT >= map->m_y)
		return (0);
	map->n_v = 0;
	if (map->map[(int)map->v.y / UNIT][((int)map->v.x - map->r.left)
		/ UNIT] == '1')
		return (0);
	else if (map->map[(int)map->v.y / UNIT][((int)map->v.x - map->r.left)
		/ UNIT] == 'D')
		return (0);
	return (1);
}

int	*calcul_distance(t_map *map)
{
	int		*dist;
	float	x;
	float	y;

	dist = malloc(sizeof(int) * 2);
	map->r.content = WALL;
	y = map->p.u_y - map->h.y;
	x = map->p.u_x - map->h.x;
	dist[0] = sqrt(pow(x, 2) + pow(y, 2));
	y = map->p.u_y - map->v.y;
	x = map->p.u_x - map->v.x;
	dist[1] = sqrt(pow(x, 2) + pow(y, 2));
	return (dist);
}

float	p_to_wall(t_map *map)
{
	int	*dis;
	int	res;

	dis = calcul_distance(map);
	if (map->n_h || dis[0] >= dis[1])
	{
		map->vert = true;
		if (check(map, (map->v.x - map->r.left) / UNIT, map->v.y / UNIT) == 2)
		{
			map->r.d_y = (int)map->v.y / UNIT;
			map->r.d_x = ((int)map->v.x - map->r.left) / UNIT;
		}
		res = dis[1] * cos((map->r.ang - map->r.cast) * M_PI / 180);
		free(dis);
		return (res);
	}
	map->vert = false;
	if (check(map, map->h.x / UNIT, (map->h.y - map->r.up) / UNIT) == 2)
	{
		map->r.d_y = (int)(map->h.y - map->r.up) / UNIT;
		map->r.d_x = (int)map->h.x / UNIT;
	}
	res = dis[0] * cos((map->r.ang - map->r.cast) * M_PI / 180);
	free(dis);
	return (res);
}

float	wall_height(t_map *map)
{
	double	b;
	double	ret;

	b = (PP_WIDTH / 2) / tan((VIEW_D / 2) * (M_PI / 180));
	ret = (UNIT * b) / map->r.distance;
	return (ret);
}
