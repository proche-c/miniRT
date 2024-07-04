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

int	ft_get_ambient(char **params, t_scene *scene)
{
	if (scene->ambient.defined == 0)
	{
		scene->ambient.defined = 1;
		if (ft_data_ambient(params, scene) == 1)
		{
			perror("error: ambient: wrong parameters\n");
			return (1);
		}
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
	if (ft_count_params(params) != 3)
	{
		return (1);
	}
	if (ft_get_ambient_ratio(params, scene) == 1)
	{
		return (1);
	}
	if (ft_get_color(params, scene) == 1)
	{
		return (1);
	}
	return (0);
}

int	ft_get_ambient_ratio(char **params, t_scene *scene)
{
	if (ft_is_float(params[1]) == 1 && ft_atof(params[1]) >= 0
		&& ft_atof(params[1]) <= 1)
	{
		scene->ambient.ratio = ft_atof(params[1]);
		return (0);
	}
	return (1);
}

int	ft_get_color(char **params, t_scene *scene)
{
	char	**col;

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
