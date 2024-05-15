/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2023/10/05 00:11:28 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	 ft_get_light(char **params, t_scene *scene)
{
	printf("IN FT_GET_LIGHT\n");
		// check if light is already defined
	if (scene->light.defined == 0)
	{
		scene->light.defined = 1;
		// if it's not defined, ft_data_light stores data in struc scene
		if (ft_data_light(params, scene) == 1)
		{
			perror("error: light: wrong parameters\n");
			printf("OUT FT_GET_LIGHT IN 1\n");
			return (1);
		}
		// ft_print_camera, ft_print_ambient, ft_print_light are debug functions
		ft_print_camera(scene);
		ft_print_ambient(scene);
		ft_print_light(scene);
		printf("OUT FT_GET_LIGHT IN 2\n");
		return (0);
	}
	else
	{
		perror("error: light: camera already defined\n");
		return (1);
	}	
}

int	ft_data_light(char **params, t_scene *scene)
{
	printf("IN FT_DATA_LIGHT\n");
	// params in light must be 4 but we will just use 3 for the mandatory part:
	// identifier, ratio and position
	// missing get the ratio, working on it
	if (ft_count_params(params) != 4)
	{
		printf("OUT FT_DATA_LIGHT IN 1\n");
		return (1);
	}
	if (ft_get_position(params, scene) == 1)
	{
		printf("OUT FT_DATA_LIGHT EN 2\n");
		return (1);
	}
	return (0);
}

int	ft_get_position(char **params, t_scene *scene)
{
	printf("IN FT_GET_POSITION\n");
	char **co;
	
	co = ft_split(params[1], ',');
	if (ft_is_vector(co) == 1)
	{
		scene->light.position.x = ft_atof(co[0]);
		scene->light.position.y = ft_atof(co[1]);
		scene->light.position.z = ft_atof(co[2]);
		printf("OUT FT_GET_POSITION EN 1\n");
		ft_free_params(co);
		return (0);
	}
	
	ft_free_params(co);
	printf("OUT FT_GET_POSITION EN 3\n");
	return (1);
}
