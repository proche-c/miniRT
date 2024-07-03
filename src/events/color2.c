/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:32:58 by ageiser           #+#    #+#             */
/*   Updated: 2022/09/20 15:41:05 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

t_color	add_light(t_color color, t_color light, float ratio)
{
	t_color	c;

	if (ratio > 1)
		ratio = 1;
	if (ratio < 0)
		ratio = 0;
	c.r = color.r * (1 - ratio) + light.r * ratio;
	c.g = color.g * (1 - ratio) + light.g * ratio;
	c.b = color.b * (1 - ratio) + light.b * ratio;
	if (c.r > 255)
		c.r = 255;
	if (c.g > 255)
		c.g = 255;
	if (c.b > 255)
		c.b = 255;
	if (c.r < 0)
		c.r = 0;
	if (c.g < 0)
		c.g = 0;
	if (c.b < 0)
		c.b = 0;
	return (c);
}

// color.r * (1 - ratio): This part calculates the contribution 
// of the original color's red component.
//     As ratio increases from 0 to 1, the weight of color.r 
// decreases from 1 to 0.
// light.r * ratio: This part calculates the contribution 
// of the light's red component.
//     As ratio increases from 0 to 1, the weight of light.r 
//increases from 0 to 1.

//mix two colors (c1 = first color, p1 = ratio of fc...)
t_color	mix_color(t_color c1, float p1, t_color c2, float p2)
{
	t_color	dst;

	dst.r = c1.r * p1 + c2.r * p2;
	dst.g = c1.g * p1 + c2.g * p2;
	dst.b = c1.b * p1 + c2.b * p2;
	return (dst);
}
