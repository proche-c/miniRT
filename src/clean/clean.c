/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2023/10/05 00:11:28 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_free_scene(t_scene *scene)
{
	printf("**ENTRO EN FT_FREE_SCENE**\n");
	free(scene->str_scene);
	if (scene->camera != NULL)
		ft_free_camera(scene);
	if (scene->ambient != NULL)
		ft_free_ambient(scene);
	if (scene->light != NULL)
		ft_free_light(scene);
	if (scene->elements != NULL)
	{
		if (scene->elements->planes != NULL)
			ft_free_planes(scene);
		if (scene->elements->spheres != NULL)
			ft_free_spheres(scene);
		if (scene->elements->cylinders != NULL)
			ft_free_cylinders(scene);
		free(scene->elements);
	}
printf("**SALGO DE FT_FREE_SCENE**\n");
}

void	ft_free_camera(t_scene *scene)
{
	printf("**ENTRO EN FT_FREE_CAMERA**\n");
	if (scene->camera->orientation != NULL)
		free(scene->camera->orientation);
	if (scene->camera->pov != NULL)
		free(scene->camera->pov);
	free(scene->camera);
	printf("**SALGO DE FT_FREE_CAMERA**\n");
	return ;
}

void	ft_free_ambient(t_scene *scene)
{
	free(scene->ambient);
	return ;
}

void	ft_free_light(t_scene *scene)
{
	free(scene->light);
	return ;
}

void	ft_free_params(char **params)
{
	int	i;

	i = 0;
	while (params[i])
	{
		free(params[i]);
		i++;
	}
	free(params);
}
