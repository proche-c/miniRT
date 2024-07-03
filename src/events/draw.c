/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:32:58 by ageiser           #+#    #+#             */
/*   Updated: 2022/09/20 15:41:05 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	mlx_initiator(t_scene *scene)
{
	scene->mlx_ptr = mlx_init();
	if (!scene->mlx_ptr)
	{
		printf("Error initializing MLX.\n");
		return (-1);
	}
	scene->window_ptr = mlx_new_window(scene->mlx_ptr, WIN_WIDTH, \
	WIN_HEIGHT, "miniRT");
	if (!scene->window_ptr)
	{
		printf("Error creating window.\n");
		return (-1);
	}
	return (0);
}

void	ft_pixel_put(t_pixel_info *pixel_info, int image_side)
{
	int	offset;

	if (pixel_info->x < 0 || pixel_info->x >= image_side || \
	pixel_info->y < 0 || pixel_info->y >= image_side)
	{
		return ;
	}
	offset = (pixel_info->img->size_line * pixel_info->y) + \
	(pixel_info->x * (pixel_info->img->bpp / 8));
	if (offset < 0 || offset >= image_side * image_side * \
	(pixel_info->img->bpp / 8))
	{
		printf("Error: Invalid offset %d for pixel (%d, %d)\n", \
		offset, pixel_info->x, pixel_info->y);
		return ;
	}
	*((unsigned int *)(pixel_info->img->img_pixel_str + offset)) \
	= pixel_info->color;
}
/*printf("Error: Invalid coordinates (%d, %d)\n", \
pixel_info->x, pixel_info->y);*/
// pixel_info->img->size_line is the number of bytes in a row of the image.
// pixel_info->img->bpp is the bits per pixel.
// (pixel_info->img->bpp / 8) converts bits per pixel to bytes per pixel.
// The offset is calculated by multiplying the row number (y) by 
// the size of a row in bytes (size_line), and adding the column offset 
// (x * bytes per pixel).
// pixel_info->img->img_pixel_str is the starting address 
// of the image pixel data.
// The offset is added to this starting address to get the 
// address of the specific pixel.
// The color value (pixel_info->color) is assigned to this address.
// The cast to unsigned int* ensures that the correct number of bytes 
// are written for the pixel color.

void	color_screen(t_scene *scene, int color)
{
	int				x;
	int				y;
	int				start_x;
	int				start_y;
	t_pixel_info	pixel_info;

	pixel_info.img = &scene->img;
	pixel_info.color = color;
	y = 0;
	while (y < scene->image_side)
	{
		x = 0;
		while (x < scene->image_side)
		{
			pixel_info.x = x;
			pixel_info.y = y;
			ft_pixel_put(&pixel_info, scene->image_side);
			x++;
		}
		y++;
	}
	start_x = (WIN_WIDTH - scene->image_side) / 2;
	start_y = (WIN_HEIGHT - scene->image_side) / 2;
	mlx_put_image_to_window(scene->mlx_ptr, scene->window_ptr, \
	scene->img.img_ptr, start_x, start_y);
}

int	pixel_print(t_scene *scene)
{
	scene->img.img_ptr = mlx_new_image(scene->mlx_ptr, \
	scene->image_side, scene->image_side);
	if (!scene->img.img_ptr)
	{
		printf("Error creating image.\n");
		return (-1);
	}
	scene->img.img_pixel_str = mlx_get_data_addr(scene->img.img_ptr, \
	&scene->img.bpp, &scene->img.size_line, &scene->img.endian);
	if (!scene->img.img_pixel_str)
	{
		printf("Error getting data address.\n");
		return (-1);
	}
	return (0);
}

// mlx_get_data_addr is a function from the MLX library 
// that retrieves the address of the image pixel data.
// scene->img.img_ptr: The pointer to the image created earlier.
// &scene->img.bpp: A pointer to an integer to store bits per pixel.
// &scene->img.size_line: A pointer to an integer to store 
// the size of a line in bytes.
// &scene->img.endian: A pointer to an integer to store the endianess 
// of the image.
// The function returns a pointer to the pixel data, which 
// is stored in scene->img.img_pixel_str.

t_vector	calculate_normal(t_intersection *intersection)
{
	t_vector	normal;

	normal = (t_vector){0, 0, 0, 0, 0};
	if (ft_strncmp(intersection->element->identifier, "sp", 3) == 0)
		normal = calculate_sphere_normal(intersection->element, intersection);
	else if (ft_strncmp(intersection->element->identifier, "pl", 3) == 0)
		normal = calculate_plane_normal(intersection->element, normal);
	else if (ft_strncmp(intersection->element->identifier, "cy", 3) == 0)
		normal = calculate_cylinder_normal(intersection->element, \
		intersection);
	return (normal);
}
