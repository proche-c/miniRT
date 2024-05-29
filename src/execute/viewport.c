/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2023/10/05 00:11:28 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_create_viewport(t_scene *scene)
{
	scene->aspect_ratio = ASPECT_RATIO;
	scene->image_width = 800;
	scene->image_height = (int)(scene->image_width / scene->aspect_ratio);
	scene->focal_length = DISTANCE_VIEWPORT;
	scene->h = tanf(ft_degrees_to_radians(scene-.camera.fov));
	scene->viewport_height = 2 * scene->h * scene->focal_length;
	scene->viewport_width = scene->viewport_height * (scene->aspect_ratio);
	// scene->u = ft_unit_vector(ft_cross())
	return ;
}
