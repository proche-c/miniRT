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

void	handle_plane_intersections(t_intersection *inter, t_element *c_element, \
t_intersection *tmp_inter, t_element *plane)
{
	ft_init_tmp_plane(plane, c_element, 1);
	ft_inter_pl(tmp_inter, plane);
	if (tmp_inter->state == 1 && \
	ft_get_vector_length(ft_sub_vectors(tmp_inter->position, \
	plane->position)) <= c_element->diameter * 0.5)
	{
		ft_get_inter_data_1(inter, tmp_inter, c_element);
	}
	tmp_inter->state = 0;
	ft_init_tmp_plane(plane, c_element, 2);
	ft_inter_pl(tmp_inter, plane);
	if (tmp_inter->state == 1 && \
	ft_get_vector_length(ft_sub_vectors(tmp_inter->position, \
	plane->position)) <= c_element->diameter * 0.5)
	{
		ft_get_inter_data_1(inter, tmp_inter, c_element);
	}
	tmp_inter->state = 0;
}

void	handle_infinite_cylinder_intersection(t_intersection *inter, \
t_element *c_element, t_intersection *tmp_inter)
{
	ft_inter_inf_cy(tmp_inter, c_element);
	if (tmp_inter->state == 1 && pow(ft_distance(c_element->position, \
	tmp_inter->position), 2) <= (pow(c_element->height * 0.5, 2) + \
	c_element->diameter * c_element->diameter * 0.25))
	{
		ft_get_inter_data_2(inter, tmp_inter, c_element);
	}
}

void	ft_inter_cy(t_intersection *inter, t_element *c_element)
{
	t_element		*plane ;
	t_intersection	*tmp_inter;

	plane = NULL;
	tmp_inter = NULL;
	plane = malloc(sizeof(t_element));
	if (!plane)
		return ;
	tmp_inter = malloc(sizeof(t_intersection));
	if (!tmp_inter)
	{
		free(plane);
		return ;
	}
	ft_init_tmp_inter(tmp_inter, inter);
	handle_plane_intersections(inter, c_element, tmp_inter, plane);
	handle_infinite_cylinder_intersection(inter, c_element, tmp_inter);
	free(plane);
	free(tmp_inter);
}

/*   PAULA'S CODE
void	ft_inter_cy(t_intersection *inter, t_element *c_element)
{
	t_element		*plane;
	t_intersection	*tmp_inter;

	tmp_inter = malloc(sizeof(t_intersection));
	plane = malloc(sizeof(t_element));
	ft_init_tmp_inter(tmp_inter, inter);
	ft_init_tmp_plane(plane, c_element, 1);
	ft_inter_pl(tmp_inter, plane);
	if (tmp_inter->state == 1 && \
		ft_get_vector_length(ft_sub_vectors(tmp_inter->position,
				plane->position)) <= c_element->diameter * 0.5)
	{
		ft_get_inter_data_1(inter, tmp_inter, c_element);
	}
	tmp_inter->state = 0;
	ft_init_tmp_plane(plane, c_element, 2);
	ft_inter_pl(tmp_inter, plane);
	if (tmp_inter->state == 1 && \
		ft_get_vector_length(ft_sub_vectors(tmp_inter->position,
				plane->position)) <= c_element->diameter * 0.5)
	{
		ft_get_inter_data_1(inter, tmp_inter, c_element);
	}
	tmp_inter->state = 0;
	ft_inter_inf_cy(tmp_inter, c_element);
	if (tmp_inter->state == 1 && pow(ft_distance(c_element->position,
				tmp_inter->position), 2) <= (pow(c_element->height * 0.5, 2) + \
			c_element->diameter * c_element->diameter * 0.25))
	{
		ft_get_inter_data_2(inter, tmp_inter, c_element);
	}
	free(plane);
	free(tmp_inter);
	return ;
}*/
	//printf("plane n_vector: %f %f %f\n", plane->n_vector.x, 
	//plane->n_vector.y, plane->n_vector.z);
	//printf("cy_base");
	//printf("cy_base");

void	ft_init_tmp_inter(t_intersection *tmp_inter, t_intersection *inter)
{
	tmp_inter->state = 0;
	tmp_inter->ray.origin.x = inter->ray.origin.x;
	tmp_inter->ray.origin.y = inter->ray.origin.y;
	tmp_inter->ray.origin.z = inter->ray.origin.z;
	tmp_inter->ray.direction.x = inter->ray.direction.x;
	tmp_inter->ray.direction.y = inter->ray.direction.y;
	tmp_inter->ray.direction.z = inter->ray.direction.z;
	tmp_inter->ray.pixel_center.x = inter->ray.pixel_center.x;
	tmp_inter->ray.pixel_center.y = inter->ray.pixel_center.y;
	tmp_inter->ray.pixel_center.z = inter->ray.pixel_center.z;
}

void	ft_init_tmp_plane(t_element *plane, t_element *c_element, int point)
{
	plane->n_vector.x = c_element->n_vector.x;
	plane->n_vector.y = c_element->n_vector.y;
	plane->n_vector.z = c_element->n_vector.z;
	if (point == 1)
	{
		plane->position = \
		ft_add_vectors(ft_mult_vector_float(c_element->n_vector,
					-0.5 * c_element->height), c_element->position);
	}
	else if (point == 2)
	{
		plane->position = \
		ft_add_vectors(ft_mult_vector_float(c_element->n_vector,
					0.5 * c_element->height), c_element->position);
	}
}

//chatgpt
/*
void	ft_init_tmp_plane(t_element *plane, t_element *c_element, int point)
{
	plane->n_vector.x = c_element->n_vector.x;
	plane->n_vector.y = c_element->n_vector.y;
	plane->n_vector.z = c_element->n_vector.z;
	if (point == 1)
	{
		plane->position = ft_add_vectors(ft_mult_vector_float \
		(c_element->n_vector, 
		-0.5 * c_element->height), c_element->position);
		// Inverser la normale pour le plan inférieur
		plane->n_vector = ft_mult_vector_float(plane->n_vector, -1);
	}
	else if (point == 2)
	{
		plane->position = ft_add_vectors(ft_mult_vector_float \
		(c_element->n_vector, 
		* c_element->height), c_element->position);
	}
}*/
