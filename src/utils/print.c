/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2023/10/05 00:11:28 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_print_camera(t_scene *scene)
{
	printf("\n***CAMERA***\n");
	printf("scene->camera->defined: %d\n", scene->camera_defined);
	printf("scene->camera->pov[0]: %f\n", scene->camera_pov[0]);
	printf("scene->camera->pov[1]: %f\n", scene->camera_pov[1]);
	printf("scene->camera->pov[2]: %f\n", scene->camera_pov[2]);
	printf("scene->camera->orientation[0]: %f\n", scene->camera_orientation[0]);
	printf("scene->camera->orientation[1]: %f\n", scene->camera_orientation[1]);
	printf("scene->camera->orientation[2]: %f\n", scene->camera_orientation[2]);
	printf("scene->camera->fov: %d\n", scene->camera_fov);
}

void	ft_print_ambient(t_scene *scene)
{
	printf("\n***AMBIENT***\n");
	printf("scene->ambient->defined: %d\n", scene->ambient_defined);
	printf("scene->ambient->ratio: %f\n", scene->ambient_ratio);
	printf("scene->ambient_color[0]: %d\n", scene->ambient_color[0]);
	printf("scene->ambient_color[1]: %d\n", scene->ambient_color[1]);
	printf("scene->ambient_color[2]: %d\n", scene->ambient_color[2]);
}

void	ft_print_light(t_scene *scene)
{
	printf("\n***LIGHT***\n");
	printf("scene->light->defined: %d\n", scene->light_defined);
	// printf("scene->camera->pov[0]: %d\n", scene->camera->pov[0]);
	// printf("scene->camera->pov[1]: %d\n", scene->camera->pov[1]);
	// printf("scene->camera->pov[2]: %d\n", scene->camera->pov[2]);
	// printf("scene->camera->orientation[0]: %d\n", scene->camera->orientation[0]);
	// printf("scene->camera->orientation[1]: %d\n", scene->camera->orientation[1]);
	// printf("scene->camera->orientation[2]: %d\n", scene->camera->orientation[2]);
	// printf("scene->camera->fov: %d\n", scene->camera->fov);
}

void	ft_print_params(char **params)
{
	 int	i;

	 i = 0;
	 while (params[i])
	 {
		printf("params[%d]: %s\n", i, params[i]);
		i++;
	 }
}