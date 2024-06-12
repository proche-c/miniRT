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


void	ft_inter_cy(t_intersection *inter, t_element *c_element)
{
	t_quadratic	*quadratic;
	t_vector	oc;
	t_vector	ocn;
	t_vector	dn;
	float		t[2];
	float		disc;
	// float			a;
	// float			b;
	// float			c;
	// float			r;

	// printf("ft_inter_cy\n");
	// r = c_element->diameter / 2;
	quadratic = malloc(sizeof(t_quadratic));
	oc = ft_sub_vectors(inter->ray.origin, c_element->position);
	ocn = ft_cross(oc, c_element->n_vector);
	dn = ft_cross(inter->ray.direction, c_element->n_vector);
	ft_get_quadratic(c_element, quadratic, ocn, dn);
	disc = quadratic->b * quadratic->b - 4 * quadratic->a * quadratic->c;
	// printf("disc: %f\n", disc);
	if (disc < 0)
		return ;
	t[0] = (-quadratic->b + sqrtf(quadratic->b * quadratic->b - 4 * quadratic->a * quadratic->c)) / (2 * quadratic->a);
	t[1] = (-quadratic->b - sqrtf(quadratic->b * quadratic->b - 4 * quadratic->a * quadratic->c)) / (2 * quadratic->a);
	// printf("t[0]: %f\n", t[0]);
	// printf("t[1]: %f\n", t[1]);
	if (t[0] > 0 && t[1] > 0)
		ft_get_inter_cy_1(inter, c_element, t);
	else if (t[0] > 0)
	{
		ft_get_inter_cy_2(inter, c_element, t[0]);
	}
	else if (t[1] > 0)
	{
		ft_get_inter_cy_2(inter, c_element, t[1]);
	}
	if (inter->state == 1)
	{
		ft_print_intersection(inter);
	}
	// a = ft_dot(c_element->n_vector, c_element->n_vector);
	// b = 2 * ft_dot(ocn, dn);
	// c = ft_dot(ocn, ocn) - r * r *
	// 	ft_dot(c_element->n_vector, c_element->n_vector);
	// printf("a: %f; quadratic->a: %f\n", a, quadratic->a);
	// printf("b: %f; quadratic->b: %f\n", b, quadratic->b);
	// printf("c: %f; quadratic->c: %f\n", c, quadratic->c);
	return ;
}

void	ft_get_quadratic(t_element *c_element, t_quadratic *quadratic,
	t_vector ocn, t_vector dn)
{
	float		r;

	r = c_element->diameter / 2;
	quadratic->a = ft_dot(c_element->n_vector, c_element->n_vector);
	quadratic->b = 2 * ft_dot(ocn, dn);
	quadratic->c = ft_dot(ocn, ocn) - r * r *
		ft_dot(c_element->n_vector, c_element->n_vector);	
}
	
void	ft_get_inter_cy_1(t_intersection *inter, t_element *c_element, float t[2])
{
	t_vector	inter_point_1;
	t_vector	inter_point_2;
	float		inter_point_1_proj;
	float		inter_point_2_proj;

	inter_point_1 = ft_add_vectors(inter->ray.origin, ft_mult_vector_float(inter->ray.direction, t[0]));
	inter_point_2 = ft_add_vectors(inter->ray.origin, ft_mult_vector_float(inter->ray.direction, t[1]));
	inter_point_1_proj = ft_dot(ft_sub_vectors(inter_point_1, c_element->position), c_element->n_vector);
	inter_point_2_proj = ft_dot(ft_sub_vectors(inter_point_2, c_element->position), c_element->n_vector);
	// printf("inter_point_1_proj: %f\n", inter_point_1_proj);
	// printf("inter_point_2_proj: %f\n", inter_point_2_proj);
	if (inter_point_1_proj >= 0 && inter_point_1_proj <= c_element->height)
	{
		if (inter->state == 0)
		{
			inter->position.x = inter_point_1.x;
			inter->position.y = inter_point_1.y;
			inter->position.z = inter_point_1.z;
			inter->element = c_element;
			inter->state = 1;
		}
		else
			ft_get_closest_point(inter, inter_point_1, c_element);
	}
	if (inter_point_2_proj >= 0 && inter_point_2_proj <= c_element->height)
	{
		if (inter->state == 0)
		{
			inter->position.x = inter_point_2.x;
			inter->position.y = inter_point_2.y;
			inter->position.z = inter_point_2.z;
			inter->element = c_element;
			inter->state = 1;
		}
		else
			ft_get_closest_point(inter, inter_point_1, c_element);
	}
}

void	ft_get_inter_cy_2(t_intersection *inter, t_element *c_element, float t)
{
	t_vector	inter_point;
	float		inter_point_proj;

	inter_point = ft_add_vectors(inter->ray.origin, ft_mult_vector_float(inter->ray.direction, t));
	inter_point_proj = ft_dot(ft_sub_vectors(inter_point, c_element->position), c_element->n_vector);
	if (inter_point_proj >= 0 && inter_point_proj <= c_element->height)
	{
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
}

// void	ft_get_inter_sp(t_intersection *inter, float disc, float h, float a)
// {
// 	t_vector	inter_point;
// 	float		t;

// 	t = (h - sqrtf(disc)) / a;
// 	inter_point = ft_mult_vector_float(inter->ray.direction, t);
// 	inter_point = ft_add_vectors(inter->ray.origin, inter_point);
// 	if (inter->state == 0)
// 	{
// 		inter->position.x = inter_point.x;
// 		inter->position.y = inter_point.y;
// 		inter->position.z = inter_point.z;
// 		inter->state = 1;
// 	}
// 	else
// 		ft_get_closest_point(inter, inter_point);
// }

// void	ft_get_closest_point(t_intersection *inter, t_vector inter_point)
// {
// 	float		length1;
// 	float		length2;
// 	t_vector	v1;
// 	t_vector	v2;

// 	v1 = ft_sub_vectors(inter_point, inter->ray.pixel_center);
// 	length1 = ft_get_vector_length(v1);
// 	v2 = ft_sub_vectors(inter->position, inter->ray.pixel_center);
// 	length2 = ft_get_vector_length(v2);
// 	if (length1 < length2)
// 	{
// 		inter->position.x = inter_point.x;
// 		inter->position.y = inter_point.y;
// 		inter->position.z = inter_point.z;		
// 	}
// }