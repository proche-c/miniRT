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

void	ft_get_inter_data_2(t_intersection *inter,
t_intersection *tmp_inter, t_element *c_element)
{
	if (inter->is_shadow == 0)
	{
		ft_get_inter_data_shadow_0(inter, tmp_inter, c_element);
	}
	else
	{
		ft_get_inter_data_shadow_not_0(inter, tmp_inter, c_element);
	}
}
