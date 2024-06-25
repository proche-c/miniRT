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

// Calculate lighting at an intersection point
t_color calculate_lighting(t_scene *scene, t_intersection *inter, t_vector normal, t_vector view_dir) 
{
    t_color inter_color = inter->element->color;
    t_light *light = &scene->light;
    t_ambient *ambient = &scene->ambient;

    t_vector light_dir = ft_sub_vectors(light->position, inter->position);

    light_dir = normalize(light_dir);
    normal = normalize(normal);
    view_dir = normalize(view_dir);
    double diff = fmax(ft_dot(normal, light_dir), 0.0);
  
    t_color ambient_diffuse_color = {
        .r = ambient->ratio * ambient->color.r + light->ratio * inter->element->color.r * diff,
        .g = ambient->ratio * ambient->color.g + light->ratio * inter->element->color.g * diff,
        .b = ambient->ratio * ambient->color.b + light->ratio * inter->element->color.b * diff
    };
    inter_color = add_light(inter_color, ambient_diffuse_color, ambient->ratio);

            // Specular lighting // Shininess factor (not mandatory)
    /*
    t_vector reflection = reflect_vector(light_dir, normal);
    double spec = pow(fmax(dot_product(reflection, view_dir), 0.0), 32); // 32 is the shininess factor
    inter_color.r += light->ratio * 255 * spec;
    inter_color.g += light->ratio * 255 * spec;
    inter_color.b += light->ratio * 255 * spec;
*/

    return inter_color;
}