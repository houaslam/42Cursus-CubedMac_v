
#include "../raycasting/raycasting.h"


void    loads_images(t_textures *txt, char *path)
{
    int w;
    int h;

    (txt)->img = mlx_xpm_file_to_image((txt)->map->window->mlx, path, &w, &h);
    if (!(txt)->img)
        put_error("INVALID IMAGE");
    (txt)->h = h;///// what if i tried txt-> instead
    (txt)->w = w;
    (txt)->add = (int *)mlx_get_data_addr((txt)->img, &(txt)->bits_per_pixel, &(txt)->line_length, &(txt)->endian);
}

void    loads_textures(t_textures *txt)
{
	loads_images(&txt[NO], txt->map->directions->no);
	loads_images(&txt[SO], txt->map->directions->so);
	loads_images(&txt[EA], txt->map->directions->ea);
	loads_images(&txt[WE], txt->map->directions->we);
}
