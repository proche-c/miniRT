#include "minirt.h"

void	rt_init(t_rt *rt)
{
    rt->mlx = mlx_init();
    rt->width = (float) WIN_WIDTH;
    rt->height = (float) WIN_HEIGHT;
    rt->mlx_win = mlx_new_window(rt->mlx, rt->width, rt->height, "minirt");
    rt->img.img = mlx_new_image(rt->mlx, rt->width, rt->height);
    rt->img.addr = mlx_get_data_addr(rt->img.img, &rt->img.bits_per_pixel,
			&rt->img.line_length, &rt->img.endian);
    
    //hook_init(rt);
}
