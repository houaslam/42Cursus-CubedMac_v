/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookair <macbookair@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 18:48:02 by houaslam          #+#    #+#             */
/*   Updated: 2023/10/04 22:58:57 by macbookair       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int	ft_exit(t_window *mlx)
{
	int	i;

	free(mlx->map->directions->no);
	free(mlx->map->directions->so);
	free(mlx->map->directions->we);
	free(mlx->map->directions->ea);
	free(mlx->map->directions->door);
	i = write(2, "GAME OVER !!", ft_strlen("GAME OVER !!"));
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	exit(0);
	return (i);
}

void	check_angles(t_map *map)
{
	map->r.cast = remainder(map->r.cast, 360);
	if (map->r.cast < 0)
		map->r.cast += 360;
	map->r.ang = remainder(map->r.ang, 360);
	if (map->r.ang < 0)
		map->r.ang += 360;
}

void	rays_casting(t_map *map, t_window *window)
{
	int	i;

	i = 0;
	map->r.cast = map->r.ang + 30;
	map->img.addr = mlx_get_data_addr(map->img.img, &map->img.bits_per_pixel,
			&map->img.line_length, &map->img.endian);
	while (i < PP_WIDTH)
	{
		check_angles(map);
		quadrant(map);
		map->r.distance = p_to_wall(map);
		map->wall_h = wall_height(map);
		draw_ray(window, i);
		map->r.cast -= (float)VIEW_D / PP_WIDTH;
		i++;
	}
	mlx_put_image_to_window(window->mlx, window->mlx_win, map->img.img, 0, 0);
	map->mini.addr = mlx_get_data_addr(map->mini.img, &map->mini.bits_per_pixel,
			&map->mini.line_length, &map->mini.endian);
	draw_minimap(map);
}

void	player_view(t_map **map)
{
	if ((*map)->map[(int)(*map)->p.y][(int)(*map)->p.x] == 'E')
		(*map)->r.ang = 0;
	else if ((*map)->map[(int)(*map)->p.y][(int)(*map)->p.x] == 'N')
		(*map)->r.ang = 90;
	else if ((*map)->map[(int)(*map)->p.y][(int)(*map)->p.x] == 'W')
		(*map)->r.ang = 180;
	else if ((*map)->map[(int)(*map)->p.y][(int)(*map)->p.x] == 'S')
		(*map)->r.ang = 270;
	(*map)->r.cast = (*map)->r.ang + 30;
}
