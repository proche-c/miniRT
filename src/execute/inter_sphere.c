/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2023/10/05 00:11:28 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	calculate_discriminant(t_ray ray, t_vector oc, float radius_squared, \
float *h)
{
	float	a;
	float	c;

	*h = ft_dot(ray.direction, oc);
	a = ft_get_length_squared(ray.direction);
	c = ft_get_length_squared(oc) - radius_squared;
	return ((*h * *h) - (a * c));
}

float	calculate_t(float h, float disc, float a)
{
	float	t1;
	float	t2;

	t1 = h - sqrtf(disc) / a;
	t2 = h + sqrtf(disc) / a;
	if (t1 < t2)
		return (t1);
	else
		return (t2);
	// return ((h - sqrtf(disc)) / a);
}

void	ft_inter_sp(t_intersection *inter, t_element *c_element)
{
	t_vector	oc;
	float		h;
	float		t;
	float		radius_squared;
	float		disc;

	oc = ft_sub_vectors(c_element->position, inter->ray.origin);
	radius_squared = (c_element->diameter / 2.0) * (c_element->diameter / 2.0);
	disc = calculate_discriminant(inter->ray, oc, radius_squared, &h);
	if (disc >= 0)
	{
		t = calculate_t(h, disc, ft_get_length_squared(inter->ray.direction));
		if (t > 0.001)
		{
			ft_get_inter_sp(inter, c_element, t);
		}
	}
}

//t_matrix translation_matrix = create_translation_matrix
//(-c_element->position.x, -c_element->position.y, -c_element->position.z);
	//t_vector transformed_origin = 
	//apply_matrix(translation_matrix, inter->ray.origin);
	//t_vector transformed_direction = inter->ray.direction;
	//transformed_direction = normalize(transformed_direction);
	//(void)transformed_origin;
	//(void)transformed_direction;
	//printf("OC: (%f, %f, %f, %f, %f)\n", oc.x, oc.y, 
	//oc.z, oc.length_squared, oc.length);

	// printf("entro en inter_sp.....\n");
	//oc = ft_sub_vectors( (t_vector){0, 0, 0, 0, 0}, transformed_origin );
	// Centre de la sphère est maintenant à l'origine
	//a = ft_get_length_squared(transformed_direction);
	//h = ft_dot(transformed_direction, oc);
	// printf("h: %f\n", h);
	// printf("c: %f\n", c);
	//printf("disc: %f\n", disc);

void	ft_get_closest_point(t_intersection *inter, \
t_vector inter_point, t_element *c_element)
{
	float		length1;
	float		length2;
	// t_vector	v1;
	// t_vector	v2;

	// v1 = ft_sub_vectors(inter_point, inter->ray.pixel_center);
	// length1 = ft_get_vector_length(v1);
	// v2 = ft_sub_vectors(inter->position, inter->ray.pixel_center);
	// length2 = ft_get_vector_length(v2);

	length1 = ft_distance(inter->ray.origin, inter_point);
	length2 = ft_distance(inter->ray.origin, inter->position);
	printf("inter->ray.direction.x: %f, inter->ray.direction.y: %f, inter->ray.direction.z: %f\n", inter->ray.direction.x, inter->ray.direction.y, inter->ray.direction.z);
	printf("inter_point.x: %f, inter_point.y: %f, inter_point.z: %f\n", inter_point.x, inter_point.y, inter_point.z);
	printf("inter->position.x: %f, inter->position.y: %f, inter->position.z: %f\n", inter->position.x, inter->position.y, inter->position.z);
	if (length1 < length2)
	{
		inter->position.x = inter_point.x;
		inter->position.y = inter_point.y;
		inter->position.z = inter_point.z;
		inter->element = c_element;
		inter->distance = ft_distance(inter->ray.origin, inter_point);
	}
	// printf("inter_point.x: %f, inter_point.y: %f, inter_point.z: %f\n", inter_point.x, inter_point.y, inter_point.z);
	// printf("inter->position.x: %f, inter->position.y: %f, inter->position.z: %f\n", inter->position.x, inter->position.y, inter->position.z);
	printf("length1: %f and length2: %f, inter->element: %s\n", length1, length2, inter->element->identifier);
}

void	ft_get_inter_sp(t_intersection *inter, t_element *c_element, float t)
{
	t_vector	inter_point;

	inter_point = ft_mult_vector_float(inter->ray.direction, t);
	inter_point = ft_add_vectors(inter->ray.origin, inter_point);
	if (inter->state == 0 || t < inter->distance)
	{
		inter->position.x = inter_point.x;
		inter->position.y = inter_point.y;
		inter->position.z = inter_point.z;
		inter->element = c_element;
		inter->state = 1;
		inter->distance = ft_distance(inter->ray.origin, inter_point);
	}
	else
	{
		ft_get_closest_point(inter, inter_point, c_element);
	}
}
	//printf("inter->distace = %f\n", inter->distance); //
