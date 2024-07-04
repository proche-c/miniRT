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

int	ft_get_light(char **params, t_scene *scene)
{
	if (scene->light.defined == 0)
	{
		scene->light.defined = 1;
		if (ft_data_light(params, scene) == 1)
		{
			perror("error: light: wrong parameters\n");
			return (1);
		}
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
	if (ft_count_params(params) != 4)
	{
		return (1);
	}
	if (ft_get_position(params, scene) == 1)
	{
		return (1);
	}
	if (ft_get_light_ratio(params, scene) == 1)
	{
		return (1);
	}
	return (0);
}

int	ft_get_position(char **params, t_scene *scene)
{
	char	**co;

	co = ft_split(params[1], ',');
	if (ft_is_vector(co) == 1)
	{
		scene->light.position.x = ft_atof(co[0]);
		scene->light.position.y = ft_atof(co[1]);
		scene->light.position.z = ft_atof(co[2]);
		ft_free_params(co);
		return (0);
	}
	ft_free_params(co);
	return (1);
}

int	ft_get_light_ratio(char **params, t_scene *scene)
{
	if (ft_is_float(params[2]) == 1 && ft_atof(params[2]) >= 0
		&& ft_atof(params[2]) <= 1)
	{
		scene->light.ratio = ft_atof(params[2]);
		return (0);
	}
	return (1);
}
