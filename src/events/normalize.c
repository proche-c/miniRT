#include "../../include/minirt.h"

//sphere(center c, radius r, intersection point p, normal n)

    //n = (p - c) / r

//plane (normal n, point p) n = constant
    
        //n = n

//cylinder (center c, radius r, intersection point p, normal n)
    
        //n = (p - c) / r

        // Function to normalize a vector

t_vector cross_product(t_vector a, t_vector b) {
    t_vector result;
    result.x = a.y * b.z - a.z * b.y;
    result.y = a.z * b.x - a.x * b.z;
    result.z = a.x * b.y - a.y * b.x;
    result.length_squared = 0; // Initialize or calculate if needed
    result.length = 0; // Initialize or calculate if needed
    return result;
}

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


t_vector    calculate_sphere_normal(t_element *element, t_intersection *inter, t_vector normal)
{
    //vector from the center of the sphere to the intersection point
    normal.x = inter->position.x - element->position.x;
    normal.y = inter->position.y - element->position.y;
    normal.z = inter->position.z - element->position.z;
    //normalize the vector
    normal = normalize(normal);
    printf("Normal vector: %f %f %f\n", normal.x, normal.y, normal.z);
    return (normal);
}

t_vector    calculate_plane_normal(t_element *element, t_vector normal)
{
    normal.x = element->position.x;
    normal.y = element->position.y;
    normal.z = element->position.z;
    printf("Normal vector: %f %f %f\n", normal.x, normal.y, normal.z);
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
    };  // Arbitrary up vector

    if (fabs(n_vector.y) > 0.99) 
    {
        up = (t_vector){
            .x = 1,
            .y = 0,
            .z = 0,
            .length_squared = 0,
            .length = 0
        }; // Change up vector if axis is almost vertical
    }

    t_vector right = cross_product(up, n_vector);
    right = normalize(right);
    up = cross_product(n_vector, right);
    up = normalize(up);

    t_vector relative_point = {
        .x = inter_position.x - cylinder_position.x,
        .y = inter_position.y - cylinder_position.y,
        .z = inter_position.z - cylinder_position.z,
        .length_squared = 0, // Initialize or calculate if needed
        .length = 0          // Initialize or calculate if needed
    };

    local_point.x = relative_point.x * right.x + relative_point.y * right.y + relative_point.z * right.z;
    local_point.y = relative_point.x * up.x + relative_point.y * up.y + relative_point.z * up.z;
    local_point.z = relative_point.x * n_vector.x + relative_point.y * n_vector.y + relative_point.z * n_vector.z;
    local_point.length_squared = 0; // Initialize or calculate if needed
    local_point.length = 0; // Initialize or calculate if needed

    printf("Local cylinder point: %f %f %f\n", local_point.x, local_point.y, local_point.z);
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

    printf("Normal cylinder vector: %f %f %f\n", normal.x, normal.y, normal.z);
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
    }; // Arbitrary up vector

    if (fabs(n_vector.y) > 0.99) 
    {
        up = (t_vector){
            .x = 1,
            .y = 0,
            .z = 0,
            .length_squared = 0,
            .length = 0
        }; // Change up vector if axis is almost vertical
    }

    t_vector right = cross_product(up, n_vector);
    right = normalize(right);
    up = cross_product(n_vector, right);
    up = normalize(up);

    world_normal.x = local_normal.x * right.x + local_normal.y * up.x + local_normal.z * n_vector.x;
    world_normal.y = local_normal.x * right.y + local_normal.y * up.y + local_normal.z * n_vector.y;
    world_normal.z = local_normal.x * right.z + local_normal.y * up.z + local_normal.z * n_vector.z;
    world_normal.length_squared = 0; // Initialize or calculate if needed
    world_normal.length = 0; // Initialize or calculate if needed

    printf("World cylinder normal: %f %f %f\n", world_normal.x, world_normal.y, world_normal.z);
    return world_normal;
}