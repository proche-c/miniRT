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


void	ft_inter_sp(t_intersection *inter, t_element *c_element)
{
	t_vector	oc;
	float		a;
	float		h;
	float		c;
	float		disc;

	// printf("entro en inter_sp.....\n");
	oc = ft_sub_vectors(c_element->position, inter->ray.origin);
	// printf("oc.x: %f\n", oc.x);
	// printf("oc.y: %f\n", oc.y);
	// printf("oc.z: %f\n", oc.z);
	a = ft_get_length_squared(inter->ray.direction);
	// printf("inter->ray.direction.x: %f\n", inter->ray.direction.x);
	// printf("inter->ray.direction.y: %f\n", inter->ray.direction.y);
	// printf("inter->ray.direction.z: %f\n", inter->ray.direction.z);
	// printf("a: %f\n", a);
	h = ft_dot(inter->ray.direction, oc);
	// printf("h: %f\n", h);
	c = ft_get_length_squared(oc) - (c_element->diameter * c_element->diameter);
	// printf("c: %f\n", c);
	disc = h * h - a * c;
	// printf("disc: %f\n", disc);
	if (disc >= 0)
		ft_get_inter_sp(inter, disc, h, a);
}

void	ft_get_inter_sp(t_intersection *inter, float disc, float h, float a)
{
	t_vector	inter_point;
	float		t;

	t = (h - sqrtf(disc)) / a;
	inter_point = ft_mult_vector_float(inter->ray.direction, t);
	inter_point = ft_add_vectors(inter->ray.origin, inter_point);
	if (inter->state == 0)
	{
		inter->position.x = inter_point.x;
		inter->position.y = inter_point.y;
		inter->position.z = inter_point.z;
		inter->state = 1;
	}
	else
		ft_get_closest_point(inter, inter_point);
}

void	ft_get_closest_point(t_intersection *inter, t_vector inter_point)
{
	float		length1;
	float		length2;
	t_vector	v1;
	t_vector	v2;

	v1 = ft_sub_vectors(inter_point, inter->ray.pixel_center);
	length1 = ft_get_vector_length(v1);
	v2 = ft_sub_vectors(inter->position, inter->ray.pixel_center);
	length2 = ft_get_vector_length(v2);
	if (length1 < length2)
	{
		inter->position.x = inter_point.x;
		inter->position.y = inter_point.y;
		inter->position.z = inter_point.z;		
	}
}