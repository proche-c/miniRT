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

// WORK IN PROGRESS
int	 ft_get_plane(t_element *new_element, char **params)
{
	new_element->next = NULL;
	if (ft_count_params(params) != 4)
	{
		return (1);
	}
	new_element->identifier = ft_strdup(params[0]);
	if (ft_get_e_position(new_element, params[1]) == 1)
	{
		return (1);
	}
	if (ft_get_e_color(new_element, params[3]) == 1)
	{
		return (1);
	}
	if (ft_get_e_n_vector(new_element, params[2]) == 1)
	{
		return (1);
	}
	return (0);
}

int	ft_get_e_n_vector(t_element *new_element, char *param)
{
	printf("IN FT_GET_E_N_VECTOR, params[2]: %s  \n", param);
	char **co;

	co = ft_split(param, ',');
	// n_vector must be a normalized vector
	if (ft_is_vector(co) == 1 && ft_is_normalized(co) == 1)
	{
		// stores orientation in struct scene
		new_element->n_vector.x = ft_atof(co[0]);
		new_element->n_vector.y = ft_atof(co[1]);
		new_element->n_vector.z = ft_atof(co[2]);
		printf("OUT FT_GET_E_N_VECTOR IN 1\n");
		ft_free_params(co);
		return (0);
	}
	// if co is not a normalized vector, error
	ft_free_params(co);
	printf("OUT FT_GET_E_N_VECTOR IN 2\n");
	return (1);
}