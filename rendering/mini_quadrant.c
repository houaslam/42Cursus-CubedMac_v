/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_quadrant.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 09:54:58 by houaslam          #+#    #+#             */
/*   Updated: 2023/10/01 14:54:27 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/raycasting.h"

// void	draw_player(t_map *map)
// {
// 	int	x;
// 	int	y;

// 	y = map->minimap.height / 2;
// 	while (y > map->minimap.height / 2 - 15)
// 	{
// 		x = map->minimap.width / 2 + MINI_UNIT / 2;
// 		while (x < map->minimap.width / 2 + MINI_UNIT / 2 + 2)
// 			my_mlx_pixel_put(&map->mini, x++, y, 225111);
// 		y--;
// 	}
// 	draw_square(225111, map->minimap.width / 2, 
// 	map->minimap.height / 2, map->window);
// }

void	keep_adding(t_map *map)
{
	check_angles(map);
	if (map->r.ang >= 0 && map->r.ang <= 90)
	{
		map->minimap.x += cos(map->r.ang * M_PI / 180);
		map->minimap.y -= sin(map->r.ang * M_PI / 180);
	}
	else if (map->r.ang > 90 && map->r.ang <= 180)
	{
		map->minimap.x -= sin((map->r.ang - 90) * M_PI / 180);
		map->minimap.y -= cos((map->r.ang - 90) * M_PI / 180);
	}
	else if (map->r.ang > 180 && map->r.ang <= 270)
	{
		map->minimap.x -= cos((map->r.ang - 180) * M_PI / 180);
		map->minimap.y += sin((map->r.ang - 180) * M_PI / 180);
	}
	else if (map->r.ang > 270 && map->r.ang <= 360)
	{
		map->minimap.x += sin((map->r.ang - 270) * M_PI / 180);
		map->minimap.y += cos((map->r.ang - 270) * M_PI / 180);
	}
}

int	check_tip(t_map *map, int y)
{
	if (y < 0)
		return (0);
	else if (map->minimap.y <= 0 && map->minimap.x <= 0)
		return (0);
	else if (map->minimap.y >= map->minimap.height)
		return (0);
	else if (map->minimap.x >= map->minimap.width)
		return (0);
	return (1);
}

void	mini_quadrant(t_map *map)
{
	int		k;
	float	y;
	float distance;

	y = MINI_UNIT;
	k = MINI_UNIT;
	map->minimap.x = map->minimap.width / 2 + MINI_UNIT / 2;
	map->minimap.y = map->minimap.height / 2 + MINI_UNIT / 2;
	(void)k;
	(void)y;
	distance = map->r.distance * (float)(MINI_UNIT / UNIT);
	while (distance)
	{
		my_mlx_pixel_put(&map->mini, map->minimap.x, map->minimap.y, BLACK);
		my_mlx_pixel_put(&map->mini, map->minimap.x + 1, map->minimap.y, BLACK);
		keep_adding(map);
		distance--;
	}
}
