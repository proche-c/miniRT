
#include "minirt.h"

//add light to color   (color = obj color, light = light color, p2 = light ratio)
t_color add_light(t_color color, t_color light, float ratio)
{
    t_color c;

    // Clamping p2 to be between 0 and 1
    if (ratio > 1)
        ratio = 1;
    if (ratio < 0)
        ratio = 0;

    // Calculate the final color components considering the light color and intensity ratio
    c.r = color.r * (1 - ratio) + light.r * ratio;
    c.g = color.g * (1 - ratio) + light.g * ratio;
    c.b = color.b * (1 - ratio) + light.b * ratio;

    // Clamping the final color values to be within 0 and 255
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

    return c;
}

//mix two colors (c1 = first color, p1 = ratio of first color, c2 = second color, p2 = ratio of second color)
t_color	mix_color(t_color c1, float p1, t_color c2, float p2)
{
	t_color	dst; //destination color

	dst.r = c1.r * p1 + c2.r * p2;
	dst.g = c1.g * p1 + c2.g * p2;
	dst.b = c1.b * p1 + c2.b * p2;
	return (dst);
}

