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

t_color	calculate_lighting(t_scene *scene, t_intersection *inter, \
t_vector normal, t_vector view_dir)
{
	t_color		inter_color;
	t_light		*light;
	t_ambient	*ambient;
	t_vector	light_dir;
	t_ray		shadow_ray;
	int			in_shadow;
	t_color		ambient_diffuse_color;
	double		diff;

	inter_color = inter->element->color;
	light = &scene->light;
	ambient = &scene->ambient;
	light_dir = ft_sub_vectors(light->position, inter->position);
	light_dir = ft_unit_vector(light_dir);
	normal = ft_unit_vector(normal);
	view_dir = ft_unit_vector(view_dir);
	shadow_ray = create_shadow_ray(inter->position, light->position);
	in_shadow = is_in_shadow(scene, shadow_ray, light, inter);
	if (in_shadow)
	{
		return ((t_color){
			.r = ambient->ratio * inter->element->color.r,
			.g = ambient->ratio * inter->element->color.g,
			.b = ambient->ratio * inter->element->color.b
		});
	}
	diff = fmax(ft_dot(normal, light_dir), 0.0);
	ambient_diffuse_color.r = ambient->ratio * ambient->color.r + \
	light->ratio * inter->element->color.r * diff;
	ambient_diffuse_color.g = ambient->ratio * ambient->color.g + \
	light->ratio * inter->element->color.g * diff;
	ambient_diffuse_color.b = ambient->ratio * ambient->color.b + \
	light->ratio * inter->element->color.b * diff;
	inter_color = add_light(inter_color, ambient_diffuse_color, \
	ambient->ratio);
	return (inter_color);
}

/*
    // Specular lighting (Phong reflection model)
    t_vector reflection = reflect_vector(light_dir, normal);
    double spec = pow(fmax(ft_dot(reflection, view_dir), 0.0), 32);
	// 32 is the shininess factor
    inter_color.r += light->ratio * 255 * spec;
    inter_color.g += light->ratio * 255 * spec;
    inter_color.b += light->ratio * 255 * spec;*/