/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_offset_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadermou <fadermou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 23:04:45 by macbookair        #+#    #+#             */
/*   Updated: 2023/10/07 14:05:07 by fadermou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/raycasting.h"

void	vertical_offset(t_map *map, int *dir)
{
	if (map->r.content == DOOR)
		*dir = DO;
	else
	{
		if (((int)map->r.cast % 360 >= 0 && (int)map->r.cast % 360 < 90)
			|| ((int)map->r.cast % 360 >= 270 && (int)map->r.cast
				% 360 < 360))
			*dir = EA;
		else
			*dir = WE;
	}
	map->text_offset_x = (int)(map->v.y) % map->textures[*dir].h;
	if (map->text_offset_x >= map->textures->w)
		map->text_offset_x = map->textures[*dir].h - 1;
}

void	horizontal_offset(t_map *map, int *dir)
{
	if (map->r.content == DOOR)
		*dir = DO;
	else
	{
		if (((int)map->r.cast % 360 >= 0 && (int)map->r.cast % 360 < 180))
			*dir = NO;
		else
			*dir = SO;
	}
	map->text_offset_x = (int)(map->h.x) % map->textures[*dir].w;
	if (map->text_offset_x >= map->textures->w)
		map->text_offset_x = map->textures[*dir].w - 1;
}

void	get_offset_x(t_map *map, int *dir)
{
	map->text_offset_x = 0;
	if (map->vert == true)
		vertical_offset(map, dir);
	else
		horizontal_offset(map, dir);
}
