/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix2.c                                           :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:32:58 by ageiser           #+#    #+#             */
/*   Updated: 2022/09/20 15:41:05 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/minirt.h"

t_vector	apply_matrix(t_matrix mat, t_vector vec)
{
	t_vector	result;

	result.x = mat.m[0][0] * vec.x + mat.m[0][1] * \
	vec.y + mat.m[0][2] * vec.z + mat.m[0][3] * 1.0f;
	result.y = mat.m[1][0] * vec.x + mat.m[1][1] * \
	vec.y + mat.m[1][2] * vec.z + mat.m[1][3] * 1.0f;
	result.z = mat.m[2][0] * vec.x + mat.m[2][1] * \
	vec.y + mat.m[2][2] * vec.z + mat.m[2][3] * 1.0f;
	return (result);
}
// 1.0f is the w component

t_matrix	multiply_matrices(t_matrix m1, t_matrix m2)
{
	t_matrix	result;
	int			i;
	int			j;
	int			k;

	i = 0;
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
	return (result);
}
