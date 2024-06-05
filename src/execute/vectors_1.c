/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2023/10/05 00:11:28 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector ft_add_vectors(t_vector v1, t_vector v2)
{
	t_vector	result;
	int			temp;

	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	result.z = v1.z + v2.z;
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

t_vector ft_sub_vectors(t_vector v1, t_vector v2)
{
	t_vector	result;
	int			temp;

	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	result.z = v1.z - v2.z;
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

t_vector ft_multiply_vectors(t_vector v1, t_vector v2)
{
	t_vector	result;
	int			temp;

	result.x = v1.x * v2.x;
	result.y = v1.y * v2.y;
	result.z = v1.z * v2.z;
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

t_vector ft_mult_vector_float(t_vector v, float f)
{
	t_vector	result;
	int			temp;

	result.x = v.x * f;
	result.y = v.y * f;
	result.z = v.z * f;
	// printf("result.x %f\n", result.x);
	// printf("result.y %f\n", result.y);
	// printf("result.z %f\n", result.z);
	if (fabs(result.x) < E || fabs(v.x) < E)
	{
		temp = 0;
		result.x = (float)temp;
	}
	if (fabs(result.y) < E || fabs(v.y) < E)
	{
		temp = 0;
		result.y = (float)temp;
	}
	if (fabs(result.z) < E || fabs(v.z) < E)
	{
		temp = 0;
		result.z = (float)temp;
	}
	// printf("result.x %f\n", result.x);
	// printf("result.y %f\n", result.y);
	// printf("result.z %f\n", result.z);
	return (result);
}

t_vector ft_mult_vector_float_1(t_vector v, float f)
{
	t_vector	result;
	int			temp;

	result.x = v.x * f;
	result.y = v.y * f;
	result.z = v.z * f;
	printf("result.x %f\n", result.x);
	printf("result.y %f\n", result.y);
	printf("result.z %f\n", result.z);
	if (fabs(result.x) < E || fabs(v.x) < E)
	{
		temp = 0;
		result.x = (float)temp;
	}
	if (fabs(result.y) < E || fabs(v.y) < E)
	{
		temp = 0;
		result.y = (float)temp;
	}
	if (fabs(result.z) < E || fabs(v.z) < E)
	{
		temp = 0;
		result.z = (float)temp;
	}
	printf("result.x %f\n", result.x);
	printf("result.y %f\n", result.y);
	printf("result.z %f\n", result.z);
	return (result);
}

t_vector ft_div_vector_float(t_vector v, float f)
{
	t_vector	result;
	int			temp;

	result.x = v.x / f;
	result.y = v.y / f;
	result.z = v.z / f;
	if (fabs(result.x) < E || fabs(v.x) < E)
	{
		temp = 0;
		result.x = (float)temp;
	}
	if (fabs(result.y) < E || fabs(v.x) < E)
	{
		temp = 0;
		result.y = (float)temp;
	}
	if (fabs(result.z) < E || fabs(v.x) < E)
	{
		temp = 0;
		result.z = (float)temp;
	}
	return (result);
}