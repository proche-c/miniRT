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


void	ft_inter_pl(t_scene *scene, t_intersection *inter, t_element *c_element)
{
	(void)scene;
	(void)inter;
	(void)c_element;

	return ;
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