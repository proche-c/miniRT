/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:32:58 by ageiser           #+#    #+#             */
/*   Updated: 2022/09/20 15:41:05 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_vector	normalize(t_vector v)
{
	double	length;
	double	length_squared;

	length = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	if (length == 0)
	{
		return ((t_vector){0, 0, 0, 0, 0});
	}
	length_squared = length * length;
	return ((t_vector){v.x / length, v.y / length, v.z / length, \
	length_squared, length});
}

// sqrt(v.x * v.x + v.y * v.y + v.z * v.z): Calculates the 
// Euclidean norm (magnitude) of the vector v.
// Normalization: Ensures the vector v is transformed into a 
// unit vector pointing in the same direction but with a magnitude of 1.

t_vector	calculate_sphere_normal(t_element *element, t_intersection *inter)
{
	t_vector	normal;

	normal.x = inter->position.x - element->position.x;
	normal.y = inter->position.y - element->position.y;
	normal.z = inter->position.z - element->position.z;
	normal = normalize(normal);
	return (normal);
}
// normal.x = inter->position.x - element->position.x; normal 
// between the center of the sphere and the intersection position

t_vector	calculate_plane_normal(t_element *element, t_vector normal)
{
	normal.x = element->n_vector.x;
	normal.y = element->n_vector.y;
	normal.z = element->n_vector.z;
	return (normal);
}

void	calculate_up_right(t_vector n_vector, t_vector *up, t_vector *right)
{
	up->x = 0;
	up->y = 1;
	up->z = 0;
	if (fabs(n_vector.y) > 0.99)
	{
		up->x = 1;
		up->y = 0;
		up->z = 0;
	}
	*right = ft_cross(*up, n_vector);
	*right = normalize(*right);
	*up = ft_cross(n_vector, *right);
	*up = normalize(*up);
}
// Initialization: Sets an initial up vector assuming typical 
// orientation ({0, 1, 0}).
// Cross Product Calculations: Computes orthogonal vectors 
// right and up using cross products to ensure orthogonality.

t_vector	transform_point_to_local(t_vector inter_position, \
t_vector cylinder_position, t_vector n_vector)
{
	t_vector	local_point;
	t_vector	up;
	t_vector	right;
	t_vector	relative_point;

	calculate_up_right(n_vector, &up, &right);
	relative_point.x = inter_position.x - cylinder_position.x;
	relative_point.y = inter_position.y - cylinder_position.y;
	relative_point.z = inter_position.z - cylinder_position.z;
	local_point.x = relative_point.x * right.x + relative_point.y * right.y + \
	relative_point.z * right.z;
	local_point.y = relative_point.x * up.x + relative_point.y * up.y + \
	relative_point.z * up.z;
	local_point.z = relative_point.x * n_vector.x + relative_point.y * \
	n_vector.y + relative_point.z * n_vector.z;
	return (local_point);
}

// The transform_point_to_local function transforms a given intersection 
// point inter_position from global coordinates into local coordinates 
// relative to a cylinder's surface, specified by its 
// position (cylinder_position) and orientation (n_vector).
// Calculates relative_point, which represents the vector 
// from cylinder_position to inter_position in global coordinates.