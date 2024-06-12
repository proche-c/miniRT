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
/*
//converts normalized color to rgb
int	color2rgb(t_color c)
{
	int	color;

	color = (int)(c.r * 255) << 16;
	color += (int)(c.g * 255) << 8;
	color += (int)(c.b * 255);
	return (color);
}*/

int color2rgb(t_color color) 
{
    return (color.r << 16) | (color.g << 8) | color.b;
}