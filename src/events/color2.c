
#include "minirt.h"

//add light to color   (color = obj color, light = light color, p2 = light ratio)
t_color	add_light(t_color color, t_color light, float p2)
{
    t_color c;

    if (p2 > 1)
        p2 = 1;
    if (p2 < 0)
        p2 = 0;
    c.r = color.r + light.r * p2;
    c.g = color.g + light.g * p2;
    c.b = color.b + light.b * p2;
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
/*
//used to calc the middle color of 9 colors, useful for antialiasing, blur, multiple light sources, etc
int	big_mix(t_color	c[9])
{
	t_color	r;
	int		i;

	i = 0;
	r = newcolor(0.0f, 0.0f, 0.0f);
	while (i < 9)
	{
		r.r += c[i].r;
		r.g += c[i].g;
		r.b += c[i].b;
		i++;
	}
	r.r /= 9;
	r.g /= 9;
	r.b /= 9;
	return (color2rgb(r));
}*/

//return the color of the point hit by the ray (only used for texture and pattern) 
/*
t_color	color_obj(t_obj *obj, t_hit *hit)
{
	float	uv[2];
	t_color	color;

	color = obj->color;
	if (obj->id == id_sphere && obj->has_texture)
	{
		uv_sphere_map(obj, hit->phit, uv);
		color = get_pixelcolor(&obj->texture, uv[0], uv[1]);
	}
	else if (obj->pattern_num > 0)
		color = pattern_color(obj, hit->phit);
	return (color);
}*/
