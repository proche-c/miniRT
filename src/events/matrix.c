#include "../../include/minirt.h"

//4d vector (adding a vect)
t_matrix create_translation_matrix(float tx, float ty, float tz) 
{
    t_matrix mat = {{
        {1, 0, 0, tx},
        {0, 1, 0, ty},
        {0, 0, 1, tz},
        {0, 0, 0,  1}
    }};
    return mat;
}

t_matrix create_rotation_matrix_x(float angle) 
{
    t_matrix mat = {{
        {1, 0, 0, 0},
        {0, cos(angle), -sin(angle), 0},
        {0, sin(angle), cos(angle), 0},
        {0, 0, 0, 1}
    }};
    return mat;
}

t_matrix create_rotation_matrix_y(float angle) 
{
    t_matrix mat = {{
        { cos(angle), 0, sin(angle), 0},
        { 0, 1, 0, 0},
        {-sin(angle), 0, cos(angle), 0},
        { 0, 0, 0, 1}
    }};
    return mat;
}

t_matrix create_rotation_matrix_z(float angle) 
{
    t_matrix mat = {{
        {cos(angle), -sin(angle), 0, 0},
        {sin(angle), cos(angle), 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    }};
    return mat;
}

t_matrix create_scaling_matrix(float sx, float sy, float sz) 
{
    t_matrix mat = {{
        {sx, 0, 0, 0},
        {0, sy, 0, 0},
        {0, 0, sz, 0},
        {0, 0, 0,  1}
    }};
    return mat;
}

t_vector apply_matrix(t_matrix mat, t_vector vec) 
{
    t_vector result;
    result.x = mat.m[0][0] * vec.x + mat.m[0][1] * vec.y + mat.m[0][2] * vec.z + mat.m[0][3] * 1.0f; // 1.0f is the w component
    result.y = mat.m[1][0] * vec.x + mat.m[1][1] * vec.y + mat.m[1][2] * vec.z + mat.m[1][3] * 1.0f;
    result.z = mat.m[2][0] * vec.x + mat.m[2][1] * vec.y + mat.m[2][2] * vec.z + mat.m[2][3] * 1.0f;
    /*
    printf("resultx = %f\n", result.x);
    printf("resulty = %f\n", result.y);
    printf("resultz = %f\n", result.z);
*/
    
    
    return result;
}

t_matrix multiply_matrices(t_matrix m1, t_matrix m2) 
{
    t_matrix result;
    int i = 0, j = 0, k = 0;

    while (i < 4) 
    {
        j = 0;
        while (j < 4) 
        {
            result.m[i][j] = 0;
            k = 0;
            while (k < 4) 
            {
                result.m[i][j] += m1.m[i][k] * m2.m[k][j];
                k++;
            }
            j++;
        }
        i++;
    }

    return result;
}


