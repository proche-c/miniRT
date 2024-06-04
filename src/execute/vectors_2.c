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

	result = v.x * v.x + v.y * v.y + v.z * v.z;
	if ((result * result) > E)
		return (v.x * v.x + v.y * v.y + v.z * v.z);
	else
		return (0);
}

float	ft_get_vector_length(t_vector v)
{
	return (sqrtf(ft_get_length_squared(v)));
}

float	ft_dot(t_vector v1, t_vector v2)
{
	float	result;

	result = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	if ((result * result) > E)
		return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
	else
		return (0);
}

t_vector	ft_cross(t_vector v1, t_vector v2)
{
	t_vector	result;

	result.x = 0;
	result.y = 0;
	result.z = 0;
	if (((v1.y * v2.z - v1.z * v2.y) * (v1.y * v2.z - v1.z * v2.y)) > E)
		result.x = v1.y * v2.z - v1.z * v2.y;
	if (((v1.z * v2.x - v1.x * v2.z) * (v1.z * v2.x - v1.x * v2.z)) > E)
		result.y = v1.z * v2.x - v1.x * v2.z;
	if (((v1.x * v2.y - v1.y * v2.x) * (v1.x * v2.y - v1.y * v2.x)) > E)
		result.z = v1.x * v2.y - v1.y * v2.x;
	return (result);

}

t_vector	ft_unit_vector(t_vector v)
{
	return (ft_div_vector_float(v, ft_get_vector_length(v)));
}

