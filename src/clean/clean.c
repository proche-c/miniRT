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
	//free(scene->ambient_color);
	free(scene->light_color);
	printf("**SALGO DE FT_FREE_SCENE**\n");
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
