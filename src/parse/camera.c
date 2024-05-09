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
	printf("ENTRO EN FT_GET_CAMERA\n");
	if (ft_init_camera(scene) == 1)
	{
		perror("error: camera: fail to asign memory\n");
		return (1);
	}
	if (ft_data_camera(params, scene) == 1)
	{
		perror("error: camera: wrong parameters\n");
		return (1);
	}
	printf("SALGO DE FT_GET_CAMERA\n");
	return (0);
}

int	ft_init_camera(t_scene *scene)
{
	printf("ENTRO EN FT_INIT_CAMERA\n");
	if (scene->camera->defined == 0)
	{
		scene->camera->defined = 1;
		scene->camera->pov = malloc(sizeof(t_coordinates *));
		scene->camera->orientation = malloc(sizeof(t_coordinates *));
		scene->camera->orientation_position = -1;
		scene->camera->pov_defined = 0;
		scene->camera->orientation_defined = 0;
		scene->camera->fov_defined = 0;
		if (!scene->camera)
				return (1);
		printf("SALGO DE FT_INIT_CAMERA\n");
		return (0);
	}
	else
	{
		perror("error: camera: camera already defined\n");
		return (1);
	}
}

int	ft_data_camera(char **params, t_scene *scene)
{
	printf("ENTRO EN FT_DATA_CAMERA\n");
	if (ft_count_params(params) != 4)
	{
		printf("n_params in camera: %d\n", ft_count_params(params));
		printf("SALGO DE FT_DATA_CAMERA EN 1\n");
		return (1);
	}
	if (ft_get_fov(params, scene) == 1)
	{
		printf("SALGO DE FT_DATA_CAMERA EN 2\n");
		return (1);
	}
	if (ft_get_orientation(params, scene) == 1)
	{
		printf("SALGO DE FT_DATA_CAMERA EN 3\n");
		return (1);
	}
	if (ft_get_pov(params, scene) == 1)
	{
		printf("SALGO DE FT_DATA_CAMERA EN 4\n");
		return (1);
	}
	printf("''''''scene->camera->fov: %d\n", scene->camera->fov);
	printf("scene->camera->orientation->x: %5.2f\n", scene->camera->orientation->x);
	printf("scene->camera->orientation->y: %5.2f\n", scene->camera->orientation->y);
	printf("scene->camera->orientation->z: %5.2f\n", scene->camera->orientation->z);
	printf("scene->camera->pov->x: %5.2f\n", scene->camera->pov->x);
	printf("scene->camera->pov->y: %5.2f\n", scene->camera->pov->y);
	printf("scene->camera->pov->z: %5.2f\n", scene->camera->pov->z);
	printf("SALGO DE FT_DATA_CAMERA EN 5\n");
	return (0);
}

int	ft_get_fov(char **params, t_scene *scene)
{
	printf("ENTRO EN FT_GET_FOV\n");
	int	i;

	i = 1;
	while (params[i])
	{
		if (ft_strchr(params[i], ',') == NULL && ft_atoi(params[i]) > 0
			&& ft_atoi(params[i]) < 181 && scene->camera->fov_defined == 0)
		{
			scene->camera->fov = ft_atoi(params[i]);
			scene->camera->fov_defined = 1;
			printf("SALGO DE FT_GET_FOV CON FOV %d\n", scene->camera->fov);
			return (0);
		}
		i++;
	}
	printf("SALGO DE FT_GET_FOV SIN FOV\n");
	return (1);
}

