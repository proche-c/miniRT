#include "minirt.h"

//ambiant light
//diffuse light (lambertian reflection) how the light source interacts with the surface
//specular light (phong reflection) how the light source interacts with the viewer



// Function to calculate the reflection vector
t_vector reflect_vector(t_vector light_dir, t_vector normal) 
{
    double dot = dot_product(normal, light_dir);
    t_vector reflection = {
        2 * dot * normal.x - light_dir.x,
        2 * dot * normal.y - light_dir.y,
        2 * dot * normal.z - light_dir.z
    };
    return reflection;
}

// Calculate lighting at an intersection point
t_color calculate_lighting(t_scene *scene, t_intersection *inter, t_vector normal, t_vector view_dir) 
{
    t_color color = {0, 0, 0};
    t_light *light = &scene->light;
    t_ambient *ambient = &scene->ambient;

    // Ambient lighting
    color.r += ambient->color.r * ambient->ratio;
    color.g += ambient->color.g * ambient->ratio;
    color.b += ambient->color.b * ambient->ratio;

    // Calculate vector from intersection point to light source
    t_vector light_dir = {
        light->position.x - inter->position.x,
        light->position.y - inter->position.y,
        light->position.z - inter->position.z
    };
    light_dir = normalize(light_dir);

    // Diffuse lighting
    double diff = fmax(dot_product(normal, light_dir), 0.0);
    color.r += light->ratio * inter->element->color.r * diff;
    color.g += light->ratio * inter->element->color.g * diff;
    color.b += light->ratio * inter->element->color.b * diff;

    // Specular lighting
    t_vector reflection = reflect_vector(light_dir, normal);
    double spec = pow(fmax(dot_product(reflection, view_dir), 0.0), 32); // Shininess factor
    color.r += light->ratio * 255 * spec;
    color.g += light->ratio * 255 * spec;
    color.b += light->ratio * 255 * spec;

    // Clamp color values to [0, 255]
    color.r = fmin(color.r, 255);
    color.g = fmin(color.g, 255);
    color.b = fmin(color.b, 255);

    return color;
}