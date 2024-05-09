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
	if (ft_init_ambient(scene) == 1)
	{
		perror("error: ambient: fail to initialize ambient\n");
		return (1);
	}
	if (ft_data_ambient(params, scene) == 1)
	{
		perror("error: ambient: wrong parameters\n");
		return (1);
	}
	printf("SALGO DE FT_GET_AMBIENT\n");
	return (0);
}

int	ft_init_ambient(t_scene *scene)
{
	printf("ENTRO EN FT_INIT_AMBIENT\n");
	if (scene->ambient->defined == 0)
	{
		scene->ambient->defined = 1;
		scene->ambient->color = malloc(sizeof(t_color *));
		if (!scene->ambient->color)
				return (1);
		printf("SALGO DE FT_INIT_AMBIENT\n");
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
	// printf("''''''scene->ambient->fov: %d\n", scene->ambient->fov);
	// printf("scene->ambient->orientation->x: %5.2f\n", scene->ambient->orientation->x);
	// printf("scene->ambient->orientation->y: %5.2f\n", scene->ambient->orientation->y);
	// printf("scene->ambient->orientation->z: %5.2f\n", scene->ambient->orientation->z);
	// printf("scene->ambient->pov->x: %5.2f\n", scene->ambient->pov->x);
	// printf("scene->ambient->pov->y: %5.2f\n", scene->ambient->pov->y);
	// printf("scene->ambient->pov->z: %5.2f\n", scene->ambient->pov->z);
	printf("SALGO DE FT_DATA_AMBIENT EN 4\n");
	return (0);
}