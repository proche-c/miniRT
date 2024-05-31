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
int	 ft_get_cylinder(t_element *new_element, char **params)
{
	new_element->next = NULL;
	if (ft_count_params(params) != 6)
	{
		return (1);
	}
	new_element->identifier = ft_strdup(params[0]);
	if (ft_get_e_position(new_element, params[1]) == 1)
	{
		return (1);
	}
	if (ft_get_e_color(new_element, params[5]) == 1)
	{
		return (1);
	}
	if (ft_get_e_diameter(new_element, params[3]) == 1)
	{
		return (1);
	}
	if (ft_get_e_n_vector(new_element, params[2]) == 1)
	{
		return (1);
	}
	if (ft_get_e_height(new_element, params[4]) == 1)
	{
		return (1);
	}
	return (0);
}

int	ft_get_e_height(t_element *new_element, char *param)
{
	print_in_out("IN FT_GET_E_HEIGHT\n");
	// height is a positive float
	if ( ft_atof(param) > 0)
	{
		new_element->height = ft_atof(param);
		print_in_out("OUT FT_GET_E_HEIGHT WITH HEIGHT \n");
		return (0);

	}
	print_in_out("OUT FT_GET_E_HEIGHT WITHOUT HEIGHT\n");
	return (1);
}