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

void	ft_get_closest_point_cy(t_intersection *inter, \
t_vector inter_point, t_element *c_element)
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
		inter->cy_base = 1;
		inter->distance = ft_distance(inter->ray.origin, inter_point);
	}
}

int	ft_get_quadratic(t_quadratic *q)
{
	if (q->a == 0)
	{
		return (0);
	}
	q->disc = q->b * q->b - 4 * q->a * q->c;
	if (q->disc < 0)
		return (0);
	q->t1 = (-q->b - sqrt(q->disc)) / (q->a * 2);
	q->t2 = (-q->b + sqrt(q->disc)) / (q->a * 2);
	return (1);
}

// Si a est zéro, ce n'est pas une équation quadratique

void	ft_inter_inf_cy(t_intersection *tmp_inter, t_element *c_element)
{
	t_quadratic	q;
	t_vector	u;
	t_vector	v;

	u = ft_cross(tmp_inter->ray.direction, c_element->n_vector);
	v = ft_cross(ft_sub_vectors(tmp_inter->ray.origin, c_element->position),
			c_element->n_vector);
	q.a = ft_dot(u, u);
	q.b = 2 * ft_dot(u, v);
	q.c = ft_dot(v, v) - c_element->diameter * c_element->diameter * \
	0.25 * ft_dot(c_element->n_vector, c_element->n_vector);
	q.disc = q.b * q.b - 4 * q.a * q.c;
	if (q.disc < 0)
		return ;
	if (q.a < E)
		return ;
	q.t1 = (-q.b - sqrt(q.disc)) / (q.a * 2);
	q.t2 = (-q.b + sqrt(q.disc)) / (q.a * 2);
	if (q.t2 <= E && q.t1 <= E)
		return ;
	if (q.t1 <= E || (q.t2 > E && (q.t2 < q.t1)))
		q.t1 = q.t2;
	tmp_inter->state = 1;
	tmp_inter->position = ft_add_vectors(tmp_inter->ray.origin,
			ft_mult_vector_float(tmp_inter->ray.direction, q.t1));
}
	// printf("%f\n", q.t1);
	// printf("cy");
		// printf("q.t1: %f\n", q.t1);
	// printf("q.t2: %f\n", q.t2);
	// printf("q.disc: %f\n", q.disc);
/*
void	ft_get_inter_data_1(t_intersection *inter,
	t_intersection *tmp_inter, t_element *c_element)
{
	if (inter->state == 0)
	{
		inter->position.x = tmp_inter->position.x;
		inter->position.y = tmp_inter->position.y;
		inter->position.z = tmp_inter->position.z;
		inter->element = c_element;
		inter->cy_base = 1;
		inter->state = 1;
		inter->distance = tmp_inter->distance;
	}
	else
		ft_get_closest_point_cy(inter, tmp_inter->position, c_element);
}

void	ft_get_inter_data_2(t_intersection *inter, t_intersection *tmp_inter,
	t_element *c_element)
{
	if (inter->state == 0)
	{
		inter->position.x = tmp_inter->position.x;
		inter->position.y = tmp_inter->position.y;
		inter->position.z = tmp_inter->position.z;
		inter->element = c_element;
		inter->state = 1;
		inter->distance = tmp_inter->distance;
	}
	else
		ft_get_closest_point(inter, tmp_inter->position, c_element);
}*/
