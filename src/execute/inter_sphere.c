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
	float	t;

	// printf("entro en inter_sp.....\n");
	oc = ft_sub_vectors(c_element->position, inter->ray.origin);
	a = ft_get_length_squared(inter->ray.direction);

	h = ft_dot(inter->ray.direction, oc);
	// printf("h: %f\n", h);
	c = ft_get_length_squared(oc) - (c_element->diameter * c_element->diameter);
	// printf("c: %f\n", c);
	disc = h * h - a * c;
	printf("disc: %f\n", disc);
	if (disc >= 0)
	{
		t = (h - sqrtf(disc)) / a;
		ft_get_inter_sp(inter, c_element, t);
	}
}

void	ft_get_inter_sp(t_intersection *inter, t_element *c_element, float t)
{
	t_vector	inter_point;

	inter_point = ft_mult_vector_float(inter->ray.direction, t);
	inter_point = ft_add_vectors(inter->ray.origin, inter_point);
	if (inter->state == 0)
	{
		inter->position.x = inter_point.x;
		inter->position.y = inter_point.y;
		inter->position.z = inter_point.z;
		inter->element = c_element;
		inter->state = 1;
	}
	else
		ft_get_closest_point(inter, inter_point, c_element);
}


void	ft_get_closest_point(t_intersection *inter, t_vector inter_point, t_element *c_element)
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
		inter->element = c_element;	
	}
}