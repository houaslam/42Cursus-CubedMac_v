/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 08:59:03 by houaslam          #+#    #+#             */
/*   Updated: 2023/10/07 14:22:20 by houaslam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/raycasting.h"

void	draw_square(int color, int x, int y, t_window *window)
{
	int	a;
	int	b;

	a = -1;
	while (++a < MINI_UNIT)
	{
		b = -1;
		while (++b < MINI_UNIT)
			my_mlx_pixel_put(&window->map->mini, x++, y, color);
		x -= MINI_UNIT;
		y++;
	}
}

int	base(t_map *map)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < PP_HEIGHT / 5)
	{
		x = 0;
		while (x < PP_WIDTH / 5)
		{
			color = 0xFF777777;
			if (y == 0 || x == 0 || y == PP_HEIGHT \
			/ 5 - 1 || x == PP_WIDTH / 5 - 1)
				color = RED;
			my_mlx_pixel_put(&map->mini, x, y, color);
			x++;
		}
		y++;
	}
	map->minimap.height = PP_HEIGHT / 5;
	map->minimap.width = PP_WIDTH / 5;
	map->minimap.mini_p.u_x = (map->p.u_x / UNIT) * MINI_UNIT;
	map->minimap.mini_p.u_y = (map->p.u_y / UNIT) * MINI_UNIT;
	return (floor(map->minimap.mini_p.u_y - map->minimap.height / 2));
}

int	check(t_map *map, double x, double y)
{
	if (x < 0 || y < 0)
		return (0);
	if (y >= map->m_y || x >= map->m_x)
		return (0);
	if (map->map[(int)y][(int)x] == '1')
		return (1);
	if (map->map[(int)y][(int)x] == 'D')
	{
		map->r.content = DOOR;
		return (2);
	}
	return (0);
}

void	draw_circle(int x, int y, int r, t_map *map)
{
	double	i;
	double	angle;
	double	x1;
	double	y1;

	while (r > 0)
	{
		i = 0;
		while (i < 360)
		{
			angle = i;
			x1 = r * cos(angle * M_PI / 180);
			y1 = r * sin(angle * M_PI / 180);
			my_mlx_pixel_put(&map->mini, x + x1, y + y1, BLOOD);
			i += 0.1;
		}
		r--;
	}
}

void	draw_minimap(t_map *map)
{
	double	x;
	double	y;
	int		x_mov;
	int		y_mov;

	y = base(map);
	y_mov = -1;
	while (++y_mov < map->minimap.height)
	{
		x = floor(map->minimap.mini_p.u_x - map->minimap.width / 2);
		x_mov = -1;
		while (++x_mov < map->minimap.width)
		{
			if (check(map, x / MINI_UNIT, y / MINI_UNIT) == 1)
				my_mlx_pixel_put(&map->mini, x_mov, y_mov, BLACK);
			if (check(map, x / MINI_UNIT, y / MINI_UNIT) == 2)
				my_mlx_pixel_put(&map->mini, x_mov, y_mov, GREY);
			x++;
		}
		y++;
	}
	mini_quadrant(map);
	draw_circle(map->minimap.width / 2, map->minimap.height / 2, 5, map);
	mlx_put_image_to_window(map->window->mlx, map->window->mlx_win, \
	map->mini.img, 50, 50);
}
