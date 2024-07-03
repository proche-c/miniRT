/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:32:58 by ageiser           #+#    #+#             */
/*   Updated: 2022/09/20 15:41:05 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

//new color structure in float
t_color	newcolor(float r, float g, float b)
{
	t_color	c;

	c.r = r;
	c.g = g;
	c.b = b;
	return (c);
}

//color modification, every color component is multiplied by p
t_color	*color_part(t_color *c, float p)
{
	c->r *= c->r * p;
	c->g *= c->g * p;
	c->b *= c->b * p;
	return (c);
}

//new color creation 
t_color	color_mul(t_color c, float p)
{
	c.r *= c.r * p;
	c.g *= c.g * p;
	c.b *= c.b * p;
	return (c);
}

//converts rgb to normalised color
t_color	rgb2color(int rgb)
{
	t_color	c;

	c.r = (float)((rgb >> 16) & 0xff) / 255;
	c.g = (float)((rgb >> 8) & 0xff) / 255;
	c.b = (float)(rgb & 0xff) / 255;
	return (c);
}

// (rgb >> 16): This shifts the bits of the rgb integer 
// 16 positions to the right.
// if rgb is 0xFF8844, shifting right by 16 bits results in 0x0000FF.
// & 0xff: This performs a bitwise AND operation with 0xff 
// (which is 11111111 in binary).
// It effectively extracts the lowest 8 bits of the result, 
// which is the red component.
// casted to float and divided by 255 to get the normalised value

int	color2rgb(t_color color)
{
	return ((color.r << 16) | (color.g << 8) | color.b);
}

// color.r << 16: Moves the red component to the highest 8 bits.
// color.g << 8: Moves the green component to the middle 8 bits.
// color.b: Keeps the blue component in the lowest 8 bits.
// The bitwise OR (|) combines these shifted values into a 
// single integer representing the RGB color.
