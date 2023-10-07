/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_offset_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadermou <fadermou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 23:04:45 by macbookair        #+#    #+#             */
/*   Updated: 2023/10/07 11:24:48 by fadermou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/raycasting.h"

void	vertical_offset(t_map *map, int *dir, int *text_offset_x)
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
	*text_offset_x = (int)(map->v.y) % map->textures[*dir].h;
}

void	horizontal_offset(t_map *map, int *dir, int *text_offset_x)
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
	*text_offset_x = (int)(map->h.x) % map->textures[*dir].w;
}

void	get_offset_x(t_map *map, int *dir, int *text_offset_x)
{
	if (map->vert == true)
		vertical_offset(map, dir, text_offset_x);
	else
		horizontal_offset(map, dir, text_offset_x);
}
