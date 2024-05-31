/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2023/10/05 00:11:28 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	ft_get_ray(t_scene *scene, int j, int i)
{
	t_ray	ray;

	(void)i;
	(void)j;
	ray.origin.x = scene->camera.pov.x;

	return (ray);
}

void	ft_hit_something(t_ray ray, t_scene *scene, t_intersection *inter)
{
	(void)ray;
	(void)scene;

	inter->state = 0;

}