/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2023/10/05 00:11:28 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	ft_get_length_squared(t_vector v)
{
	float	result;
	int		temp;

	result = v.x * v.x + v.y * v.y + v.z * v.z;
	if (fabs(result) > E)
		return (result);
	else
	{
		temp = 0;
		result = (float)temp;
		return (result);
	}
}

float	ft_get_vector_length(t_vector v)
{
	float	result;
	int		temp;

	result = sqrtf(ft_get_length_squared(v));
	if (fabs(result) < E)
	{
		temp = 0;
		result = (float)temp;
	}
	return (result);
}

float	ft_dot(t_vector v1, t_vector v2)
{
	float	result;
	int		temp;

	result = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	if (fabs(result) > E)
		return (result);
	else
	{
		temp = 0;
		result = (float)temp;
		return (result);
	}
}

t_vector	ft_cross(t_vector v1, t_vector v2)
{
	t_vector	result;
	int			temp;

	result.x = v1.y * v2.z - v1.z * v2.y;
	result.y = v1.z * v2.x - v1.x * v2.z;
	result.z = v1.x * v2.y - v1.y * v2.x;
	if (fabs(result.x) < E)
	{
		temp = 0;
		result.x = (float)temp;
	}
	if (fabs(result.y) < E)
	{
		temp = 0;
		result.y = (float)temp;
	}
	if (fabs(result.z) < E)
	{
		temp = 0;
		result.z = (float)temp;
	}
	return (result);
}

// Dot Product: Results in a scalar, measures how much two vectors 
// point in the same direction, used for projections and angles.
// Cross Product: Results in a vector perpendicular to the original 
// vectors, used for determining perpendicularity and 
// calculating areas and torques.

t_vector	ft_unit_vector(t_vector v)
{
	return (ft_div_vector_float(v, ft_get_vector_length(v)));
}

	// float	length;	
	// length = ft_get_vector_length(v);
