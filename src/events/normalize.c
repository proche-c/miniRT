#include "../../include/minirt.h"

t_vector normalize(t_vector v) 
{
    double length = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
    double length_squared = v.x * v.x + v.y * v.y + v.z * v.z;
    t_vector norm = {
        .x = v.x / length,
        .y = v.y / length,
        .z = v.z / length,
        .length_squared = length_squared,
        .length = length
    };
    return norm;
}


t_vector    calculate_sphere_normal(t_element *element, t_intersection *inter)
{
    t_vector normal;
    normal.x = inter->position.x - element->position.x;
    normal.y = inter->position.y - element->position.y;
    normal.z = inter->position.z - element->position.z;
    normal = normalize(normal);
    return (normal);
}

t_vector    calculate_plane_normal(t_element *element, t_vector normal)
{
    normal.x = element->n_vector.x;
    normal.y = element->n_vector.y;
    normal.z = element->n_vector.z;
    return (normal);
}

// Transforms a point to the local coordinate system of the cylinder
t_vector transform_point_to_local(t_vector inter_position, t_vector cylinder_position, t_vector n_vector)
{
    t_vector local_point;
    t_vector up = {
        .x = 0,
        .y = 1,
        .z = 0,
        .length_squared = 0,
        .length = 0
    };

    if (fabs(n_vector.y) > 0.99) 
    {
        up = (t_vector){
            .x = 1,
            .y = 0,
            .z = 0,
            .length_squared = 0,
            .length = 0
        };
    }

    t_vector right = ft_cross(up, n_vector);
    right = normalize(right);
    up = ft_cross(n_vector, right);
    up = normalize(up);

    t_vector relative_point = {
        .x = inter_position.x - cylinder_position.x,
        .y = inter_position.y - cylinder_position.y,
        .z = inter_position.z - cylinder_position.z,
        .length_squared = 0,
        .length = 0
    };

    local_point.x = relative_point.x * right.x + relative_point.y * right.y + relative_point.z * right.z;
    local_point.y = relative_point.x * up.x + relative_point.y * up.y + relative_point.z * up.z;
    local_point.z = relative_point.x * n_vector.x + relative_point.y * n_vector.y + relative_point.z * n_vector.z;
    local_point.length_squared = 0;
    local_point.length = 0;
    return local_point;
}

t_vector calculate_cylinder_normal(t_element *element, t_intersection *inter, t_vector normal)
{
    t_vector local_point = transform_point_to_local(inter->position, element->position, element->n_vector);
    t_vector local_normal = {
        .x = local_point.x,
        .y = 0,
        .z = local_point.z,
        .length_squared = 0,
        .length = 0
    };

    local_normal = normalize(local_normal);
    normal = transform_point_to_world(local_normal, element->n_vector);
    return normal;
}

// Transforms a normal vector back to the world coordinate system from the local system
t_vector transform_point_to_world(t_vector local_normal, t_vector n_vector)
{
    t_vector world_normal;
    t_vector up = {
        .x = 0,
        .y = 1,
        .z = 0,
        .length_squared = 0,
        .length = 0
    }; 

    if (fabs(n_vector.y) > 0.99) 
    {
        up = (t_vector){
            .x = 1,
            .y = 0,
            .z = 0,
            .length_squared = 0,
            .length = 0
        };
    }

    t_vector right = ft_cross(up, n_vector);
    right = normalize(right);
    up = ft_cross(n_vector, right);
    up = normalize(up);

    world_normal.x = local_normal.x * right.x + local_normal.y * up.x + local_normal.z * n_vector.x;
    world_normal.y = local_normal.x * right.y + local_normal.y * up.y + local_normal.z * n_vector.y;
    world_normal.z = local_normal.x * right.z + local_normal.y * up.z + local_normal.z * n_vector.z;
    world_normal.length_squared = 0;
    world_normal.length = 0; 
    return world_normal;
}