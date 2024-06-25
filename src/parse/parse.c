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

#include "minirt.h"

int	ft_parse(t_scene *scene)
{
	char	**lines;
	int		i;

	lines = ft_split(scene->str_scene, '\n');
	i = 0;
	while (lines[i])
	{
		if (ft_get_parameter(lines[i], scene) == 1)
		{
			perror("error: parameter definition\n");
			ft_free_params(lines);
			return (1);
		}
		i++;
	}
	ft_free_params(lines);
	if (scene->camera.defined == 0 || scene->ambient.defined == 0
		|| scene->light.defined == 0 || scene->elements == NULL)
	{
		printf("error: scene definition: missing mandatory parameters\n");
		return (1);
	}
	return (0);
}

int	ft_get_parameter(char *line, t_scene *scene)
{
	char	**params;

	params = ft_split(line, ' ');
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
		result = ft_get_element(params, scene);
	else if (ft_strncmp(params[0], "sp", 3) == 0)
		result = ft_get_element(params, scene);
	else if (ft_strncmp(params[0], "cy", 3) == 0)
		result = ft_get_element(params, scene);
	return (result);
}

int	ft_is_vector(char **co)
{
	int	i;

	if (ft_count_params(co) != 3)
		return (0);
	i = 0;
	while (co[i])
	{
		if (ft_is_float(co[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_normalized(char **co)
{
	int		i;
	float	length;
	float	vec[3];

	vec[0] = ft_atof(co[0]);
	vec[1] = ft_atof(co[1]);
	vec[2] = ft_atof(co[2]);
	i = 0;
	length = 0;
	while (i < 3)
	{
		if (vec[i] > 1 || vec[i] < -1)
			return (0);
		length = length + vec[i] * vec[i];
		i++;
	}
	if (length != 1)
		return (0);
	return (1);
}

void	ft_normalize_params(t_vector vector)
{
	float	length;

	length = ft_get_vector_length(vector);
	vector.x = vector.x / length;
	vector.y = vector.y / length;
	vector.z = vector.z / length;
}