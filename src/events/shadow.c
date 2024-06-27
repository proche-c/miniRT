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

int	is_in_shadow(t_scene *scene, t_ray shadow_ray, \
t_light *light, t_intersection *inter)
{
	t_intersection	*shadow_inter;
	double			max_distance;

	shadow_inter = malloc(sizeof(t_intersection));
	shadow_inter->distance = FLT_MAX;
	shadow_inter->state = 0;
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
