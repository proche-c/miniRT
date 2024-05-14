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
	printf("ENTRO EN FT_INITIALIZE SCENE\n");

	scene->camera.defined = 0;
	scene->ambient.defined = 0;
	scene->light.defined = 0;
	// scene->ambient_color = malloc(sizeof(t_color *));
	// scene->light_color = malloc(sizeof(t_color *));
	scene->elements = NULL;
	// if (!scene->light_color)
	// {
	// 	perror("error: scene: fail to assign memory\n");
	// 	return (1);
	// }

	printf("SALGO DE FT_INITIALIZE SCENE\n");
	return (0);
}
