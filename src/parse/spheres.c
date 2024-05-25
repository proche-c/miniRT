/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spheres.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2023/10/05 00:11:28 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

// WORK IN PROGRESS
int	 ft_get_sphere(t_element *new_element, char **params)
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
	if (ft_get_e_diameter(new_element, params[2]) == 1)
	{
		return (1);
	}
	return (0);
}

int	ft_get_e_diameter(t_element *new_element, char *param)
{
	printf("IN FT_GET_E_DIAMETER\n");
	// fov is a positive int in the range 0-180 (0 not included, I think)
	if ( ft_atof(param) > 0)
	{
		new_element->diameter = ft_atof(param);
		printf("OUT FT_GET_E_DIAMETER, DIAMETER %f\n", new_element->diameter);
		return (0);

	}
	printf("OUT FT_GET_E_DIAMETER WITHOUT DIAMETER\n");
	return (1);
}