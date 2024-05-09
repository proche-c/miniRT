/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2023/10/05 00:11:28 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	 ft_get_light(char **params, t_scene *scene)
{
	(void)params;
	if (scene->light != NULL)
	{
		perror("error: light: light already defined\n");
		return (1);
	}
	else
	{
		if (ft_init_light(scene) == 1)
		{
			perror("error: light: fail to asign memory\n");
			return (1);
		}
	}
	return (0);
}

int	ft_init_light(t_scene *scene)
{
	scene->light = malloc(sizeof(t_light *));
	if (!scene->light)
		return (1);
	printf("pointer scene->light: %p\n", scene->light); 
	return (0);
}