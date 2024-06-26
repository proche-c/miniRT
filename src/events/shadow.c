#include "../../include/minirt.h"

t_ray create_shadow_ray(t_vector origin, t_vector light_position)
{
    t_ray shadow_ray;
    
    shadow_ray.origin = origin;
    shadow_ray.direction = ft_unit_vector(ft_sub_vectors(light_position, origin));
    shadow_ray.t_min = SHADOW_RAY_MIN_DISTANCE; // Ajustez cette valeur selon votre scène
    shadow_ray.t_max = ft_get_vector_length(ft_sub_vectors(light_position, origin)); // Distance maximale du rayon
    
    return shadow_ray;
}

int is_in_shadow(t_scene *scene, t_ray shadow_ray, t_light *light)
{
    t_intersection inter;
    inter.distance = FLT_MAX; // Initialisez la distance à une valeur maximale
    inter.state = 0;
    inter.ray = shadow_ray;

    ft_hit_something(scene, &inter);

    double max_distance = ft_get_vector_length(ft_sub_vectors(light->position, shadow_ray.origin));

    if (inter.state && inter.distance < max_distance)
    {
        return 1; // Une intersection est trouvée avant d'atteindre la lumière
    }

    return 0; // Aucune intersection trouvée, le point n'est pas dans l'ombre
}
