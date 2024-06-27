/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                            :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:32:58 by ageiser           #+#    #+#             */
/*   Updated: 2022/09/20 15:41:05 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/minirt.h"

//4d vector (adding a vect)
t_matrix	create_translation_matrix(float tx, float ty, float tz)
{
	t_matrix	mat;

	mat.m[0][0] = 1;
	mat.m[0][1] = 0;
	mat.m[0][2] = 0;
	mat.m[0][3] = tx;
	mat.m[1][0] = 0;
	mat.m[1][1] = 1;
	mat.m[1][2] = 0;
	mat.m[1][3] = ty;
	mat.m[2][0] = 0;
	mat.m[2][1] = 0;
	mat.m[2][2] = 1;
	mat.m[2][3] = tz;
	mat.m[3][0] = 0;
	mat.m[3][1] = 0;
	mat.m[3][2] = 0;
	mat.m[3][3] = 1;
	return (mat);
}

t_matrix	create_rotation_matrix_x(float angle)
{
	t_matrix	mat;

	mat.m[0][0] = 1;
	mat.m[0][1] = 0;
	mat.m[0][2] = 0;
	mat.m[0][3] = 0;
	mat.m[1][0] = 0;
	mat.m[1][1] = cos(angle);
	mat.m[1][2] = -sin(angle);
	mat.m[1][3] = 0;
	mat.m[2][0] = 0;
	mat.m[2][1] = sin(angle);
	mat.m[2][2] = cos(angle);
	mat.m[2][3] = 0;
	mat.m[3][0] = 0;
	mat.m[3][1] = 0;
	mat.m[3][2] = 0;
	mat.m[3][3] = 1;
	return (mat);
}

t_matrix	create_rotation_matrix_y(float angle)
{
	t_matrix	mat;

	mat.m[0][0] = cos(angle);
	mat.m[0][1] = 0;
	mat.m[0][2] = sin(angle);
	mat.m[0][3] = 0;
	mat.m[1][0] = 0;
	mat.m[1][1] = 1;
	mat.m[1][2] = 0;
	mat.m[1][3] = 0;
	mat.m[2][0] = -sin(angle);
	mat.m[2][1] = 0;
	mat.m[2][2] = cos(angle);
	mat.m[2][3] = 0;
	mat.m[3][0] = 0;
	mat.m[3][1] = 0;
	mat.m[3][2] = 0;
	mat.m[3][3] = 1;
	return (mat);
}

t_matrix	create_rotation_matrix_z(float angle)
{
	t_matrix	mat;

	mat.m[0][0] = cos(angle);
	mat.m[0][1] = -sin(angle);
	mat.m[0][2] = 0;
	mat.m[0][3] = 0;
	mat.m[1][0] = sin(angle);
	mat.m[1][1] = cos(angle);
	mat.m[1][2] = 0;
	mat.m[1][3] = 0;
	mat.m[2][0] = 0;
	mat.m[2][1] = 0;
	mat.m[2][2] = 1;
	mat.m[2][3] = 0;
	mat.m[3][0] = 0;
	mat.m[3][1] = 0;
	mat.m[3][2] = 0;
	mat.m[3][3] = 1;
	return (mat);
}

t_matrix	create_scaling_matrix(float sx, float sy, float sz)
{
	t_matrix	mat;

	mat.m[0][0] = sx;
	mat.m[0][1] = 0;
	mat.m[0][2] = 0;
	mat.m[0][3] = 0;
	mat.m[1][0] = 0;
	mat.m[1][1] = sy;
	mat.m[1][2] = 0;
	mat.m[1][3] = 0;
	mat.m[2][0] = 0;
	mat.m[2][1] = 0;
	mat.m[2][2] = sz;
	mat.m[2][3] = 0;
	mat.m[3][0] = 0;
	mat.m[3][1] = 0;
	mat.m[3][2] = 0;
	mat.m[3][3] = 1;
	return (mat);
}
