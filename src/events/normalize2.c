/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:32:58 by ageiser           #+#    #+#             */
/*   Updated: 2022/09/20 15:41:05 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/minirt.h"

// Transform a normal vector to the world coordinate from the local
t_vector	transform_point_to_world(t_vector local_normal, t_vector n_vector)
{
	t_vector	world_normal;
	t_vector	up;
	t_vector	right;

	up.x = 0;
	up.y = 1;
	up.z = 0;
	up.length_squared = 0;
	up.length = 0;
	if (fabs(n_vector.y) > 0.99)
	{
		up.x = 1;
		up.y = 0;
		up.z = 0;
		up.length_squared = 0;
		up.length = 0;
	}
	right = ft_cross(up, n_vector);
	right = normalize(right);
	up = ft_cross(n_vector, right);
	up = normalize(up);
	world_normal.x = local_normal.x * right.x + local_normal.y * \
	up.x + local_normal.z * n_vector.x;
	world_normal.y = local_normal.x * right.y + local_normal.y * \
	up.y + local_normal.z * n_vector.y;
	world_normal.z = local_normal.x * right.z + local_normal.y * \
	up.z + local_normal.z * n_vector.z;
	world_normal.length_squared = 0;
	world_normal.length = 0;
	return (world_normal);
}
