/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajarouaslam <hajarouaslam@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 07:38:31 by houaslam          #+#    #+#             */
/*   Updated: 2023/10/02 22:06:43 by hajarouasla      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int	turn_move(int keycode, t_map *map)
{
	if (keycode == ARROW_LEFT)
		map->r.ang += 7;
	else if (keycode == ARROW_RIGHT)
		map->r.ang -= 7;
	return (0);
}

bool can_move(t_map *map, int y, int x)
{
	if ((map->map[y][x] != '1') && (map->map[y][x] != 'D'))
		return true;
	return false;
}

void	move_up_down(t_map *map, int keycode)
{
	int	sinvalue;
	int	cosvalue;

	sinvalue = sin(map->r.ang * M_PI / 180) * SPEED;
	cosvalue = cos(map->r.ang * M_PI / 180) * SPEED;
	if ((keycode == UP || keycode == ARROW_UP) && map->r.distance > 0)
	{
		if (can_move(map, (int)(map->p.u_y / UNIT), (int)(map->p.u_x + cosvalue) / UNIT))
			map->p.u_x += cosvalue;
		if (can_move(map, (int)(map->p.u_y - sinvalue) / UNIT, (int)map->p.u_x / UNIT))
			map->p.u_y -= sinvalue;
	}
	if ((keycode == DOWN || keycode == ARROW_DOWN))
	{
		if (can_move(map,(int)map->p.u_y / UNIT, (int)(map->p.u_x - cosvalue) / UNIT))
			map->p.u_x -= cosvalue;
		if (can_move(map, (int)(map->p.u_y + sinvalue) / UNIT, (int)map->p.u_x / UNIT))
			map->p.u_y += sinvalue;
	}
}

void	move_left_right(t_map *map, int keycode)
{
	int	sinvalue;
	int	cosvalue;

	sinvalue = sin((90 - map->r.ang) * M_PI / 180) * SPEED;
	cosvalue = cos((90 - map->r.ang) * M_PI / 180) * SPEED;
	if (keycode == LEFT)
	{
		if (can_move(map, (int)map->p.u_y / UNIT, (int)(map->p.u_x - cosvalue) / UNIT))
			map->p.u_x -= cosvalue;
		if (can_move(map, (int)(map->p.u_y - sinvalue) / UNIT, (int)map->p.u_x / UNIT))
			map->p.u_y -= sinvalue;
	}
	if (keycode == RIGHT)
	{
		if (can_move(map, (int)map->p.u_y / UNIT, (int)(map->p.u_x + cosvalue) / UNIT))
			map->p.u_x += cosvalue;
		if (can_move(map, (int)(map->p.u_y + sinvalue) / UNIT, (int)map->p.u_x / UNIT))
			map->p.u_y += sinvalue;
	}
}

int	which_move(int keycode, t_map *map)
{
	if (keycode == LEFT || keycode == RIGHT)
		move_left_right(map, keycode);
	if (keycode == UP || keycode == ARROW_UP \
	|| keycode == DOWN || keycode == ARROW_DOWN)
		move_up_down(map, keycode);
	if (keycode == ARROW_LEFT || keycode == ARROW_RIGHT)
		turn_move(keycode, map);
	if (keycode == SPACE && map->map[map->r.d_y][map->r.d_x] == 'D')
		map->map[map->r.d_y][map->r.d_x] = 48;
	if (keycode == FIRE)
		map->window->DO_ANIMATION = true;
	if (keycode == DESTROY)
		ft_exit(map->window);
	rays_casting(map, map->window);
	return (0);
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
