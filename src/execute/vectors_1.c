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

	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	result.z = v1.z + v2.z;
	return (result);
}

t_vector ft_sub_vectors(t_vector v1, t_vector v2)
{
	t_vector	result;

	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	result.z = v1.z - v2.z;
	return (result);
}

t_vector ft_multiply_vectors(t_vector v1, t_vector v2)
{
	t_vector	result;

	result.x = 0;
	result.y = 0;
	result.z = 0;
	if ((v1.x * v2.x * v1.x * v2.x) > E)
		result.x = v1.x * v2.x;
	if ((v1.y * v2.y * v1.y * v2.y) > E)
		result.y = v1.y * v2.y;
	if ((v1.z * v2.z * v1.z * v2.z) > E)
		result.z = v1.z * v2.z;
	return (result);
}

t_vector ft_mult_vector_float(t_vector v, float f)
{
	t_vector	result;

	result.x = v.x * f;
	result.y = v.y * f;
	result.z = v.z * f;
	if ((result.x * result.x) < E)
		result.x = 0;
	if ((result.y * result.y) < E)
		result.y = 0;
	if ((result.z * result.z) < E)
		result.z = 0;
	return (result);
}

t_vector ft_div_vector_float(t_vector v, float f)
{
	t_vector	result;

	result.x = v.x / f;
	result.y = v.y / f;
	result.z = v.z / f;
	if ((result.x * result.x) < E)
		result.x = 0;
	if ((result.y * result.y) < E)
		result.y = 0;
	if ((result.z * result.z) < E)
		result.z = 0;
	return (result);
}