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

	co = ft_split(params[1], ',');
	if (ft_is_vector(co) == 1)
	{
		scene->camera.pov.x = ft_atof(co[0]);
		scene->camera.pov.y = ft_atof(co[1]);
		scene->camera.pov.z = ft_atof(co[2]);
		ft_free_params(co);
		return (0);
	}
	ft_free_params(co);
	return (1);
}

int	ft_is_normalized(char **co)
{
	int		i;
	float	length;
	float	vec[3];

	vec[0] = ft_atof(co[0]);
	vec[1] = ft_atof(co[1]);
	vec[2] = ft_atof(co[2]);
	i = 0;
	length = 0;
	while (i < 3)
	{
		if (vec[i] > 1 || vec[i] < -1)
			return (0);
		length = length + vec[i] * vec[i];
		i++;
	}
	if (length != 1)
		return (0);
	return (1);
}
