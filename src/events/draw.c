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

void	ft_pixel_put(t_img *img, int x, int y, int color, t_scene *scene)
{
	int	offset;

    if (x < 0 || x >= scene->image_side || y < 0 || y >= scene->image_side)
    {
        printf("Error: Invalid coordinates (%d, %d)\n", x, y);
        return;
    }
    offset = (img->size_line * y) + (x * (img->bpp / 8));	
    if (offset < 0 || offset >= scene->image_side * scene->image_side * (img->bpp / 8))
    {
        printf("Error: Invalid offset %d for pixel (%d, %d)\n", offset, x, y);
        return;
    } 
    *((unsigned int *)( img->img_pixel_str + offset)) = color;
}

void	color_screen(t_scene *scene, int color)
{
    int	x;
    int	y;

    y = 0;
  
    while (y < scene->image_side)
    {
        x = 0;
        while (x < scene->image_side)
        {
            
            ft_pixel_put(&scene->img, x, y, color, scene);
           
            x++;
        }
        y++;
    }

    int start_x = (WIN_WIDTH - scene->image_side) / 2;
    int start_y = (WIN_HEIGHT - scene->image_side) / 2;
    
    mlx_put_image_to_window(scene->mlx_ptr, scene->window_ptr, scene->img.img_ptr, start_x, start_y);
}

int pixel_print(t_scene *scene)
{
	scene->img.img_ptr = mlx_new_image(scene->mlx_ptr, scene->image_side, scene->image_side);
	if (!scene->img.img_ptr)
	{
		printf("Error creating image.\n");
		return (-1);
	}
	printf("NEW image initiated.\n");

	scene->img.img_pixel_str = mlx_get_data_addr(scene->img.img_ptr, &scene->img.bpp, &scene->img.size_line, &scene->img.endian);
	if (!scene->img.img_pixel_str)
	{
		printf("Error getting data address.\n");
		return (-1);
	}
	printf("Data address obtained: bpp = %d, size_line = %d, endian = %d\n", scene->img.bpp, scene->img.size_line, scene->img.endian);
	return (0);
}

void write_pixel_object(t_scene *scene, t_intersection *intersection, int j, int i)
{
    t_vector normal;
    t_vector view_dir;
    t_color color_calc;
    int color_int2;


    normal = (t_vector){0,0,0,0,0};
    if (ft_strncmp(intersection->element->identifier, "sp", 3) == 0)
        normal = calculate_sphere_normal(intersection->element, intersection);
    else if (ft_strncmp(intersection->element->identifier, "pl", 3) == 0)
        normal = calculate_plane_normal(intersection->element, normal);
    else if (ft_strncmp(intersection->element->identifier, "cy", 3) == 0)
        normal = calculate_cylinder_normal(intersection->element, intersection, normal);
    view_dir = (t_vector) {
        .x = scene->camera.pov.x - intersection->position.x,
        .y = scene->camera.pov.y - intersection->position.y,
        .z = scene->camera.pov.z - intersection->position.z,
        .length_squared = 0,
        .length = 0
    };
    view_dir = normalize(view_dir);
    color_calc = calculate_lighting(scene, intersection, normal, view_dir);
    color_int2 = color2rgb(color_calc);
    ft_pixel_put(&scene->img, i, j, color_int2, scene);
}

void write_pixel_no_object(t_scene *scene, int j, int i)
{
    int no_col;
    t_color background_color = {0,0,0};

    no_col = color2rgb(background_color);
    ft_pixel_put(&scene->img, i, j, no_col, scene);
}
