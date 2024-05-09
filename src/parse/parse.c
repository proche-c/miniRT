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
	printf("**ENTRO EN FT_PARSE**\n");
	char	**lines;
	int		i;

	ft_initialize_scene(scene);
	lines = ft_split(scene->str_scene, '\n');
	i = 0;
	while (lines[i])
	{
		if (ft_get_parameter(lines[i], scene) == 1)
		{
			perror("error: parameter definition\n");
			ft_free_scene(scene);
			printf("**1  SALGO DE FT_PARSE**\n");
			return (1);
		}
		i++;
	}
	printf("scene->camera->fov: %d\n", *(scene->camera->fov));
	ft_free_params(lines);
	printf("**2  SALGO DE FT_PARSE**\n");
	return (0);
}

void	ft_initialize_scene(t_scene *scene)
{
	//printf("**ENTRO EN FT_INITIALIZE SCENE**\n");
	scene->camera = NULL;
	scene->ambient = NULL;
	scene->light = NULL;
	scene->elements = NULL;
	// scene->camera->defined = 0;
	// scene->ambient->defined = 0;
	// scene->light->defined = 0;
	//printf("**SALGO DE FT_INITIALIZE SCENE**\n");
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
			//ft_free_params(params);
			return (1);
		}
	}
	else
	{
		perror("error: unknown identifier\n");
		return (1);
	}
	//ft_free_params(params);
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
		result = ft_get_planes(params, scene);
	else if (ft_strncmp(params[0], "sp", 3) == 0)
		result = ft_get_spheres(params, scene);
	else if (ft_strncmp(params[0], "cy", 3) == 0)
		result = ft_get_cylinders(params, scene);
	// if (scene->camera != NULL)
	// 	printf("3 scene->camera->fov: %d\n", *(scene->camera->fov));
	return (result);
}

int	ft_init_elements(t_scene *scene)
{
	scene->elements = malloc(sizeof(t_element *));
	if (!scene->elements)
		return (1);
	scene->elements->planes = NULL;
	scene->elements->spheres = NULL;
	scene->elements->cylinders = NULL;
	return (0);
}