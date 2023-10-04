/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distances.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajarouaslam <hajarouaslam@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:02:14 by houaslam          #+#    #+#             */
/*   Updated: 2023/10/04 12:11:52 by hajarouasla      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int	check_case_h(t_map *map)
{
	map->n_h = 1;
	if (map->h.y < 0 || map->h.x / UNIT >= map->m_x \
	|| map->h.x < 0 || map->h.y / UNIT >= map->m_y)
		return (0);
	map->n_h = 0;
	if (map->map[(int)(map->h.y - map->r.up) / UNIT][(int)map->h.x \
	/ UNIT] == '1')
	{
		map->r.content = WALL;
		return (0);
	}
	else if (map->map[(int)(map->h.y - map->r.up) / UNIT][(int)map->h.x \
	/ UNIT] == 'D')
	{
		map->r.content = DOOR;
		return (0);
	}
	return (1);
}

int	check_case_v(t_map *map)
{
	map->n_v = 1;
	if (map->v.y < 0 || map->v.x / UNIT >= map->m_x \
	|| map->v.x / UNIT < 0 || map->v.y / UNIT >= map->m_y)
		return (0);
	map->n_v = 0;
	if (map->map[(int)map->v.y / UNIT][((int)map->v.x - map->r.left) \
	/ UNIT] == '1')
	{
		map->r.content = WALL;
		return (0);
	}
	else if (map->map[(int)map->v.y / UNIT][((int)map->v.x - map->r.left) \
	/ UNIT] == 'D')
	{
		map->r.content = DOOR;
		return (0);
	}
	return (1);
}

float	p_to_wall(t_map *map)
{
	float	x;
	float	y;
	float	h;
	float	v;

	map->r.content = WALL;
	y = map->p.u_y - map->h.y;
	x = map->p.u_x - map->h.x;
	h = sqrt(pow(x, 2) + pow(y, 2));
	y = map->p.u_y - map->v.y;
	x = map->p.u_x - map->v.x;
	v = sqrt(pow(x, 2) + pow(y, 2));
	if (map->n_h || h >= v)
	{
		map->vert = true;
		if (check(map, ((int)map->v.x - map->r.left) / UNIT, (int)map->v.y / UNIT) == 2)
		{
			map->r.content = DOOR;
			map->r.d_y = (int)map->v.y / UNIT;
			map->r.d_x = ((int)map->v.x - map->r.left) / UNIT;
		}
		return (v * cos((map->r.ang - map->r.cast) * M_PI / 180));
	}
	map->vert = false;
	if (check(map, (int)map->h.x / UNIT, (int)(map->h.y - map->r.up) / UNIT) == 2)
	{
		map->r.content = DOOR;
		map->r.d_y = (int)(map->h.y - map->r.up) / UNIT;
		map->r.d_x = (int)map->h.x / UNIT;
	}
	return (h * cos((map->r.ang - map->r.cast) * M_PI / 180));
}

float	wall_height(t_map *map)
{
	double	b;
	double	ret;

	b = (PP_WIDTH / 2) / tan((VIEW_D / 2) * (M_PI / 180));
	ret = (UNIT * b) / map->r.distance;
	return (ret);
}
