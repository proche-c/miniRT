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
/*
t_vector ft_multiply_vector_scalar(t_vector v, float scalar) {
    t_vector result;

    result.x = v.x * scalar;
    result.y = v.y * scalar;
    result.z = v.z * scalar;

    return result;
}*/
/*
void ft_inter_sp(t_intersection *inter, t_element *c_element) //including the matrix
{
    t_vector	oc;
	float		a;
	float		h;
	float		c;
	float		disc;
	float	t;

// Créer la matrice de translation
    t_matrix translation_matrix = create_translation_matrix(-c_element->position.x, -c_element->position.y, -c_element->position.z);

    // Appliquer la transformation au rayon
    t_vector transformed_origin = apply_matrix(translation_matrix, inter->ray.origin);
    t_vector transformed_direction = inter->ray.direction;  // La direction du rayon ne change pas avec une simple translation

    // Calculer oc avec la sphère transformée
    oc = ft_sub_vectors((t_vector){0, 0, 0, 0, 0}, transformed_origin ); // Centre de la sphère est maintenant à l'origine
    a = ft_get_length_squared(transformed_direction);
    h = ft_dot(transformed_direction, oc);
    c = ft_get_length_squared(oc) - (c_element->diameter / 2.0) * (c_element->diameter / 2.0);
    disc = h * h - a * c;

    if (disc >= 0) 
	{
        t = (h - sqrtf(disc)) / a;
        ft_get_inter_sp(inter, c_element, t);
    }
}*/


   ///PAULA'S CODE commentend

void	ft_inter_sp(t_intersection *inter, t_element *c_element)
{
	t_vector	oc;
	float		a;
	float		h;
	float		c;
	float		disc;
	float	t;

	//t_matrix translation_matrix = create_translation_matrix(-c_element->position.x, -c_element->position.y, -c_element->position.z);
	//t_vector transformed_origin = apply_matrix(translation_matrix, inter->ray.origin);
	//t_vector transformed_direction = inter->ray.direction;
	//transformed_direction = normalize(transformed_direction);//
	//(void)transformed_origin;
	//(void)transformed_direction;
	
	//printf("OC: (%f, %f, %f, %f, %f)\n", oc.x, oc.y, oc.z, oc.length_squared, oc.length);

	// printf("entro en inter_sp.....\n");
	//oc = ft_sub_vectors( (t_vector){0, 0, 0, 0, 0}, transformed_origin );// Centre de la sphère est maintenant à l'origine
	oc = ft_sub_vectors(c_element->position, inter->ray.origin);
	//a = ft_get_length_squared(transformed_direction);
	a = ft_get_length_squared(inter->ray.direction);
	//h = ft_dot(transformed_direction, oc);
	h = ft_dot(inter->ray.direction, oc);
	// printf("h: %f\n", h);
	c = ft_get_length_squared(oc) - ((c_element->diameter / 2.0) * (c_element->diameter / 2.0));
	// printf("c: %f\n", c);
	disc = h * h - a * c;
	//printf("disc: %f\n", disc);
	if (disc >= 0)
	{
		t = (h - sqrtf(disc)) / a;
		if (t > 0.001)
		{
		ft_get_inter_sp(inter, c_element, t);
		}
	}
}

/*
void	ft_inter_sp(t_intersection *inter, t_element *c_element)
{
	t_vector	oc;
	float		a;
	float		h;
	float		c;
	float		disc;
	float		t;

	t_matrix translation_matrix = create_translation_matrix(-c_element->position.x, -c_element->position.y, -c_element->position.z);
	t_vector transformed_origin = apply_matrix(translation_matrix, inter->ray.origin);
	t_vector transformed_direction = inter->ray.direction;
	
	oc = ft_sub_vectors((t_vector){0, 0, 0, 0, 0}, transformed_origin); // Centre de la sphère est maintenant à l'origine
	a = ft_get_length_squared(transformed_direction);
	h = ft_dot(transformed_direction, oc);
	c = ft_get_length_squared(oc) - ((c_element->diameter / 2.0) * (c_element->diameter / 2.0));
	disc = h * h - a * c;

	if (disc >= 0)
	{
		t = (h - sqrtf(disc)) / a;
		if (t < inter->distance && t > 0.001)
		{
			ft_get_inter_sp(inter, c_element, t);
		}
	}
}*/


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
		inter->distance = length1;
	}
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
		inter->distance = t;
	}
	else
	{
		ft_get_closest_point(inter, inter_point, c_element);
	}
}
/*
void ft_inter_sp(t_intersection *inter, t_element *c_element)
{
    t_vector oc;
    float a, h, c, disc, t;

    t_matrix translation_matrix = create_translation_matrix(-c_element->position.x, -c_element->position.y, -c_element->position.z);
    t_vector transformed_origin = apply_matrix(translation_matrix, inter->ray.origin);
    t_vector transformed_direction = inter->ray.direction;
    
    oc = ft_sub_vectors((t_vector){0, 0, 0, 0, 0}, transformed_origin);
    a = ft_get_length_squared(transformed_direction);
    h = ft_dot(transformed_direction, oc);
    c = ft_get_length_squared(oc) - ((c_element->diameter / 2.0) * (c_element->diameter / 2.0));
    disc = h * h - a * c;

    if (disc >= 0)
    {
        t = (h - sqrtf(disc)) / a;
        t_vector inter_point = ft_add_vectors(inter->ray.origin, ft_mult_vector_float(inter->ray.direction, t));
        float distance = ft_get_vector_length(ft_sub_vectors(inter_point, inter->ray.origin));

        if (inter->state == 0 || distance < inter->distance)
        {
            inter->position = inter_point;
            inter->element = c_element;
            inter->distance = distance;
            inter->state = 1;
        }
    }
}*/
