/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2023/10/05 00:11:28 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// WORK IN PROGRESS
int	 ft_get_element(char **params, t_scene *scene)
{
	(void)params;
	t_element *new_element = NULL;

	if (scene->flag == 0)
	{
		ft_create_element(new_element);
	}
	return (0);
}

void	ft_create_element(t_element *new_element)
{
	(void)new_element;
	return ;
}