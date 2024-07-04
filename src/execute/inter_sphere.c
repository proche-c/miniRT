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

	t1 = (h - sqrtf(disc)) / a;
	t2 = (h + sqrtf(disc)) / a;
	if (t1 > 0.001 && t2 > 0.001)
	{
		if (t1 < t2)
			return (t1);
		else
			return (t2);
	}
	else if (t1 > 0.001)
		return (t1);
	else
		return (t2);
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

void	ft_get_closest_point(t_intersection *inter, \
t_vector inter_point, t_element *c_element)
{
	float		length1;
	float		length2;

	length1 = ft_distance(inter->ray.origin, inter_point);
	length2 = ft_distance(inter->ray.origin, inter->position);
	if (length1 < length2)
	{
		inter->position.x = inter_point.x;
		inter->position.y = inter_point.y;
		inter->position.z = inter_point.z;
		inter->element = c_element;
		inter->distance = ft_distance(inter->ray.origin, inter_point);
	}
}

void	ft_get_inter_sp(t_intersection *inter, t_element *c_element, float t)
{
	t_vector	inter_point;

	inter_point.x = inter->ray.origin.x + inter->ray.direction.x * t;
	inter_point.y = inter->ray.origin.y + inter->ray.direction.y * t;
	inter_point.z = inter->ray.origin.z + inter->ray.direction.z * t;
	if (inter->state == 0)
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
