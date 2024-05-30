# include "../include/minirt.h"


int mlx_initiator(t_scene *scene)
{
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

void	ft_pixel_put(t_img *img, int x, int y, int color)
{
	int	offset;

    if (x < 0 || x >= IMG_WIDTH || y < 0 || y >= IMG_HEIGHT)
    {
        printf("Error: Invalid coordinates (%d, %d)\n", x, y);
        return;
    }

	//calc the offset in octets for the pixel at position (x, y) in the img
	offset = (img->size_line * y) + (x * (img->bpp / 8));	
    //printf("size_line: %d, bpp: %d, x: %d, y: %d, offset: %d\n", img->size_line, img->bpp, x, y, offset);
    //printf("Offset: %d (x: %d, y: %d)\n", offset, x, y);
    //(img->size_line * y) = calc how many oct are necessary to reach the line y
    //(x * (img->bpp / 8)) = calc how many oct are necessary to reach the x position in the line y (converts bpp in octets pp )
	//printf("IMG_WIDTH: %d * IMG_HEIGHT: %d * (img->bpp / 8): %d = %d\n", IMG_WIDTH, IMG_HEIGHT, (img->bpp / 8), IMG_WIDTH * IMG_HEIGHT * (img->bpp / 8));
    if (offset < 0 || offset >= IMG_WIDTH * IMG_HEIGHT * (img->bpp / 8))
    {
        printf("Error: Invalid offset %d for pixel (%d, %d)\n", offset, x, y);
        return;
    } 
    *((unsigned int *)( img->img_pixel_str + offset)) = color;
    //printf("color_screen done\n");
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

    int start_x = (WIN_WIDTH - IMG_WIDTH) / 2;
    int start_y = (WIN_HEIGHT - IMG_HEIGHT) / 2;
    
    mlx_put_image_to_window(scene->mlx_ptr, scene->window_ptr, scene->img.img_ptr, start_x, start_y);
}



int pixel_print(t_scene *scene)
{
	scene->img.img_ptr = mlx_new_image(scene->mlx_ptr, IMG_WIDTH, IMG_HEIGHT);
	if (!scene->img.img_ptr)
	{
		printf("Error creating image.\n");
		return (-1);
	}
	printf("Image created.\n");

	scene->img.img_pixel_str = mlx_get_data_addr(scene->img.img_ptr, &scene->img.bpp, &scene->img.size_line, &scene->img.endian);
	if (!scene->img.img_pixel_str)
	{
		printf("Error getting data address.\n");
		return (-1);
	}
	printf("Data address obtained: bpp = %d, size_line = %d, endian = %d\n", scene->img.bpp, scene->img.size_line, scene->img.endian);
	return (0);
}
