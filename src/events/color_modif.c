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
    t_vec3 position;
    t_vec3 normal;
    t_color color;
} t_surface;

// Function to calculate dot product of two vectors
double dot_product(t_vec3 a, t_vec3 b) {
    return (a.x * b.x + a.y * b.y + a.z * b.z);
}

// Function to normalize a vector
t_vec3 normalize(t_vec3 v) {
    double length = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
    t_vec3 norm = {v.x / length, v.y / length, v.z / length};
    return norm;
}

// Function to calculate the Lambertian reflection
t_color lambertian_reflection(t_surface surface, t_light light) {
    t_vec3 light_dir = {light.position.x - surface.position.x, 
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

// Example usage
int reflect_tester() 
{
    
    t_surface surface = {{0, 0, 0}, {0, 0, 1}, {255, 0, 0}}; // Red surface
    t_light light = {1, 1.0, {10, 10, 10}}; // Light source
    
    t_color reflected_color = lambertian_reflection(surface, light);

    printf("Reflected Color: R=%d, G=%d, B=%d\n", reflected_color.r, reflected_color.g, reflected_color.b);
    
    // Initialize MiniLibX and create a window
    //void *mlx = mlx_init();
    //void *win = mlx_new_window(mlx, 800, 600, "Lambertian Reflection");

    // Here you can use the reflected_color to set the pixel color in your MiniLibX window

    return 0;
}
