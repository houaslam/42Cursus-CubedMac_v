/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookair <macbookair@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:09:17 by houaslam          #+#    #+#             */
/*   Updated: 2023/10/04 23:05:30 by macbookair       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/raycasting.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	render_ceiling(t_window *window, int pos)
{
	float	ceiling;
	int		i;

	i = 0;
	ceiling = (PP_HEIGHT / 2) - (window->map->wall_h / 2);
	if (ceiling > 0 && ceiling < PP_HEIGHT)
	{
		while (i <= ceiling && ceiling > 0)
			my_mlx_pixel_put(&window->map->img, pos, i++,
				window->map->directions->c);
	}
	return (i);
}

void	draw_ray(t_window *window, int pos)
{
	int	i;
	int	dir;
	int	wall_h;
	int	color;
	int	text_offset_y;
	int	text_offset_x;
	int	distanceFromTop;

	i = render_ceiling(window, pos);
	wall_h = window->map->wall_h;
	get_offset_x(window->map, &dir, &text_offset_x);
	while (window->map->wall_h >= 0 && i < PP_HEIGHT)
	{
		distanceFromTop = i + (wall_h / 2) - (PP_HEIGHT / 2);
		text_offset_y = distanceFromTop * ((float)window->map->textures[dir].h
				/ wall_h);
		color = window->map->textures[dir].add[(window->map->textures[dir].w
				* text_offset_y) + text_offset_x];
		my_mlx_pixel_put(&window->map->img, pos, i++, color);
		window->map->wall_h--;
	}
	while (i < PP_HEIGHT)
		my_mlx_pixel_put(&window->map->img, pos, i++,
			window->map->directions->f);
}
