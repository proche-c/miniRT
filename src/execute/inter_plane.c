/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2023/10/05 00:11:28 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_inter_pl(t_intersection *inter, t_element *c_element)
{
	float		inter_exists;
	float		t;

	inter_exists = ft_dot(inter->ray.direction, c_element->n_vector);
	if (inter_exists != 0)
	{
		t = ft_dot(ft_sub_vectors(c_element->position, inter->ray.origin),
				c_element->n_vector) / inter_exists;
		if (t > 0)
		{
			ft_get_inter_pl(inter, c_element, t);
		}
	}
	return ;
}
	// inter->position = ft_add_vectors(inter->ray.origin,
	// 	ft_mult_vector_float(inter->ray.direction, inter->t));
	// inter->color = c_element->color;
	// inter->state = 1;

void	ft_get_inter_pl(t_intersection *inter, t_element *c_element, float t)
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
