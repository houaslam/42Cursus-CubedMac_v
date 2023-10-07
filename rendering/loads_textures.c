/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loads_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookair <macbookair@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 23:04:51 by macbookair        #+#    #+#             */
/*   Updated: 2023/10/04 23:04:52 by macbookair       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../raycasting/raycasting.h"


void    loads_images(t_textures *txt, char *path)
{
    int w;
    int h;

    (txt)->img = mlx_xpm_file_to_image((txt)->map->window->mlx, path, &w, &h);
    if (!(txt)->img)
        put_error("INVALID IMAGE");
    (txt)->h = h;
    (txt)->w = w;
    (txt)->add = (int *)mlx_get_data_addr((txt)->img, &(txt)->bits_per_pixel, &(txt)->line_length, &(txt)->endian);
}

void    loads_textures(t_textures *txt)
{
	loads_images(&txt[NO], txt->map->directions->no);
	loads_images(&txt[SO], txt->map->directions->so);
	loads_images(&txt[EA], txt->map->directions->ea);
	loads_images(&txt[WE], txt->map->directions->we);
	loads_images(&txt[DO], txt->map->directions->door);
}
