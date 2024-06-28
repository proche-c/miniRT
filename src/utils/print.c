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

void	print_in_out(char *str)
{
	if (DEBUG == 1)
		printf("%s", str);
}

void	ft_print_camera(t_scene *scene)
{
	printf("\n***CAMERA***\n");
	printf("scene->camera->defined: %d\n", scene->camera.defined);
	printf("scene->camera->pov[0]: %f\n", scene->camera.pov.x);
	printf("scene->camera->pov[1]: %f\n", scene->camera.pov.y);
	printf("scene->camera->pov[2]: %f\n", scene->camera.pov.z);
	printf("scene->camera->orientation[0]: %f\n", scene->camera.orientation.x);
	printf("scene->camera->orientation[1]: %f\n", scene->camera.orientation.y);
	printf("scene->camera->orientation[2]: %f\n", scene->camera.orientation.z);
	printf("scene->camera->fov: %d\n", scene->camera.fov);
}

void	ft_print_ambient(t_scene *scene)
{
	printf("\n***AMBIENT***\n");
	printf("scene->ambient->defined: %d\n", scene->ambient.defined);
	printf("scene->ambient->ratio: %f\n", scene->ambient.ratio);
	printf("scene->ambient_color[0]: %d\n", scene->ambient.color.r);
	printf("scene->ambient_color[1]: %d\n", scene->ambient.color.g);
	printf("scene->ambient_color[2]: %d\n", scene->ambient.color.b);
}

void	ft_print_light(t_scene *scene)
{
	printf("\n***LIGHT***\n");
	printf("scene->light->defined: %d\n", scene->light.defined);
	printf("sscene->light.position.x: %f\n", scene->light.position.x);
	printf("scene->light.position.y: %f\n", scene->light.position.y);
	printf("scene->light.position.z: %f\n", scene->light.position.z);
	printf("scene->light->ratio: %f\n", scene->light.ratio);
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
