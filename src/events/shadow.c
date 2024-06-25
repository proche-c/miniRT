#include "../../include/minirt.h"

t_ray create_shadow_ray(t_vector origin, t_vector light_position)
{
    t_ray shadow_ray;
    
    shadow_ray.origin = origin;
    shadow_ray.direction = ft_sub_vectors(light_position, origin);
    shadow_ray.t_min = SHADOW_RAY_MIN_DISTANCE; // Ajustez cette valeur selon votre scène
    shadow_ray.t_max = ft_get_vector_length(shadow_ray.direction); // Distance maximale du rayon
    
    return shadow_ray;
}

int is_in_hard_shadow(t_scene *scene, t_ray shadow_ray, double max_distance)
{
    t_intersection inter;

    // Parcourez tous les objets de la scène pour vérifier les intersections
    for (int i = 0; i < scene->num_objects; i++)
    {
        if (intersect(scene->objects[i], shadow_ray, &inter) && inter.distance < max_distance)
        {
            return 1; // Une intersection est trouvée avant d'atteindre la lumière
        }
    }
    return 0; // Aucune intersection trouvée, le point n'est pas dans l'ombre
}

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
    double max_distance = ft_get_vector_length(ft_sub_vectors(light->position, inter->position));
    int in_hard_shadow = is_in_hard_shadow(scene, shadow_ray, max_distance);

    // If the point is in hard shadow, only ambient light applies
    if (in_hard_shadow)
    {
        return (t_color){
            .r = ambient->ratio * ambient->color.r,
            .g = ambient->ratio * ambient->color.g,
            .b = ambient->ratio * ambient->color.b
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

    // Specular lighting (Phong reflection model)
    t_vector reflection = reflect_vector(light_dir, normal);
    double spec = pow(fmax(ft_dot(reflection, view_dir), 0.0), 32); // 32 is the shininess factor
    inter_color.r += light->ratio * 255 * spec;
    inter_color.g += light->ratio * 255 * spec;
    inter_color.b += light->ratio * 255 * spec;

    return inter_color;
}