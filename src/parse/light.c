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
	printf("ENTRO EN FT_GET_LIGHT\n");
	if (scene->light_defined == 0)
	{
		scene->light_defined = 1;
		if (ft_data_light(params, scene) == 1)
		{
			perror("error: light: wrong parameters\n");
			return (1);
		}
				ft_print_camera(scene);
		ft_print_ambient(scene);
		ft_print_light(scene);
		printf("SALGO DE FT_GET_LIGHT\n");
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
	printf("ENTRO EN FT_DATA_LIGHT\n");
	if (ft_count_params(params) != 4)
	{
		printf("SALGO DE FT_DATA_LIGHT EN 1\n");
		return (1);
	}
	if (ft_get_position(params, scene) == 1)
	{
		printf("SALGO DE FT_DATA_LIGHT EN 2\n");
		return (1);
	}
	return (0);
}

int	ft_get_position(char **params, t_scene *scene)
{
	printf("ENTRO EN FT_GET_POSITION\n");
	char **co;
	

		co = ft_split(params[1], ',');
		if (ft_is_coordinates(co) == 1)
		{
			if (ft_data_position(co, scene) == 1)
			{
				printf("SALGO DE FT_GET_POSITION EN 1\n");
				ft_free_params(co);
				return (1);
			}
			else
			{
				printf("SALGO DE FT_GET_POSITION EN 2\n");
				ft_free_params(co);
				return (0);
			}
		}
	
	ft_free_params(co);
	printf("SALGO DE FT_GET_POSITION EN 3\n");
	return (1);
}

int	ft_data_position(char **co, t_scene *scene)
{
	printf("ENTRO EN FT_DATA_POSITION\n");
	scene->light_position[0] = ft_atof(co[0]);
	scene->light_position[1] = ft_atof(co[1]);
	scene->light_position[2] = ft_atof(co[2]);
	printf("SALGO DE FDATA_POSITION\n");
	return (0);
}