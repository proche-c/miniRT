/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2023/10/05 00:11:28 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

int	ft_parse(t_scene *scene)
{
	printf("IN FT_PARSE\n");
	char	**lines;
	int		i;

	// get the lines in scene->str
	lines = ft_split(scene->str_scene, '\n');
	i = 0;
	while (lines[i])
	{
		if (ft_get_parameter(lines[i], scene) == 1)
		{
			perror("error: parameter definition\n");
			ft_free_params(lines);
			printf("OUT FT_PARSE IN 1\n");
			return (1);
		}
		i++;
	}
	ft_free_params(lines);
	if (scene->camera.defined == 0 || scene->ambient.defined == 0
		|| scene->light.defined == 0 || scene->elements == NULL)
	{
		printf("error: scene definition: missing mandatory parameters\n");
		printf("OUT FT_PARSE IN 2\n");
		return (1);
	}
	printf("OUT FT_PARSE IN 3\n");
	return (0);
}

int	ft_get_parameter(char *line, t_scene *scene)
{
	char	**params;

	// get rid of spaces and get clean params
	params = ft_split(line, ' ');
	// evaluate identifier
	if (ft_strncmp(params[0], "C", 2) == 0 || ft_strncmp(params[0], "A", 2) == 0
		|| ft_strncmp(params[0], "L", 2) == 0
			|| ft_strncmp(params[0], "pl", 3) == 0
				|| ft_strncmp(params[0], "sp", 3) == 0
					|| ft_strncmp(params[0], "cy", 3) == 0)
	{
		if (ft_get_data(params, scene) == 1)
		{
			ft_free_params(params);
			return (1);
		}
	}
	else
	{
		perror("error: unknown identifier\n");
		ft_free_params(params);
		return (1);
	}
	ft_free_params(params);
	return (0);
}

// evaluates type of identifier and call function to get the data
int	ft_get_data(char **params, t_scene *scene)
{
	int	result;

	result = 0;
	if (ft_strncmp(params[0], "C", 2) == 0)
		result = ft_get_camera(params, scene);
	else if (ft_strncmp(params[0], "A", 2) == 0)
		result = ft_get_ambient(params, scene);
	else if (ft_strncmp(params[0], "L", 2) == 0)
		result = ft_get_light(params, scene);
	else if (ft_strncmp(params[0], "pl", 3) == 0)
	{
		// result = 0;
		result = ft_get_element(params, scene);
	}
	else if (ft_strncmp(params[0], "sp", 3) == 0)
		result = ft_get_element(params, scene);
	else if (ft_strncmp(params[0], "cy", 3) == 0)
	{
		// result = 0;
		result = ft_get_element(params, scene);
	}
	return (result);
}

// I'm not using this for the moment
int	ft_init_elements(t_scene *scene)
{
	(void)scene;
	return (0);
}