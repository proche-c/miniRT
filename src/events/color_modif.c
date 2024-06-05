# include "../include/minirt.h"

typedef struct s_vec3 {
    double x;
    double y;
    double z;
} t_vec3;

/*
typedef struct s_light {
    t_vec3 position;
    double intensity;
} t_light;*/
/*
typedef struct s_color {
    int r;
    int g;
    int b;
} t_color;*/

typedef struct s_surface {
    t_vector position;
    t_vector normal;
    t_color color;
} t_surface;

// Function to calculate dot product of two vectors
double dot_product(t_vector a, t_vector b) {
    return (a.x * b.x + a.y * b.y + a.z * b.z);
}


// Function to calculate the Lambertian reflection
t_color lambertian_reflection(t_surface surface, t_light light) {
    t_vector light_dir = {light.position.x - surface.position.x, 
                        light.position.y - surface.position.y, 
                        light.position.z - surface.position.z};
    light_dir = normalize(light_dir);
    double cos_theta = dot_product(surface.normal, light_dir);
    if (cos_theta < 0) cos_theta = 0; // Clamp to 0 if negative

    t_color result;
    result.r = (int)(surface.color.r * light.ratio * cos_theta);
    result.g = (int)(surface.color.g * light.ratio * cos_theta);
    result.b = (int)(surface.color.b * light.ratio * cos_theta);

    // Clamp values to 0-255
    if (result.r > 255) result.r = 255;
    if (result.g > 255) result.g = 255;
    if (result.b > 255) result.b = 255;

    return result;
}


int reflect_tester(t_scene *scene) 
{
    t_light light = scene->light;
    t_surface surface = {{0, 0, 0}, {0, 0, 1}, {255, 0, 0}}; // Red surface
    
    printf("base color: R=%d, G=%d, B=%d\n", surface.color.r, surface.color.g, surface.color.b);
    t_color reflected_color = lambertian_reflection(surface, light);

    printf("Reflected Color: R=%d, G=%d, B=%d\n", reflected_color.r, reflected_color.g, reflected_color.b);
    

    return 0;
}

int    add_light_test(t_scene *scene)
{
	t_color scene_color;
 
	printf("change color test\n");
	printf("base color = %d\n", scene->elements->color.r);
	printf("ratio = %f\n", scene->light.ratio);
	float intensity = scene->light.ratio;


    // Ajout de la lumière à la couleur de la scène
    scene_color = add_light(scene->elements->color, intensity);

    printf("red + light = %d\n", scene_color.r);
    return (0);
}
