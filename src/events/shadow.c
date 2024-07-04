/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:50:06 by ageiser           #+#    #+#             */
/*   Updated: 2022/10/07 11:59:40 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_ray	create_shadow_ray(t_vector origin, t_vector light_position)
{
	t_ray	shadow_ray;

	shadow_ray.origin = origin;
	shadow_ray.direction = \
	ft_unit_vector(ft_sub_vectors(light_position, origin));
	shadow_ray.t_min = SHADOW_RAY_MIN_DISTANCE;
	shadow_ray.t_max = \
	ft_get_vector_length(ft_sub_vectors(light_position, origin));
	return (shadow_ray);
}
// calculate the shadow ray from the intersection point to the light source
// shadow_ray.t_max = ft_get_vector_length(ft_sub_vectors(light_position, 
// origin)); 
//The maximum distance the shadow ray can travel is the distance between the 
//intersection point and the light source

int	is_in_shadow(t_scene *scene, t_ray shadow_ray, \
t_light *light, t_intersection *inter)
{
	t_intersection	*shadow_inter;
	double			max_distance;

	shadow_inter = malloc(sizeof(t_intersection));
	shadow_inter->distance = 3.402823466e+38F;
	shadow_inter->state = 0;
	shadow_inter->is_shadow = 0;
	shadow_inter->ray = shadow_ray;
	ft_hit_something_2(scene, shadow_inter, inter->element);
	max_distance = \
	ft_get_vector_length(ft_sub_vectors(light->position, shadow_ray.origin));
	if (shadow_inter->state && shadow_inter->distance < max_distance)
	{
		free(shadow_inter);
		return (1);
	}
	free(shadow_inter);
	return (0);
}

// function determines if a point on a surface (inter) in a scene is in 
// shadow relative to a light source (light) using a shadow ray (shadow_ray). 
// It does so by checking if the shadow ray intersects with any objects in the 
// scene before reaching the light source.
// Calculates max_distance, which is the length of the vector from 
// shadow_ray.origin (point on the surface) to 
// light->position (position of the light source).
// ft_sub_vectors computes the vector difference between two 
// points (light->position and shadow_ray.origin).
// ft_get_vector_length computes the magnitude (length) of the resulting vector.