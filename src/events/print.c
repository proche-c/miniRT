# include "../include/minirt.h"

int pixel_print(t_scene *scene)
{
    int bits_per_pixel, size_line, endian;

    mlx_new_image(scene->mlx_ptr, 1000, 700);
    printf("image initiated\n");
    mlx_get_data_addr(scene->mlx_ptr, &bits_per_pixel, &size_line, &endian);
    printf("data addr initiated\n");
    return (0);
};
