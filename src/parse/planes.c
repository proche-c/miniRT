/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   planes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2023/10/05 00:11:28 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_get_plane(t_element *new_element, char **params)
{
	new_element->next = NULL;
	if (ft_count_params(params) != 4)
	{
		return (1);
	}
	new_element->identifier = ft_strdup(params[0]);
	if (ft_get_e_position(new_element, params[1]) == 1)
	{
		free(new_element->identifier);
		return (1);
	}
	if (ft_get_e_color(new_element, params[3]) == 1)
	{
		free(new_element->identifier);
		return (1);
	}
	if (ft_get_e_n_vector(new_element, params[2]) == 1)
	{
		free(new_element->identifier);
		return (1);
	}
	return (0);
}

int	ft_get_e_n_vector(t_element *new_element, char *param)
{
	char		**co;
	t_vector	vector;

	co = ft_split(param, ',');
	if (ft_is_vector(co) == 1)
	{
		vector.x = ft_atof(co[0]);
		vector.y = ft_atof(co[1]);
		vector.z = ft_atof(co[2]);
		new_element->n_vector = ft_normalize_params(vector);
		ft_free_params(co);
		return (0);
	}
	ft_free_params(co);
	return (1);
}
