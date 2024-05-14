/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2023/10/05 00:11:28 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	 ft_get_ambient(char **params, t_scene *scene)
{
	printf("ENTRO EN FT_GET_AMBIENT\n");
	if (scene->ambient.defined == 0)
	{
		scene->ambient.defined = 1;
		if (ft_data_ambient(params, scene) == 1)
		{
			perror("error: ambient: wrong parameters\n");
			return (1);
		}
		ft_print_camera(scene);
		ft_print_ambient(scene);
		ft_print_light(scene);
		printf("SALGO DE FT_GET_AMBIENT\n");
		return (0);
	}
	else
	{
		perror("error: ambient: ambient already defined\n");
		return (1);
	}
}



int	ft_data_ambient(char **params, t_scene *scene)
{
	printf("ENTRO EN FT_DATA_AMBIENT\n");
	if (ft_count_params(params) != 3)
	{
		printf("n_params in ambient: %d\n", ft_count_params(params));
		printf("SALGO DE FT_DATA_AMBIENT EN 1\n");
		return (1);
	}
	if (ft_get_ratio(params, scene) == 1)
	{
		printf("SALGO DE FT_DATA_AMBIENT EN 2\n");
		return (1);
	}
	if (ft_get_color(params, scene) == 1)
	{
		printf("SALGO DE FT_DATA_AMBIENT EN 3\n");
		return (1);
	}
	printf("SALGO DE FT_DATA_AMBIENT EN 4\n");
	return (0);
}

int	ft_get_ratio(char **params, t_scene *scene)
{
	printf("ENTRO EN FT_GET_RATIO\n");
	
	if (ft_is_float(params[1]) == 1 && ft_atof(params[1]) >= 0
		&& ft_atof(params[1]) <= 1)
	{
		scene->ambient.ratio = ft_atof(params[1]);
		printf("SALGO DE FT_GET_RATIO EN 1\n");
		return (0);
	}
	printf("SALGO DE FT_GET_RATIO EN 2\n");
	return (1);
}

int	ft_get_color(char **params, t_scene *scene)
{
	char **col;

	col = ft_split(params[2], ',');
	if (ft_is_color(col) == 1)
	{
		scene->ambient.color.r = ft_atoi(col[0]);
		scene->ambient.color.g = ft_atoi(col[1]);
		scene->ambient.color.b = ft_atoi(col[2]);
		ft_free_params(col);
		return (0);
	}
	ft_free_params(col);
	return (1);
}

int	ft_is_color(char **col)
{
	int	i;
	if (ft_count_params(col) != 3)
		return (0);
	i = 0;
	while (i < 3)
	{
		if (ft_is_positive(col[i]) == 0 || ft_atoi(col[i]) > 255)
			return (0);
		i++;
	}
	return (1);
}