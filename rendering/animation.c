/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajarouaslam <hajarouaslam@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 16:00:10 by houaslam          #+#    #+#             */
/*   Updated: 2023/10/02 22:03:08 by hajarouasla      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/raycasting.h"

int perform_animation(t_window *window)
{
    // static int	frame;
	static int weapon;
	void *img;
	// int	h;
	// int	w;
	char *which;
	char *res;

	// h = 320;
	// w = 498;
	img = NULL;
	// frame %= 200001;
	weapon %= 35;
	if (window->DO_ANIMATION)
	{
		// if (frame == 500 * weapon){
			which = ft_itoa(weapon);
			res = ft_strjoin("textures/weapon_", which);
			res = ft_strjoin(res, ".xpm");
			printf("-->res = %s\n", res);
			exit(0);
			// img = mlx_xpm_file_to_image(window->mlx, res, &w, &h);
			// free(res);
			// free(which);
			// weapon++;
		// }
		if (img)
		{
			// w = PP_WIDTH / 2;
			// h = PP_HEIGHT - 100;
			// mlx_put_image_to_window(window->mlx, window->mlx_win, img,w, h);
		}
		if (weapon == 35)
			window->DO_ANIMATION = false;
		// frame++;
		free(img);
	}
	return(0);
}
