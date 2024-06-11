#include "minirt.h"

//ambiant light
//diffuse light (lambertian reflection) how the light source interacts with the surface
//specular light (phong reflection) how the light source interacts with the viewer



// Function to calculate the reflection vector

t_vector reflect_vector(t_vector incident, t_vector normal)
{
    double dot_product = incident.x * normal.x + incident.y * normal.y + incident.z * normal.z;
    t_vector reflected = 
    {
        .x = incident.x - 2 * dot_product * normal.x,
        .y = incident.y - 2 * dot_product * normal.y,
        .z = incident.z - 2 * dot_product * normal.z,
        .length_squared = 0,  // Initialize or calculate if needed
        .length = 0           // Initialize or calculate if needed
    };
    return reflected;
}

// Calculate lighting at an intersection point
t_color calculate_lighting(t_scene *scene, t_intersection *inter, t_vector normal, t_vector view_dir) 
{
    t_color inter_color = inter->element->color;
    t_light *light = &scene->light;
    t_ambient *ambient = &scene->ambient;

    // Ambient lighting
    /*
    printf("inter_color.r: %d ambient_color.r: %d ambient_ratio: %f\n", inter_color.r, ambient->color.r, ambient->ratio);
    printf("inter_color.g: %d ambient_color.g: %d ambient_ratio: %f\n", inter_color.g, ambient->color.g, ambient->ratio);
    printf("inter_color.b: %d ambient_color.b: %d ambient_ratio: %f\n", inter_color.b, ambient->color.b, ambient->ratio);
    */
    inter_color = add_light(inter_color, ambient->color, ambient->ratio);

/*
    printf("inter_color.r: %d\n", inter_color.r);
    printf("inter_color.g: %d\n", inter_color.g);
    printf("inter_color.b: %d\n", inter_color.b);
    */
  

    (void)inter;
    (void)normal;
    (void)view_dir;

    // Calculate vector from intersection point to light source
    t_vector light_dir = {
        .x = light->position.x - inter->position.x,
        .y = light->position.y - inter->position.y,
        .z = light->position.z - inter->position.z,
        .length_squared = 0,  // Initialize or calculate if needed
        .length = 0           // Initialize or calculate if needed
    };
    printf("light->position: (%f, %f, %f)\n", light->position.x, light->position.y, light->position.z);
    printf("inter->position: (%f, %f, %f)\n", inter->position.x, inter->position.y, inter->position.z);
    printf("light_dir: (%f, %f, %f)\n", light_dir.x, light_dir.y, light_dir.z); 

    // Normalize the light direction
    light_dir = normalize(light_dir);
    printf("Normalized light_dir: (%f, %f, %f)\n", light_dir.x, light_dir.y, light_dir.z);
/*
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
*/
    return inter_color;
}
