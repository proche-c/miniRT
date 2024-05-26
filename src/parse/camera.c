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

int	 ft_get_camera(char **params, t_scene *scene)
{
	printf("IN FT_GET_CAMERA\n");
	// check if camera is already defined
	if (scene->camera.defined == 0)
	{
		scene->camera.defined = 1;
		// if it's not defined, ft_data_camera stores data in struc scene
		if (ft_data_camera(params, scene) == 1)
		{
			perror("error: camera: wrong parameters\n");
			printf("OUT FT_GET_CAMERA IN 1\n");
			return (1);
		}
		// ft_print_camera, _ambient, ft_print_light are debug functions

		printf("OUT FT_GET_CAMERA IN 2\n");
		return (0);
	}
	else
	{
		// if camera is already defined, error
		perror("error: camera: camera already defined\n");
		return (1);
	}
}



int	ft_data_camera(char **params, t_scene *scene)
{
	printf("IN FT_DATA_CAMERA\n");
	// params in camera must be 4: identifier, pov, orientation and fov
	if (ft_count_params(params) != 4)
	{
		printf("OUT FT_DATA_CAMERA IN 1\n");
		return (1);
	}
	if (ft_get_fov(params, scene) == 1)
	{
		printf("OUT FT_DATA_CAMERA IN 2\n");
		return (1);
	}
	if (ft_get_orientation(params, scene) == 1)
	{
		printf("OUT FT_DATA_CAMERA IN 3\n");
		return (1);
	}
	if (ft_get_pov(params, scene) == 1)
	{
		printf("OUT FT_DATA_CAMERA IN 4\n");
		return (1);
	}
	printf("OUT FT_DATA_CAMERA IN 5\n");
	return (0);
}

int	ft_get_fov(char **params, t_scene *scene)
{
	printf("IN FT_GET_FOV\n");
	// fov is a positive int in the range 0-180 (0 not included, I think)
	if (ft_is_positive(params[3]) == 1 && ft_atoi(params[3]) > 0
		&& ft_atoi(params[3]) < 181)
	{
		scene->camera.fov = ft_atoi(params[3]);
		printf("OUTE FT_GET_FOV, FOV %d\n", scene->camera.fov);
		return (0);

	}
	printf("OUT FT_GET_FOV WITHOUT FOV\n");
	return (1);
}

int	ft_get_orientation(char **params, t_scene *scene)
{
	printf("IN FT_GET_ORIENTATION, params[2]: %s  \n", params[2]);
	char **co;

	co = ft_split(params[2], ',');
	// orientation must be a normalized vector
	if (ft_is_vector(co) == 1 && ft_is_normalized(co) == 1)
	{
		// stores orientation in struct scene
		scene->camera.orientation.x = ft_atof(co[0]);
		scene->camera.orientation.y = ft_atof(co[1]);
		scene->camera.orientation.z = ft_atof(co[2]);
		printf("OUT FT_GET_ORIENTATION IN 1\n");
		ft_free_params(co);
		return (0);
	}
	// if co is not a normalized vector, error
	ft_free_params(co);
	printf("OUT FT_GET_ORIENTATION IN 2\n");
	return (1);
}

int	ft_is_vector(char **co)
{
	// check if co is a vector
	printf("IN FT_IS_VECTOR\n");
	int	i;

	// co must have 3 parameters
	if (ft_count_params(co) != 3)
	{
		printf("OUT FT_IS_VECTOR, PARAMS != 3\n");
		return (0);
	}
	i = 0;
	while (co[i])
	{
		// each parameter must be a float
		if (ft_is_float(co[i]) == 0)
		{
			printf("OUT FT_IS_VECTOR, NO FLOATS\n");
			return (0);
		}
		i++;
	}
	printf("OUT FT_IS_VECTOR, THEY ARE FLOATS\n");
	return (1);
}

int	ft_is_normalized(char **co)
{
	// check if co is normalized
	printf("IN FT_IS_NORMALIZED\n");
	int	i;

	i = 0;
	while (co[i])
	{
		// each parameter must be 1 or 0
		if (ft_atof(co[i]) != 1 && ft_atof(co[i]) != 0)
		{
			printf("OUT FT_IS_NORMALIZED, NO NORMALIZED\n");
			return (0);
		}
		i++;
	}
	printf("OUT FT_IS_NORMALIZED, THEY ARE NORMALIZED\n");
	return (1);
}

int	ft_get_pov(char **params, t_scene *scene)
{
	printf("ENTRO EN FT_GET_POV\n");
	char **co;
	
	co = ft_split(params[1], ',');
	// pov must be a vector
	if (ft_is_vector(co) == 1)
	{
		scene->camera.pov.x = ft_atof(co[0]);
		scene->camera.pov.y = ft_atof(co[1]);
		scene->camera.pov.z = ft_atof(co[2]);
		printf("OUT FT_GET_POV IN 1\n");
		ft_free_params(co);
		return (0);
	}
	// if pov is not a vector, error:
	ft_free_params(co);
	printf("OUT FT_GET_POV EN 2\n");
	return (1);
}
