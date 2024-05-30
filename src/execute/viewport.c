/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2023/10/05 00:11:28 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_create_viewport(t_scene *scene)
{
	float	temp;
	t_vector	upper_left;
	t_vector	increaser;

	scene->aspect_ratio = ASPECT_RATIO;
	scene->image_width = 800;
	scene->image_height = (int)(scene->image_width / scene->aspect_ratio);
	scene->focal_length = DISTANCE_VIEWPORT;
	scene->h = tanf(ft_degrees_to_radians(scene->camera.fov));
	scene->viewport_height = 2 * scene->h * scene->focal_length;
	scene->viewport_width = scene->viewport_height * (scene->aspect_ratio);
	scene->vup.x = 0;
	scene->vup.y = 1;
	scene->vup.z = 0;
	scene->w = ft_multiply_vector_and_float(scene->camera.orientation, -1);
	if (ft_get_vector_length(ft_cross(scene->w, scene->vup)) == 0)
	{
		scene->vup.x = 0;
		scene->vup.y = 0;
		scene->vup.z = 1;
	}
	scene->u = ft_unit_vector(ft_cross(scene->vup, scene->w));
	scene->v = ft_cross(scene->w, scene->u);
	scene->viewport_u = ft_multiply_vector_and_float(scene->u, scene->viewport_width);
	temp = scene->viewport_height * -1;
	scene->viewport_v = ft_multiply_vector_and_float(scene->v, temp);
	scene->pixel_delta_u = ft_division_vector_by_float(scene->viewport_u, scene->image_width);
	scene->pixel_delta_v = ft_division_vector_by_float(scene->viewport_v, scene->image_height);
	upper_left = ft_subtract_vectors(scene->camera.pov, ft_multiply_vector_and_float(scene->w, scene->focal_length));
	upper_left = ft_subtract_vectors(upper_left, ft_division_vector_by_float(scene->viewport_u, 2));
	upper_left = ft_subtract_vectors(upper_left, ft_division_vector_by_float(scene->viewport_v, 2));
	increaser = ft_multiply_vector_and_float(ft_add_vectors(scene->pixel_delta_u, scene->pixel_delta_v), 0.5);
	scene->pixel00 = ft_add_vectors(upper_left, increaser);
	return ;
}
