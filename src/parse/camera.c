/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2023/10/05 00:11:28 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_get_camera(char **params, t_scene *scene)
{
	print_in_out("IN FT_GET_CAMERA\n");
	if (scene->camera.defined == 0)
	{
		scene->camera.defined = 1;
		if (ft_data_camera(params, scene) == 1)
		{
			perror("error: camera: wrong parameters\n");
			print_in_out("OUT FT_GET_CAMERA IN 1\n");
			return (1);
		}
		print_in_out("OUT FT_GET_CAMERA IN 2\n");
		return (0);
	}
	else
	{
		perror("error: camera: camera already defined\n");
		return (1);
	}
}
	// ft_print_camera, _ambient, ft_print_light are debug functions
	// if camera is already defined, error
	// if it's not defined, ft_data_camera stores data in struc scene
	// check if camera is already defined

int	ft_data_camera(char **params, t_scene *scene)
{
	print_in_out("IN FT_DATA_CAMERA\n");
	if (ft_count_params(params) != 4)
	{
		print_in_out("OUT FT_DATA_CAMERA IN 1\n");
		return (1);
	}
	if (ft_get_fov(params, scene) == 1)
	{
		print_in_out("OUT FT_DATA_CAMERA IN 2\n");
		return (1);
	}
	if (ft_get_orientation(params, scene) == 1)
	{
		print_in_out("OUT FT_DATA_CAMERA IN 3\n");
		return (1);
	}
	if (ft_get_pov(params, scene) == 1)
	{
		print_in_out("OUT FT_DATA_CAMERA IN 4\n");
		return (1);
	}
	print_in_out("OUT FT_DATA_CAMERA IN 5\n");
	return (0);
}

// params in camera must be 4: identifier, pov, orientation and fov

int	ft_get_fov(char **params, t_scene *scene)
{
	print_in_out("IN FT_GET_FOV\n");
	if (ft_is_positive(params[3]) == 1 && ft_atoi(params[3]) > 0
		&& ft_atoi(params[3]) < 181)
	{
		scene->camera.fov = ft_atoi(params[3]);
		print_in_out("OUT FT_GET_FOV WITH FOV \n");
		return (0);
	}
	print_in_out("OUT FT_GET_FOV WITHOUT FOV\n");
	return (1);
}

	// fov is a positive int in the range 0-180 (0 not included, I think)

int	ft_get_orientation(char **params, t_scene *scene)
{
	char	**co;

	print_in_out("IN FT_GET_ORIENTATION\n");
	co = ft_split(params[2], ',');
	if (ft_is_vector(co) == 1 && ft_is_normalized(co) == 1)
	{
		scene->camera.orientation.x = ft_atof(co[0]);
		scene->camera.orientation.y = ft_atof(co[1]);
		scene->camera.orientation.z = ft_atof(co[2]);
		print_in_out("OUT FT_GET_ORIENTATION IN 1\n");
		ft_free_params(co);
		return (0);
	}
	ft_free_params(co);
	print_in_out("OUT FT_GET_ORIENTATION IN 2\n");
	return (1);
}
	// orientation must be a normalized vector
	// stores orientation in struct scene
	// if co is not a normalized vector, error

int	ft_is_vector(char **co)
{
	int	i;

	print_in_out("IN FT_IS_VECTOR\n");
	if (ft_count_params(co) != 3)
	{
		print_in_out("OUT FT_IS_VECTOR, PARAMS != 3\n");
		return (0);
	}
	i = 0;
	while (co[i])
	{
		if (ft_is_float(co[i]) == 0)
		{
			print_in_out("OUT FT_IS_VECTOR, NO FLOATS\n");
			return (0);
		}
		i++;
	}
	print_in_out("OUT FT_IS_VECTOR, THEY ARE FLOATS\n");
	return (1);
}
		// check if co is a vector
		// each parameter must be a float
		// co must have 3 parameter
