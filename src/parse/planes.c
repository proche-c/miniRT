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
		return (1);
	new_element->identifier = ft_strdup(params[0]);
	if (ft_get_e_position(new_element, params[1]) == 1)
		return (1);
	if (ft_get_e_color(new_element, params[3]) == 1)
		return (1);
	if (ft_get_e_n_vector(new_element, params[2]) == 1)
		return (1);
	return (0);
}

int	ft_get_e_n_vector(t_element *new_element, char *param)
{
	char	**co;

	co = ft_split(param, ',');
	if (ft_is_vector(co) == 1)
	{
		new_element->n_vector.x = ft_atof(co[0]);
		new_element->n_vector.y = ft_atof(co[1]);
		new_element->n_vector.z = ft_atof(co[2]);
		ft_normalize_params(new_element->n_vector);
		ft_free_params(co);
		return (0);
	}
	ft_free_params(co);
	return (1);
}

int	ft_get_e_position(t_element *new_element, char *param)
{
	char	**co;

	co = ft_split(param, ',');
	if (ft_is_vector(co) == 1)
	{
		new_element->position.x = ft_atof(co[0]);
		new_element->position.y = ft_atof(co[1]);
		new_element->position.z = ft_atof(co[2]);
		ft_free_params(co);
		return (0);
	}
	ft_free_params(co);
	return (1);
}

int	ft_get_e_color(t_element *new_element, char *param)
{
	char	**col;

	col = ft_split(param, ',');
	if (ft_is_color(col) == 1)
	{
		new_element->color.r = ft_atoi(col[0]);
		new_element->color.g = ft_atoi(col[1]);
		new_element->color.b = ft_atoi(col[2]);
		ft_free_params(col);
		return (0);
	}
	ft_free_params(col);
	return (1);
}
