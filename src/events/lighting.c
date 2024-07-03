/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:32:58 by ageiser           #+#    #+#             */
/*   Updated: 2022/09/20 15:41:05 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Function to calculate the reflection vector

t_vector	reflect_vector(t_vector incident, t_vector normal)
{
	double		dot_product;
	t_vector	reflected;

	dot_product = ft_dot(incident, normal);
	reflected.x = incident.x - 2 * dot_product * normal.x;
	reflected.y = incident.y - 2 * dot_product * normal.y;
	reflected.z = incident.z - 2 * dot_product * normal.z;
	reflected.length_squared = 0;
	reflected.length = 0;
	return (normalize(reflected));
}

// The dot product measures the magnitude of the projection 
// of the incident vector in the direction of the normal vector.
// reflected.x = incident.x - 2 * dot_product * normal.x; This 
// calculates each component of the reflected vector using the formula:
// R=I−2(I⋅N)N

t_color	calculate_shadow(t_scene *scene, t_intersection *inter, t_light *light, \
t_ambient *ambient)
{
	t_ray	shadow_ray;
	int		in_shadow;	

	shadow_ray = create_shadow_ray(inter->position, light->position);
	in_shadow = is_in_shadow(scene, shadow_ray, light, inter);
	if (in_shadow)
	{
		return ((t_color)
			{
				.r = ambient->ratio * inter->element->color.r,
				.g = ambient->ratio * inter->element->color.g,
				.b = ambient->ratio * inter->element->color.b
			});
	}
	return ((t_color){-1, -1, -1});
}
//return (t_color){-1, -1, -1}; Return an invalid color to signify no shadow

t_color	calculate_color(t_intersection *inter, t_vector normal, \
t_vector light_dir, t_light_ambient *light_ambient)
{
	double	diff;
	t_color	ambient_diffuse_color;

	diff = fmax(ft_dot(normal, light_dir), 0.0);
	ambient_diffuse_color.r = light_ambient->ambient->ratio * \
	light_ambient->ambient->color.r + light_ambient->light->ratio * \
	inter->element->color.r * diff;
	ambient_diffuse_color.g = light_ambient->ambient->ratio * \
	light_ambient->ambient->color.g + light_ambient->light->ratio * \
	inter->element->color.g * diff;
	ambient_diffuse_color.b = light_ambient->ambient->ratio * \
	light_ambient->ambient->color.b + light_ambient->light->ratio * \
	inter->element->color.b * diff;
	return (ambient_diffuse_color);
}

// function computes the final color of a surface point based on 
// ambient and diffuse lighting components.
// diff: The computed diffuse reflection factor (determined by 
// the dot product between normal and light_dir).

t_color	calculate_lighting(t_scene *scene, t_intersection *inter, \
t_vector normal, t_vector view_dir)
{
	t_light_ambient	light_ambient;
	t_vector		light_dir;
	t_color			shadow_color;
	t_color			ambient_diffuse_color;
	t_color			inter_color;

	light_ambient.light = &scene->light;
	light_ambient.ambient = &scene->ambient;
	light_dir = ft_unit_vector(ft_sub_vectors(light_ambient.light->position, \
	inter->position));
	normal = ft_unit_vector(normal);
	view_dir = ft_unit_vector(view_dir);
	shadow_color = calculate_shadow(scene, inter, \
	light_ambient.light, light_ambient.ambient);
	if (shadow_color.r != -1)
	{
		return (shadow_color);
	}
	ambient_diffuse_color = calculate_color(inter, normal, \
	light_dir, &light_ambient);
	inter_color = inter->element->color;
	inter_color = add_light(inter_color, ambient_diffuse_color, \
	light_ambient.ambient->ratio);
	return (inter_color);
}

// ft_sub_vectors: Computes the vector difference between 
// the position of the light source and the intersection point.
// ft_unit_vector: Normalizes the resulting vector light_dir 
// to have unit length, ensuring it represents a direction.

/*
    // Specular lighting (Phong reflection model)
    t_vector reflection = reflect_vector(light_dir, normal);
    double spec = pow(fmax(ft_dot(reflection, view_dir), 0.0), 32);
	// 32 is the shininess factor
    inter_color.r += light->ratio * 255 * spec;
    inter_color.g += light->ratio * 255 * spec;
    inter_color.b += light->ratio * 255 * spec;*/