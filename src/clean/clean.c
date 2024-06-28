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
	if (scene->elements != NULL)
		ft_free_all_elements(scene);
	free(scene);
	printf("**SALGO DE FT_FREE_SCENE**\n");
}

void	ft_free_all_elements(t_scene *scene)
{
	t_element	*element;
	t_element	*to_delete;

	element = scene->elements;
	while (element != NULL)
	{
		to_delete = element;
		element = element->next;
		if (to_delete->identifier != NULL)
			free(to_delete->identifier);
		free(to_delete);
	}
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
