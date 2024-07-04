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
	if (scene->camera.defined == 0)
	{
		scene->camera.defined = 1;
		if (ft_data_camera(params, scene) == 1)
		{
			perror("error: camera: wrong parameters\n");
			return (1);
		}
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
	if (ft_count_params(params) != 4)
	{
		return (1);
	}
	if (ft_get_fov(params, scene) == 1)
	{
		return (1);
	}
	if (ft_get_orientation(params, scene) == 1)
	{
		return (1);
	}
	if (ft_get_pov(params, scene) == 1)
	{
		return (1);
	}
	return (0);
}

int	ft_get_fov(char **params, t_scene *scene)
{
	if (ft_is_positive(params[3]) == 1 && ft_atoi(params[3]) > 0
		&& ft_atoi(params[3]) < 181)
	{
		scene->camera.fov = ft_atoi(params[3]);
		return (0);
	}
	return (1);
}

int	ft_get_orientation(char **params, t_scene *scene)
{
	char	**co;

	co = ft_split(params[2], ',');
	if (ft_is_vector(co) == 1 && ft_is_normalized(co) == 1)
	{
		scene->camera.orientation.x = ft_atof(co[0]);
		scene->camera.orientation.y = ft_atof(co[1]);
		scene->camera.orientation.z = ft_atof(co[2]);
		ft_free_params(co);
		return (0);
	}
	ft_free_params(co);
	return (1);
}

int	ft_is_vector(char **co)
{
	int	i;

	if (ft_count_params(co) != 3)
	{
		return (0);
	}
	i = 0;
	while (co[i])
	{
		if (ft_is_float(co[i]) == 0)
		{
			return (0);
		}
		i++;
	}
	return (1);
}
