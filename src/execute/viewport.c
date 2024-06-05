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
	scene->h = tanf(ft_degrees_to_radians(scene->camera.fov));
	scene->viewport_side = 2 * scene->h * scene->focal_length;
	w = ft_mult_vector_float(scene->camera.orientation, -1);
	vup = ft_get_vup(w);
	ft_get_pixel00(scene, w, vup);
	return ;
}

t_vector	ft_get_vup(t_vector w)
{
	t_vector	vup;

	vup.x = 0;
	vup.y = 1;
	vup.z = 0;
	if (ft_get_vector_length(ft_cross(w, vup)) == 0)
	{
		vup.x = 0;
		vup.y = 0;
		vup.z = 1;
	}
	return (vup);
}

void	ft_get_pixel00(t_scene *scene, t_vector w, t_vector vup)
{
	t_vector	upper_left;
	t_vector	i;
	t_vector	u;
	t_vector	v;
	float		temp;

	printf("w.x %f\n", w.x);
	printf("w.y %f\n", w.y);
	printf("w.z %f\n", w.z);
	u = ft_unit_vector(ft_cross(vup, w));
	printf("u.x %f\n", u.x);
	printf("u.y %f\n", u.y);
	printf("u.z %f\n", u.z);
	v = ft_cross(w, u);
	printf("v.x %f\n", v.x);
	printf("v.y %f\n", v.y);
	printf("v.z %f\n", v.z);
	scene->view_u = ft_mult_vector_float_1(u, 1000);
	scene->view_v = ft_mult_vector_float_1(v, IMAGE_SIDE);
	printf("scene->view_u.x: %f\n", scene->view_u.x);
	printf("scene->view_u.y: %f\n", scene->view_u.y);
	printf("scene->view_u.z: %f\n", scene->view_u.z);
	printf("scene->view_v.x: %f\n", scene->view_v.x);
	printf("scene->view_v.y: %f\n", scene->view_v.y);
	printf("scene->view_v.z: %f\n", scene->view_v.z);
	temp = IMAGE_SIDE / scene->image_side;
	printf("temp %f\n", temp);
	scene->delta_u = ft_mult_vector_float(u, temp);
	v = ft_mult_vector_float(v, -1);
	scene->delta_v = ft_mult_vector_float(v, temp);
	printf("scene->delta_u.x: %f\n", scene->delta_u.x);
	printf("scene->delta_u.y: %f\n", scene->delta_u.y);
	printf("scene->delta_u.z: %f\n", scene->delta_u.z);
	printf("scene->delta_v.x: %f\n", scene->delta_v.x);
	printf("scene->delta_v.y: %f\n", scene->delta_v.y);
	printf("scene->delta_v.z: %f\n", scene->delta_v.z);
	w = ft_mult_vector_float(w, scene->focal_length);
	upper_left = ft_sub_vectors(scene->camera.pov, w);
	upper_left = ft_sub_vectors(upper_left, ft_div_vector_float(scene->view_u, 2));
	upper_left = ft_sub_vectors(upper_left, ft_div_vector_float(scene->view_v, 2));
	i = ft_mult_vector_float(scene->delta_u, 0.5);
	i = ft_add_vectors(ft_mult_vector_float(scene->delta_v, 0.5), i);
	scene->pixel00 = ft_add_vectors(upper_left, i);	
}