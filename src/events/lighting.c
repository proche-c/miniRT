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
    //inter_color = add_light(inter_color, ambient->color, ambient->ratio);
    //inter_color = add_light(inter_color, ambient->color, ambient->ratio);

/*
    printf("inter_color.r: %d\n", inter_color.r);
    printf("inter_color.g: %d\n", inter_color.g);
    printf("inter_color.b: %d\n", inter_color.b);
    */
  


    //(void)normal;
    (void)view_dir;

    // Calculate vector from intersection point to light source
    t_vector light_dir = {
        .x = light->position.x - inter->position.x,
        .y = light->position.y - inter->position.y,
        .z = light->position.z - inter->position.z,
        .length_squared = 0,  // Initialize or calculate if needed
        .length = 0           // Initialize or calculate if needed
    };
    /*
    printf("light->position: (%f, %f, %f)\n", light->position.x, light->position.y, light->position.z);
    printf("inter->position: (%f, %f, %f)\n", inter->position.x, inter->position.y, inter->position.z);
    printf("light_dir: (%f, %f, %f)\n", light_dir.x, light_dir.y, light_dir.z); 
*/
    // Normalize the light direction
    light_dir = normalize(light_dir);
  //  printf("Normalized light_dir: (%f, %f, %f)\n", light_dir.x, light_dir.y, light_dir.z);

    // Diffuse lighting (Phong reflection model)
    double diff = fmax(dot_product(normal, light_dir), 0.0);
    //printf("dot_product(normal, light_dir): %f, normal: (%f, %f, %f), light_dir: (%f, %f, %f)\n", dot_product(normal, light_dir), normal.x, normal.y, normal.z, light_dir.x, light_dir.y, light_dir.z);
    //printf("dot_product(normal, light_dir): %f, normal: (%f, %f, %f), light_dir: (%f, %f, %f)\n", dot_product(normal, light_dir), normal.x, normal.y, normal.z, light_dir.x, light_dir.y, light_dir.z);
    // with fmax, we make sure that the value is not negative 
    // (if the angle between the normal and the light direction is greater than 90 degrees, the dot product will be negative)
    // so we clamp the value to 0
    //printf("diff: %f\n", diff);
    /*
    //printf("diff: %f\n", diff);
    /*
    inter_color.r += light->ratio * inter->element->color.r * diff;
    inter_color.g += light->ratio * inter->element->color.g * diff;
    inter_color.b += light->ratio * inter->element->color.b * diff;
    
    if (inter_color.r > 255)
        inter_color.r = 255;
    if (inter_color.g > 255)
        inter_color.g = 255;
    if (inter_color.b > 255)
        inter_color.b = 255;
    if (inter_color.r < 0)
        inter_color.r = 0;
    if (inter_color.g < 0)
        inter_color.g = 0;
    if (inter_color.b < 0)
        inter_color.b = 0;
    */
/*
   t_color diffuse_color = 
   {
    .r = (ambient->ratio * ambient->color.r) + (light->ratio * inter->element->color.r * diff),
    .g = (ambient->ratio * ambient->color.g) + (light->ratio * inter->element->color.g * diff),
    .b = (ambient->ratio * ambient->color.b) + (light->ratio * inter->element->color.b * diff)
    };
    inter_color = add_light(inter_color, diffuse_color, 1.0);
   */ 
    /*
    */
/*
   t_color diffuse_color = 
   {
    .r = (ambient->ratio * ambient->color.r) + (light->ratio * inter->element->color.r * diff),
    .g = (ambient->ratio * ambient->color.g) + (light->ratio * inter->element->color.g * diff),
    .b = (ambient->ratio * ambient->color.b) + (light->ratio * inter->element->color.b * diff)
    };
    inter_color = add_light(inter_color, diffuse_color, 1.0);
   */ 
    /*
    printf("inter_color.r: %d\n", inter_color.r);
    printf("inter_color.g: %d\n", inter_color.g);
    printf("inter_color.b: %d\n", inter_color.b);
*/




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
/*
   t_vector reflection = reflect_vector(light_dir, normal);
    double spec = pow(fmax(dot_product(reflection, view_dir), 0.0), 32); // 32 is the shininess factor
    t_color specular_color = {
        .r = light->ratio * 255 * spec,
        .g = light->ratio * 255 * spec,
        .b = light->ratio * 255 * spec
    };
    inter_color = add_light(inter_color, specular_color, 0.2);
*/
    return inter_color;
}
