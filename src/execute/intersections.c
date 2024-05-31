/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2023/10/05 00:11:28 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	ft_get_ray(t_scene *scene, int j, int i)
{
	t_ray	ray;
	t_vector	inc;

	ray.origin.x = scene->camera.pov.x;
	ray.origin.y = scene->camera.pov.y;
	ray.origin.z = scene->camera.pov.z;
	inc = ft_mult_vector_float(scene->delta_u, i);
	inc = ft_add_vectors(inc, ft_mult_vector_float(scene->delta_v, j));
	ray.pixel_center = ft_add_vectors(scene->pixel00, inc);
	ray.direction = ft_sub_vectors(ray.pixel_center, scene->camera.pov);
	// if (i == 0 && j == 0)
	// {
	// 	printf("ray.direction.x: %f\n", ray.direction.x);
	// 	printf("ray.direction.y: %f\n", ray.direction.y);
	// 	printf("ray.direction.z: %f\n", ray.direction.z);
	// }
	return (ray);
}

void	ft_hit_something(t_ray ray, t_scene *scene, t_intersection *inter)
{
	t_element	*c_element;


	//inter->state = 0;
	ft_get_inter_ray(ray, inter);
	c_element = scene->elements;
	while (c_element)
	{
		if (ft_strncmp(c_element->identifier, "sp", 3) == 0)
			ft_inter_sp(inter, c_element);
		else if (ft_strncmp(c_element->identifier, "pl", 3) == 0)
			ft_inter_pl(scene, inter, c_element);
		else if (ft_strncmp(c_element->identifier, "cy", 3) == 0)
			ft_inter_cy(scene, inter, c_element);
		c_element = c_element->next;
	}
	// if (ray.pixel_center.x == scene->pixel00.x && ray.pixel_center.y == scene->pixel00.y
	// 	&& ray.pixel_center.z == scene->pixel00.z)
	// {
	// 	printf("inter->ray.pixel_center.x: %f\n", inter->ray.pixel_center.x);
	// 	printf("inter->ray.pixel_center.y: %f\n", inter->ray.pixel_center.y);
	// 	printf("inter->ray.pixel_center.z: %f\n", inter->ray.pixel_center.z);
	// 	printf("inter->ray.direction.x: %f\n", inter->ray.direction.x);
	// 	printf("inter->ray.direction.y: %f\n", inter->ray.direction.y);
	// 	printf("inter->ray.direction.z: %f\n", inter->ray.direction.z);
	// 	printf("inter->ray.origin.x: %f\n", inter->ray.origin.x);
	// 	printf("inter->ray.origin.y: %f\n", inter->ray.origin.y);
	// 	printf("inter->ray.origin.z: %f\n", inter->ray.origin.z);
	// }
	// printf("inter->position.x: %f\n", inter->position.x);
	// printf("inter->position.x: %f\n", inter->position.x);
	// printf("inter->position.x: %f\n", inter->position.x);
}

void	ft_get_inter_ray(t_ray ray, t_intersection *inter)
{
	inter->ray.origin = ray.origin;
	inter->ray.direction = ray.direction;
	inter->ray.pixel_center = ray.pixel_center;
}