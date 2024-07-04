/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                          :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2023/10/05 00:11:28 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_get_element(char **params, t_scene *scene)
{
	if (scene->flag == 0)
	{
		scene->flag = 1;
		if (ft_data_first_element(params, scene) == 1)
		{
			return (1);
		}
	}
	else
	{
		if (ft_data_add_element(params, scene) == 1)
		{
			return (1);
		}
	}
	return (0);
}

int	ft_data_first_element(char **params, t_scene *scene)
{
	t_element	*new_element;

	new_element = malloc(sizeof(t_element));
	if (!new_element)
	{
		perror("error: element: failed to assign memory\n");
		return (1);
	}
	if (ft_data_element(new_element, params) == 1)
	{
		return (1);
	}
	scene->elements = new_element;
	return (0);
}

int	ft_data_add_element(char **params, t_scene *scene)
{
	t_element	*new_element;

	new_element = malloc(sizeof(t_element));
	if (!new_element)
	{
		perror("error: element: failed to assign memory\n");
		return (1);
	}
	if (ft_data_element(new_element, params) == 1)
	{
		return (1);
	}
	ft_add_element(&(scene->elements), new_element);
	return (0);
}

int	ft_data_element(t_element *new_element, char **params)
{
	int	result;

	result = 0;
	if (ft_strncmp(params[0], "sp", 3) == 0)
		result = ft_get_sphere(new_element, params);
	else if (ft_strncmp(params[0], "pl", 3) == 0)
		result = ft_get_plane(new_element, params);
	else if (ft_strncmp(params[0], "cy", 3) == 0)
		result = ft_get_cylinder(new_element, params);
	if (result == 1)
	{
		free(new_element);
		return (1);
	}
	return (result);
}

int	ft_get_e_position(t_element *new_element, char *param)
{
	char	**co;

	co = ft_split(param, ',');
	if (ft_is_vector(co) == 1)
	{
		new_element->position.x = ft_atof(co[0]);
		new_element->position.y = ft_atof(co[1]);
		new_element->position.z = ft_atof(co[2]);
		ft_free_params(co);
		return (0);
	}
	ft_free_params(co);
	return (1);
}
