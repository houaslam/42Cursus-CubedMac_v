/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houaslam <houaslam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 08:59:03 by houaslam          #+#    #+#             */
/*   Updated: 2023/08/23 20:02:39 by houaslam         ###   ########.fr       */
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

void	base(t_map *map)
{
	int	x;
	int	y;
	int		k;

	k = MINI_UNIT;

	y = 0;
	while (y < PP_HEIGHT / 5)
	{
		x = 0;
		while (x < PP_WIDTH / 5)
		{
			my_mlx_pixel_put(&map->mini, x, y, PURPLE);
			x++;
		}
		y++;
	}
	map->minimap.height = PP_HEIGHT / 5;
	map->minimap.width = PP_WIDTH / 5;
	map->minimap.mini_p.u_x = (map->p.u_x / UNIT) * MINI_UNIT;
	map->minimap.mini_p.u_y = (map->p.u_y / UNIT) * MINI_UNIT;
	(void)k;
	// map->minimap.player = mlx_xpm_file_to_image(map->window->mlx 
	// , "rendering/player.xpm", &k, &k);
	// mlx_put_image_to_window(map->window->mlx, map->window->mlx_win 
	// , map->minimap.player, 90, 80);
}

int	check(t_map *map, double x, double y)
{
	if (x / MINI_UNIT < 0 || y / MINI_UNIT < 0)
		return (0);
	if (y / MINI_UNIT >= map->m_y \
	|| x / MINI_UNIT >= map->m_x)
		return (0);
	if (map->map[(int)y / MINI_UNIT][(int)x / MINI_UNIT] != '1')
		return (0);
	return (1);
}

void DrawCircle(int x, int y, int r, t_map *map)
{
    double i;
    double angle;
    double x1;
    double y1;

    while (r > 0)
    {
        i = 0;
        while(i < 360)
        {
            angle = i;
            x1 = r * cos(angle * M_PI / 180);
            y1 = r * sin(angle * M_PI / 180);
            my_mlx_pixel_put(&map->mini, x + x1, y + y1, 0xFF777777);
            i += 0.1;
        }
        r--;
    }
}

void    draw_minimap(t_map *map)
{
    double    x;
    double    y;
    int        x_mov;
    int        y_mov;

    base(map);
    y = floor(map->minimap.mini_p.u_y - map->minimap.height / 2);
    y_mov = 0;
    while (y_mov < map->minimap.height)
    {
        x = floor(map->minimap.mini_p.u_x - map->minimap.width / 2);
        x_mov = 0;
        while (x_mov < map->minimap.width)
        {
            if (check(map, x, y))
                my_mlx_pixel_put(&map->mini, x_mov, y_mov, BLACK);
            x_mov++;
            x++;
        }
        y_mov++;
        y++;
    }
    mini_quadrant(map);
    DrawCircle(map->minimap.width / 2, map->minimap.height/ 2,5, map);
    mlx_put_image_to_window(map->window->mlx, \
    map->window->mlx_win, map->mini.img, 50, 50);
}