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
	(void)params;
	if (scene->ambient != NULL)
	{
		perror("error: ambient: ambient already defined\n");
		return (1);
	}
	else
	{
		if (ft_init_ambient(scene) == 1)
		{
			perror("error: ambient: fail to asign memory\n");
			return (1);
		}
	}
	return (0);
}

int	ft_init_ambient(t_scene *scene)
{
	scene->ambient = malloc(sizeof(t_ambient *));
	if (!scene->ambient)
		return (1);
	printf("pointer scene->ambient: %p\n", scene->ambient); 
	return (0);
}