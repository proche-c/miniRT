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

void	ft_get_viewport(t_scene *scene)
{
	t_vector	vup;
	t_vector	w;

	scene->image_side = IMAGE_SIDE;
	scene->focal_length = DISTANCE_VIEWPORT;
	scene->h = tanf(ft_degrees_to_radians(scene->camera.fov / 2.0));
	scene->viewport_side = 2 * scene->h * scene->focal_length;
	w.x = scene->camera.orientation.x * -1;
	w.y = scene->camera.orientation.y * -1;
	w.z = scene->camera.orientation.z * -1;
	vup = ft_get_vup(w);
	ft_get_pixel00(scene, vup, w);
	return ;
}

t_vector	ft_get_vup(t_vector w)
{
	t_vector	vup;

	vup.x = 0;
	vup.y = 1;
	vup.z = 0;
	if (ft_get_vector_length(ft_cross(vup, w)) == 0)
	{
		vup.x = 0;
		vup.y = 0;
		vup.z = 1;
	}
	return (vup);
}

void	ft_get_pixel00(t_scene *scene, t_vector vup, t_vector w)
{
	t_vector	upper_left;
	float		temp;

	ft_get_scene_u(scene, w, vup);
	scene->v = ft_cross(w, scene->u);
	scene->view_u = ft_mult_vector_float(scene->u, scene->viewport_side);
	temp = scene->viewport_side * -1;
	scene->view_v = ft_mult_vector_float(scene->v, temp);
	temp = 1 / (float)scene->image_side;
	scene->delta_u = ft_mult_vector_float(scene->view_u, temp);
	scene->delta_v = ft_mult_vector_float(scene->view_v, temp);
	upper_left.x = scene->camera.pov.x - w.x * \
		scene->focal_length - scene->view_u.x / 2 - scene->view_v.x / 2;
	upper_left.y = scene->camera.pov.y - w.y * \
		scene->focal_length - scene->view_u.y / 2 - scene->view_v.y / 2;
	upper_left.z = scene->camera.pov.z - w.z * \
		scene->focal_length - scene->view_u.z / 2 - scene->view_v.z / 2;
	scene->pixel00.x = upper_left.x + 0.5 * \
	(scene->delta_u.x + scene->delta_v.x);
	scene->pixel00.y = upper_left.y + 0.5 * \
	(scene->delta_u.y + scene->delta_v.y);
	scene->pixel00.z = upper_left.z + 0.5 * \
	(scene->delta_u.z + scene->delta_v.z);
}

void	ft_get_scene_u(t_scene *scene, t_vector w, t_vector vup)
{
	if (w.x == -1 && w.y == 0 && w.z == 0)
	{
		scene->u.x = 0;
		scene->u.y = 0;
		scene->u.z = 1;
	}
	else
		scene->u = ft_unit_vector(ft_cross(vup, w));
}