int	ft_get_orientation(char **params, t_scene *scene)
{
	printf("ENTRO EN FT_GET_ORIENTATION\n");
	int	i;
	char **co;

	i = 1;
	while (params[i] && scene->camera->orientation_defined == 0)
	{
		printf("params[%d]: %s\n", i, params[i]);
	
		if (ft_strchr(params[i], ',') != NULL)
		{
			co = ft_split(params[i], ',');
			if (ft_is_coordinates(co) == 1 && ft_is_normalized(co) == 1)
			{
				printf("co[0]: %s\n", co[0]);
				if (ft_data_orientation(co, scene) == 1)
				{
					printf("SALGO DE FT_GET_ORIENTATION EN 1\n");
					ft_free_params(co);
					return (1);
				}
				else
				{
					scene->camera->orientation_position = i;
					printf("SALGO DE FT_GET_ORIENTATION EN 2\n");
					ft_free_params(co);
					return (0);
				}
			}
			ft_free_params(co);
		}
		i++;
	}
	printf("SALGO DE FT_GET_ORIENTATION EN 3\n");
	return (1);
}

int	ft_is_coordinates(char **co)
{
	printf("ENTRO EN FT_IS_COORDINATES\n");
	int	i;

	printf("en ft_is_coordinates co[0]: %s\n", co[0]);
	if (ft_count_params(co) != 3)
	{
		printf("n_params in co: %d\n", ft_count_params(co));
		printf("SALGO DE FT_IS_COORDINATES, PARAMS != 3\n");
		return (0);
	}
	i = 0;
	while (co[i])
	{
		if (ft_is_float(co[i]) == 0)
		{
			printf("SALGO DE FT_IS_COORDINATES, NO FLOATS\n");
			return (0);
		}
		i++;
	}
	printf("SALGO DE FT_IS_COORDINATES, THEY ARE FLOATS\n");
	return (1);
}

int	ft_is_normalized(char **co)
{
	printf("ENTRO EN FT_IS_NORMALIZED\n");
	int	i;

	i = 0;
	while (co[i])
	{
		if (ft_atof(co[i]) != 1 && ft_atof(co[i]) != 0)
		{
			printf("SALGO DE FT_IS_NORMALIZED, NO NORMALIZED\n");
			return (0);
		}
		i++;
	}
	printf("SALGO DE FT_IS_NORMALIZED, SON NORMALIZED\n");
	return (1);
}

int	ft_data_orientation(char **co, t_scene *scene)
{
	printf("ENTRO EN FT_DATA_ORIENTATION\n");
	scene->camera->orientation_defined = 1;
	scene->camera->orientation->x = ft_atof(co[0]);
	scene->camera->orientation->y = ft_atof(co[1]);
	scene->camera->orientation->z = ft_atof(co[2]);
	printf("SALGO DE FDATA_ORIENTATION\n");
	return (0);
}

int	ft_get_pov(char **params, t_scene *scene)
{
	printf("ENTRO EN FT_GET_POV\n");
	int	i;
	char **co;

	i = 1;
	while (params[i] && scene->camera->pov_defined == 0)
	{
		printf("params[%d]: %s\n", i, params[i]);
	
		if (ft_strchr(params[i], ',') != NULL && i != scene->camera->orientation_position)
		{
			co = ft_split(params[i], ',');
			if (ft_is_coordinates(co) == 1 && ft_is_normalized(co) == 0)
			{
				if (ft_data_pov(co, scene) == 1)
				{
					printf("SALGO DE FT_GET_POV EN 1\n");
					ft_free_params(co);
					return (1);
				}
				else
				{
					printf("SALGO DE FT_GET_POV EN 2\n");
					ft_free_params(co);
					return (0);
				}
			}
			ft_free_params(co);
		}
		i++;
	}
	printf("SALGO DE FT_GET_POV EN 3\n");
	return (1);
}

int	ft_data_pov(char **co, t_scene *scene)
{
	printf("ENTRO EN FT_DATA_POV\n");
	scene->camera->pov_defined = 1;
	scene->camera->pov->x = ft_atof(co[0]);
	scene->camera->pov->y = ft_atof(co[1]);
	scene->camera->pov->z = ft_atof(co[2]);
	printf("SALGO DE FDATA_POV\n");
	return (0);
}