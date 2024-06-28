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

void	ft_get_ray(t_scene *scene, t_intersection *inter, int j, int i)
{
	inter->ray.origin.x = scene->camera.pov.x;
	inter->ray.origin.y = scene->camera.pov.y;
	inter->ray.origin.z = scene->camera.pov.z;
	inter->ray.pixel_center.x = scene->pixel00.x + \
		(i * scene->delta_u.x) + (j * scene->delta_v.x);
	inter->ray.pixel_center.y = scene->pixel00.y + \
		(i * scene->delta_u.y) + (j * scene->delta_v.y);
	inter->ray.pixel_center.z = scene->pixel00.z + \
		(i * scene->delta_u.z) + (j * scene->delta_v.z);
	inter->ray.direction.x = inter->ray.pixel_center.x - scene->camera.pov.x;
	inter->ray.direction.y = inter->ray.pixel_center.y - scene->camera.pov.y;
	inter->ray.direction.z = inter->ray.pixel_center.z - scene->camera.pov.z;
	return ;
}
	// if ((i == 0 || i == 1 || i == 2) && j == 0)
	// {
	// 	printf("ray.direction.x: %f\n", inter->ray.direction.x);
	// 	printf("ray.direction.y: %f\n", inter->ray.direction.y);
	// 	printf("ray.direction.z: %f\n", inter->ray.direction.z);
	// }

void	ft_hit_something(t_scene *scene, t_intersection *inter)
{
	t_element	*c_element;

	c_element = scene->elements;
	while (c_element)
	{
		if (ft_strncmp(c_element->identifier, "sp", 3) == 0)
			ft_inter_sp(inter, c_element);
		else if (ft_strncmp(c_element->identifier, "pl", 3) == 0)
			ft_inter_pl(inter, c_element);
		else if (ft_strncmp(c_element->identifier, "cy", 3) == 0)
			ft_inter_cy(inter, c_element);
		c_element = c_element->next;
	}
}
	//inter->state = 0;
	// ft_get_inter_ray(ray, inter);
	// printf("c_element->identifier: %s\n", c_element->identifier);
	// printf("c_element->identifier: %s\n", c_element->identifier);
	// if (ray.pixel_center.x == scene->pixel00.x 
	//&& ray.pixel_center.y == scene->pixel00.y
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

void	ft_get_inter_ray(t_ray ray, t_intersection *inter)
{
	inter->ray.origin = ray.origin;
	inter->ray.direction = ray.direction;
	inter->ray.pixel_center = ray.pixel_center;
}

void	ft_hit_something_2(t_scene *scene, t_intersection \
*shadow_inter, t_element *inter_element)
{
	t_element	*c_element;

	c_element = scene->elements;
	while (c_element)
	{
		if (c_element != inter_element)
		{
			if (ft_strncmp(c_element->identifier, "sp", 3) == 0)
				ft_inter_sp(shadow_inter, c_element);
			else if (ft_strncmp(c_element->identifier, "pl", 3) == 0)
				ft_inter_pl(shadow_inter, c_element);
			else if (ft_strncmp(c_element->identifier, "cy", 3) == 0)
				ft_inter_cy(shadow_inter, c_element);
		}
		c_element = c_element->next;
	}
}
	//inter->state = 0;
	// ft_get_inter_ray(ray, inter);
	// printf("c_element->identifier: %s\n", c_element->identifier);
	// printf("c_element->identifier: %s\n", c_element->identifier);
	// if (ray.pixel_center.x == scene->pixel00.x && 
	//ray.pixel_center.y == scene->pixel00.y
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