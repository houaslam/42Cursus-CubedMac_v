/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajarouaslam <hajarouaslam@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 16:00:10 by houaslam          #+#    #+#             */
/*   Updated: 2023/10/03 15:15:07 by hajarouasla      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/raycasting.h"
int perform_animation(t_window *window)
{
    static int	frame;
	static int weapon;
	void *img;
	int	h;
	int	w;
	char *which;
	char *res;

	h = 320;
	w = 498;
	img = NULL;
	frame %= 700 * 35 +1;
	weapon %= 35;
	if (window->DO_ANIMATION)
	{
		if (frame == 600 * weapon){
            mlx_clear_window(window->mlx, window->mlx_win);
			rays_casting(window->map, window);
			which = ft_itoa(weapon);
			res = ft_strdup("textures/weapon_");
			res = ft_strjoin(res, which);
			res = ft_strjoin(res, ".xpm");
			img = mlx_xpm_file_to_image(window->mlx, res, &w, &h);
			free(res);
			free(which);
			weapon++;
		}
		if (img)
		{
			w = PP_WIDTH / 2 - 150;
			h = PP_HEIGHT / 2 - 50;
			mlx_put_image_to_window(window->mlx, window->mlx_win, img,w, h);
		}
		if (weapon == 35)
        {
			rays_casting(window->map, window);
			window->DO_ANIMATION = false;
        }
		frame++;
		free(img);
	}
	return(0);
}
