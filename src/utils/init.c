/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2023/10/05 00:11:28 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_initialize_scene(t_scene *scene)
{
	printf("**ENTRO EN FT_INITIALIZE SCENE**\n");
	scene->camera = malloc(sizeof(t_camera *));
	scene->ambient = malloc(sizeof(t_ambient *));
	scene->light = malloc(sizeof(t_light *));
	//scene->elements = NULL;
	if (!scene->camera || !scene->ambient || !scene->light)
	{
		perror("error: scene: fail to assign memory\n");
		return (1);
	}
	if (ft_init_camera(scene) == 1)
		return (1);
	if (ft_init_ambient(scene) == 1)
		return (1);
	printf("**SALGO DE FT_INITIALIZE SCENE**\n");
	return (0);
}

int	ft_init_camera(t_scene *scene)
{
	printf("ENTRO EN FT_INIT_CAMERA\n");

		scene->camera->defined = 0;
		scene->camera->pov = malloc(sizeof(t_coordinates *));
		scene->camera->orientation = malloc(sizeof(t_coordinates *));
		if (!scene->camera)
				return (1);
		printf("SALGO DE FT_INIT_CAMERA\n");
		return (0);


}


int	ft_init_ambient(t_scene *scene)
{
	printf("ENTRO EN FT_INIT_AMBIENT\n");

		scene->ambient->defined = 0;
		scene->ambient->color = malloc(sizeof(t_color *));
		if (!scene->ambient->color)
				return (1);
		printf("SALGO DE FT_INIT_AMBIENT\n");
		return (0);

}