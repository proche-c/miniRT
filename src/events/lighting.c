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

t_vector reflect_vector(t_vector incident, t_vector normal)
{
    double dot_product = ft_dot(incident, normal);
    t_vector reflected = 
    {
        .x = incident.x - 2 * dot_product * normal.x,
        .y = incident.y - 2 * dot_product * normal.y,
        .z = incident.z - 2 * dot_product * normal.z,
        .length_squared = 0,
        .length = 0
    };
    return normalize(reflected);
}
/*
// Calculate lighting at an intersection point
t_color calculate_lighting(t_scene *scene, t_intersection *inter, t_vector normal, t_vector view_dir) 
{
    t_color inter_color = inter->element->color;
    t_light *light = &scene->light;
    t_ambient *ambient = &scene->ambient;

    t_vector light_dir = ft_sub_vectors(light->position, inter->position);

    // Normalize the light direction
    light_dir = normalize(light_dir);
    normal = normalize(normal);
    view_dir = normalize(view_dir);
  //  printf("Normalized light_dir: (%f, %f, %f)\n", light_dir.x, light_dir.y, light_dir.z);

    // Diffuse lighting (Phong reflection model)
    double diff = fmax(ft_dot(normal, light_dir), 0.0);
  
    t_color ambient_diffuse_color;
    
    if (inter->shadow == 0)
    {
        ambient_diffuse_color.r = ambient->ratio * ambient->color.r + light->ratio * inter->element->color.r * diff;
        ambient_diffuse_color.g = ambient->ratio * ambient->color.g + light->ratio * inter->element->color.g * diff;
        ambient_diffuse_color.b = ambient->ratio * ambient->color.b + light->ratio * inter->element->color.b * diff;
    }
    else
    {
        ambient_diffuse_color.r = ambient->ratio * ambient->color.r + inter->element->color.r * diff;
        ambient_diffuse_color.g = ambient->ratio * ambient->color.g + inter->element->color.g * diff;
        ambient_diffuse_color.b = ambient->ratio * ambient->color.b + inter->element->color.b * diff;
    }
    inter_color = add_light(inter_color, ambient_diffuse_color, ambient->ratio);

 

            // Specular lighting // Shininess factor (not mandatory)
    
    t_vector reflection = reflect_vector(light_dir, normal);
    double spec = pow(fmax(dot_product(reflection, view_dir), 0.0), 32); // 32 is the shininess factor
    inter_color.r += light->ratio * 255 * spec;
    inter_color.g += light->ratio * 255 * spec;
    inter_color.b += light->ratio * 255 * spec;


    return inter_color;
}*/

t_color calculate_lighting(t_scene *scene, t_intersection *inter, t_vector normal, t_vector view_dir)
{
    t_color inter_color = inter->element->color;
    t_light *light = &scene->light;
    t_ambient *ambient = &scene->ambient;

    // Calculate vector from intersection point to light source
    t_vector light_dir = ft_sub_vectors(light->position, inter->position);

    // Normalize the light direction
    light_dir = ft_unit_vector(light_dir);

    // Normalize the normal and view direction vectors
    normal = ft_unit_vector(normal);
    view_dir = ft_unit_vector(view_dir);

    // Create shadow ray
    t_ray shadow_ray = create_shadow_ray(inter->position, light->position);
    int in_shadow = is_in_shadow(scene, shadow_ray, light, inter);

    // If the point is in shadow, only ambient light applies
    
    if (in_shadow)
    {
        return (t_color){
            .r = ambient->ratio * inter->element->color.r,
        .g = ambient->ratio * inter->element->color.g,
        .b = ambient->ratio * inter->element->color.b 
        };
    }

    // Diffuse lighting (Lambertian reflection)
    double diff = fmax(ft_dot(normal, light_dir), 0.0);

    t_color ambient_diffuse_color = {
        .r = ambient->ratio * ambient->color.r + light->ratio * inter->element->color.r * diff,
        .g = ambient->ratio * ambient->color.g + light->ratio * inter->element->color.g * diff,
        .b = ambient->ratio * ambient->color.b + light->ratio * inter->element->color.b * diff
    };
    inter_color = add_light(inter_color, ambient_diffuse_color, ambient->ratio);
/*
    // Specular lighting (Phong reflection model)
    t_vector reflection = reflect_vector(light_dir, normal);
    double spec = pow(fmax(ft_dot(reflection, view_dir), 0.0), 32); // 32 is the shininess factor
    inter_color.r += light->ratio * 255 * spec;
    inter_color.g += light->ratio * 255 * spec;
    inter_color.b += light->ratio * 255 * spec;*/

    return inter_color;
}