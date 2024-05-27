/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2023/10/05 00:11:28 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// TO DO ONCE PARSING IS DONE
int	ft_execute(t_scene *scene)
{

	scene->mlx_ptr = mlx_init();
	scene->window_ptr = mlx_new_window(scene->mlx_ptr, 800, 400, "miniRT");


	// ft_normalize_parameters : this will set the origin point at (0,0,0), 
		// it will set normailized vector for camera at (0,0,1)
	// ft _create_viewport: this function will establish parameters for viewport:
		// - aspect_ratio
		// - image_width
		// -  image_height = int(image_width / aspect_ratio)
		// - image_height = (image_height < 1) ? 1 : image_height
		// - focal_length
		// - viewport_height = 2.0
		// - viewport_width = viewport_height * (double(image_width)/image_height)
		// - camera_center = vector(0, 0, 0)
	 // Calculate the vectors across the horizontal and down the vertical viewport edges
	 	// - viewport_u = vector(viewport_width, 0, 0)
		// - viewport_v = vector(0, -viewport_height, 0)
	// Calculate the horizontal and vertical delta vectors from pixel to pixel
		// - pixel_delta_u = viewport_u / image_width
		// - pixel_delta_v = viewport_v / image_height
	// Calculate the location of the upper left pixel
		// - viewport_upper_left = camera_center - vector(0, 0, focal_length) - viewport_u/2 - viewport_v/2
		// - pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v)


	printf("OUT FT_EXECUTE\n");
	return (0);
}

// void	ft_normalize_parameters(t_scene *scene)
// {
// 	scene->light.position.x = scene->light.position.x - scene->camera.pov.x;
// 	return ;
// }
