/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinders.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2023/10/05 00:11:28 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


// WORK IN PROGRESS
int	 ft_get_cylinders(char **params, t_scene *scene)
{
	(void)params;
	if (scene->elements == NULL)
		ft_init_elements(scene);
	if (ft_init_cylinders(scene) == 1)
	{
		perror("error: cylinders: fail to asign memory\n");
		return (1);
	}
	return (0);
}

int	ft_init_cylinders(t_scene *scene)
{
	(void)scene;
	return (0);
}