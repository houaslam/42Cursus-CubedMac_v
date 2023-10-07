/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookair <macbookair@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:31:12 by houaslam          #+#    #+#             */
/*   Updated: 2023/10/04 22:28:17 by macbookair       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting/raycasting.h"

int	mouse(int x, int y, t_window *window)
{
	static int	hold_x;

	if (x < PP_WIDTH && y < PP_HEIGHT && x > 0 && y > 0)
	{
		if (hold_x < x)
			window->map->r.ang -= 4;
		if (hold_x > x)
			window->map->r.ang += 4;
		hold_x = x;
		rays_casting(window->map, window);
	}
	return (0);
}

int	main(int ac, char **av)
{
	int				i;
	t_window		window;
	t_map			map;
	t_directions	directions;
	t_textures		textures[5];

	i = 5;
	if (ac != 2)
		put_error("INVALID NUMBER OF ARGUMENTS");
	window.map = &map;
	map.window = &window;
	while (i--)
		textures[i].map = &map;
	map.textures = textures;
	directions.map = &map;
	map.directions = &directions;
	parsing(&map, av);
	window.mlx = mlx_init();
	window.mlx_win = mlx_new_window(window.mlx, PP_WIDTH, PP_HEIGHT, "Cub3D");
	loads_textures(textures);
	player_view(&window.map);
	map.p.u_x = (map.p.x * UNIT) + (UNIT / 2);
	map.p.u_y = (map.p.y * UNIT) + (UNIT / 2);
	map.img.img = mlx_new_image(window.mlx, PP_WIDTH, PP_HEIGHT);
	map.mini.img = mlx_new_image(window.mlx, PP_WIDTH / 5, PP_HEIGHT / 5);
	window.s_animation = false;
	rays_casting(&map, &window);
	mlx_hook(window.mlx_win, 2, 1L << 0, which_move, &map);
	mlx_hook(window.mlx_win, 17, 0, ft_exit, &window);
	mlx_loop_hook(window.mlx, perform_animation, &window);
	mlx_hook(window.mlx_win, 6, 1L << 6, mouse, &window);
	mlx_loop(window.mlx);
}
