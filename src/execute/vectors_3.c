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

t_vector	ft_div_vector_float(t_vector v, float f)
{
	t_vector	result;
	int			temp;

	result.x = v.x / f;
	result.y = v.y / f;
	result.z = v.z / f;
	result.length_squared = v.length_squared;
	result.length = v.length;
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

float	ft_distance(t_vector v1, t_vector v2)
{
	float	x;
	float	y;
	float	z;

	x = v1.x - v2.x;
	y = v1.y - v2.y;
	z = v1.z - v2.z;
	x = pow(x, 2);
	y = pow(y, 2);
	z = pow(z, 2);
	return (sqrt(x + y + z));
}
