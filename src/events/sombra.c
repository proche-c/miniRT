/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:50:06 by ageiser           #+#    #+#             */
/*   Updated: 2022/10/07 11:59:40 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	ft_get_inter_data_shadow_0_v1(t_intersection *inter,
t_intersection *tmp_inter, t_element *c_element)
{
	if (inter->state == 0 || tmp_inter->distance < inter->distance)
	{
		inter->position.x = tmp_inter->position.x;
		inter->position.y = tmp_inter->position.y;
		inter->position.z = tmp_inter->position.z;
		inter->element = c_element;
		inter->cy_base = 1;
		inter->state = 1;
		inter->distance = tmp_inter->distance;
	}
	else
	{
		ft_get_closest_point_cy(inter, tmp_inter->position, c_element);
	}
}

void	ft_get_inter_data_shadow_not_0_v1(t_intersection *inter,
t_intersection *tmp_inter, t_element *c_element)
{
	if (inter->state == 0)
	{
		inter->position.x = tmp_inter->position.x;
		inter->position.y = tmp_inter->position.y;
		inter->position.z = tmp_inter->position.z;
		inter->element = c_element;
		inter->cy_base = 1;
		inter->state = 1;
		inter->distance = tmp_inter->distance;
	}
	else
	{
		ft_get_closest_point_cy(inter, tmp_inter->position, c_element);
	}
}

void	ft_get_inter_data_1(t_intersection *inter,
t_intersection *tmp_inter, t_element *c_element)
{
	if (inter->is_shadow == 0)
	{
		ft_get_inter_data_shadow_0_v1(inter, tmp_inter, c_element);
	}
	else
	{
		ft_get_inter_data_shadow_not_0_v1(inter, tmp_inter, c_element);
	}
}

void	ft_get_inter_data_shadow_0(t_intersection *inter,
t_intersection *tmp_inter, t_element *c_element)
{
	if (inter->state == 0 || tmp_inter->distance < inter->distance)
	{
		inter->position.x = tmp_inter->position.x;
		inter->position.y = tmp_inter->position.y;
		inter->position.z = tmp_inter->position.z;
		inter->element = c_element;
		inter->state = 1;
		inter->distance = tmp_inter->distance;
	}
	else
	{
		ft_get_closest_point(inter, tmp_inter->position, c_element);
	}
}

void	ft_get_inter_data_shadow_not_0(t_intersection *inter,
t_intersection *tmp_inter, t_element *c_element)
{
	if (inter->state == 0)
	{
		inter->position.x = tmp_inter->position.x;
		inter->position.y = tmp_inter->position.y;
		inter->position.z = tmp_inter->position.z;
		inter->element = c_element;
		inter->state = 1;
		inter->distance = tmp_inter->distance;
	}
	else
	{
		ft_get_closest_point_cy(inter, tmp_inter->position, c_element);
	}
}
