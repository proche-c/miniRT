/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:32:58 by ageiser           #+#    #+#             */
/*   Updated: 2022/09/20 15:41:05 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/minirt.h"

// Transform a normal vector to the world coordinate from the local
t_vector	transform_point_to_world(t_vector local_normal, t_vector n_vector)
{
	t_vector	world_normal;
	t_vector	up;
	t_vector	right;

	up.x = 0;
	up.y = 1;
	up.z = 0;
	if (fabs(n_vector.y) > 0.99)
	{
		up.x = 1;
		up.y = 0;
		up.z = 0;
	}
	right = ft_cross(up, n_vector);
	right = normalize(right);
	up = ft_cross(n_vector, right);
	up = normalize(up);
	world_normal.x = local_normal.x * right.x + local_normal.y * \
	up.x + local_normal.z * n_vector.x;
	world_normal.y = local_normal.x * right.y + local_normal.y * \
	up.y + local_normal.z * n_vector.y;
	world_normal.z = local_normal.x * right.z + local_normal.y * \
	up.z + local_normal.z * n_vector.z;
	return (world_normal);
}

// The transform_point_to_world function transforms a given normal 
// vector local_normal from local coordinates (relative to a cylinder's 
// surface) into global/world coordinates.

t_vector	calculate_cylinder_normal(t_element *element, t_intersection *inter)
{
	t_vector	local_point;
	t_vector	local_normal;
	t_vector	normal;

	local_point = transform_point_to_local(inter->position, element->position, \
	element->n_vector);
	local_normal.x = local_point.x;
	local_normal.y = 0;
	local_normal.z = local_point.z;
	local_normal = normalize(local_normal);
	normal = transform_point_to_world(local_normal, element->n_vector);
	return (normalize(normal));
}

// local_normal.y = 0; // Assurez-vous que la composante y 
// est nulle pour un cylindre