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
	inter->ray.pixel_center.x = scene->pixel00.x +
		(i * scene->delta_u.x) + (j * scene->delta_v.x);
	inter->ray.pixel_center.y = scene->pixel00.y +
		(i * scene->delta_u.y) + (j * scene->delta_v.y);
	inter->ray.pixel_center.z = scene->pixel00.z +
		(i * scene->delta_u.z) + (j * scene->delta_v.z);
	inter->ray.direction.x = inter->ray.pixel_center.x - scene->camera.pov.x;
	inter->ray.direction.y = inter->ray.pixel_center.y - scene->camera.pov.y;
	inter->ray.direction.z = inter->ray.pixel_center.z - scene->camera.pov.z;
	// if ((i == 0 || i == 1 || i == 2) && j == 0)
	// {
	// 	printf("ray.direction.x: %f\n", inter->ray.direction.x);
	// 	printf("ray.direction.y: %f\n", inter->ray.direction.y);
	// 	printf("ray.direction.z: %f\n", inter->ray.direction.z);
	// }
	return ;
}

void	ft_hit_something(t_scene *scene, t_intersection *inter)
{
	t_element	*c_element;


	//inter->state = 0;
	// ft_get_inter_ray(ray, inter);
	c_element = scene->elements;
	// printf("c_element->identifier: %s\n", c_element->identifier);
	while (c_element)
	{
		// printf("c_element->identifier: %s\n", c_element->identifier);
		if (ft_strncmp(c_element->identifier, "sp", 3) == 0)
			ft_inter_sp(inter, c_element);
		else if (ft_strncmp(c_element->identifier, "pl", 3) == 0)
			ft_inter_pl(inter, c_element);
		else if (ft_strncmp(c_element->identifier, "cy", 3) == 0)
			ft_inter_cy(inter, c_element);
		c_element = c_element->next;
	}
	ft_calculate_shadow(scene, inter, c_element);
}

void	ft_get_inter_ray(t_ray ray, t_intersection *inter)
{
	inter->ray.origin = ray.origin;
	inter->ray.direction = ray.direction;
	inter->ray.pixel_center = ray.pixel_center;
}

void	ft_calculate_shadow(t_scene *scene, t_intersection *inter, t_element *element)
{
	t_intersection	*shadow_inter;

	shadow_inter = malloc(sizeof(t_intersection));
	ft_get_shadow_ray(scene, inter, shadow_inter);
	ft_hit_something_shadow(scene, shadow_inter, element);
	if (shadow_inter->state == 1)
	{
		inter->shadow = 1;
		inter->shadow_element = shadow_inter->element;
	}
}

void	ft_get_shadow_ray(t_scene *scene, t_intersection *inter, t_intersection *shadow_inter)

{
	shadow_inter->ray.origin = inter->position;
	shadow_inter->ray.direction = ft_sub_vectors(scene->light.position, inter->position);
}

void	ft_hit_something_shadow(t_scene *scene, t_intersection *shadow_inter, t_element *element)

{
	t_element	*c_element;

	c_element = scene->elements;
	while (c_element)
	{
		if (c_element != element)
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