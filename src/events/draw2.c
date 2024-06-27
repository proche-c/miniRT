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

void	write_pixel_no_object(t_scene *scene)
{
	t_color			background_color;
	t_pixel_info	pixel_info;

	background_color.r = 0;
	background_color.g = 0;
	background_color.b = 0;
	color2rgb(background_color);
	ft_pixel_put(&pixel_info, scene->image_side);
}

void	write_pixel_object(t_scene *scene, t_intersection *intersection, \
int j, int i)
{
	t_vector		normal;
	t_vector		view_dir;
	t_color			color_calc;
	int				color_int2;
	t_pixel_info	pixel_info;

	normal = calculate_normal(intersection);
	view_dir = calculate_view_dir(scene, intersection);
	color_calc = calculate_lighting(scene, intersection, normal, view_dir);
	color_int2 = color2rgb(color_calc);
	pixel_info.img = &scene->img;
	pixel_info.x = i;
	pixel_info.y = j;
	pixel_info.color = color_int2;
	ft_pixel_put(&pixel_info, scene->image_side);
}

t_vector	calculate_view_dir(t_scene *scene, t_intersection *intersection)
{
	t_vector	view_dir;

	view_dir.x = scene->camera.pov.x - intersection->position.x;
	view_dir.y = scene->camera.pov.y - intersection->position.y;
	view_dir.z = scene->camera.pov.z - intersection->position.z;
	view_dir.length_squared = 0;
	view_dir.length = 0;
	return (normalize(view_dir));
}
