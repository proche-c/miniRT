# include "../include/minirt.h"

void	ft_pixel_put(t_img *img, int x, int y, int color)
{
	int	offset;

	//calc the offset in octets for the pixel at position (x, y) in the img
	offset = (img->size_line * y) + (x * (img->bpp / 8));	
    //(img->size_line * y) = calc how many oct are necessary to reach the line y
    //(x * (img->bpp / 8)) = calc how many oct are necessary to reach the x position in the line y (converts bpp in octets pp )
	*((unsigned int *)(offset + img->img_pixel_str)) = color;
    //converts the address of the pixel to a pointer
}

void	color_screen(t_scene *scene, int color)
{
    int	x;
    int	y;

    y = 0;
    while (y < IMG_HEIGHT)
    {
        x = 0;
        while (x < IMG_WIDTH)
        {
            ft_pixel_put(&scene->img, x, y, color);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(scene->mlx_ptr, scene->window_ptr, scene->img.img_ptr, 0, 0);
}

int mlx_initiator(t_scene *scene)
{
    //scene->mlx_ptr = malloc(sizeof(void *));
	scene->mlx_ptr = mlx_init();
    if (!scene->mlx_ptr)
    {
        printf("Error initializing MLX.\n");
        return (-1);
    }
	scene->window_ptr = mlx_new_window(scene->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "miniRT");
    if (!scene->window_ptr)
    {
        printf("Error creating window.\n");
        return (-1);
    }
    return (0);
}

int pixel_print(t_scene *scene)
{
    scene->img.img_ptr = mlx_new_image(scene->mlx_ptr, IMG_WIDTH, IMG_HEIGHT);
    printf("image initiated\n");
    scene->img.img_pixel_str = mlx_get_data_addr(scene->img.img_ptr, &scene->img.bpp, &scene->img.size_line, &scene->img.endian);
    if (!scene->img.img_pixel_str)
    {
        printf("Error getting data address.\n");
        return (-1);
    }
    printf("data addr initiated\n");
    return (0);
};
