/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2023/10/05 00:11:28 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_get_pov(char **params, t_scene *scene)
{
	char	**co;

	print_in_out("ENTRO EN FT_GET_POV\n");
	co = ft_split(params[1], ',');
	if (ft_is_vector(co) == 1)
	{
		scene->camera.pov.x = ft_atof(co[0]);
		scene->camera.pov.y = ft_atof(co[1]);
		scene->camera.pov.z = ft_atof(co[2]);
		print_in_out("OUT FT_GET_POV IN 1\n");
		ft_free_params(co);
		return (0);
	}
	ft_free_params(co);
	print_in_out("OUT FT_GET_POV EN 2\n");
	return (1);
}
	// pov must be a vector
	// if pov is not a vector, error:

int	ft_is_normalized(char **co)
{
	int		i;
	float	length;
	float	vec[3];

	print_in_out("IN FT_IS_NORMALIZED\n");
	vec[0] = ft_atof(co[0]);
	vec[1] = ft_atof(co[1]);
	vec[2] = ft_atof(co[2]);
	i = 0;
	length = 0;
	while (i < 3)
	{
		if (vec[i] > 1 || vec[i] < -1)
		{
			print_in_out("OUT FT_IS_NORMALIZED, NO NORMALIZED\n");
			return (0);
		}
		length = length + vec[i] * vec[i];
		i++;
	}
	if (length != 1)
	{
		print_in_out("OUT FT_IS_NORMALIZED, NO NORMALIZED\n");
		return (0);
	}
	print_in_out("OUT FT_IS_NORMALIZED, THEY ARE NORMALIZED\n");
	return (1);
}
		// each parameter must be 1 or 0
		// check if co is normalized
