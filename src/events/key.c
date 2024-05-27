
# include "../include/minirt.h"



int handle_input(int keycode, t_scene *scene)
{
	if (keycode == ESC_KEY)
	{
		printf("ESC key pressed\n"); //
		mlx_destroy_window(scene->mlx_ptr, scene->window_ptr);
		mlx_destroy_display(scene->mlx_ptr);
		ft_free_scene(scene);
		exit(0);
		
	}
	return (0);
}

void	hook_init(t_scene *scene)
{

	mlx_key_hook(scene->window_ptr, handle_input, scene);

}
