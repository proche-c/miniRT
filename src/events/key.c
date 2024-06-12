
# include "../include/minirt.h"

int handle_no_event(t_scene *scene)
{
	(void)scene;
	return (0);
}

int handle_input(int keycode, t_scene *scene)
{
	if (keycode == ESC_KEY)
	{
		printf("ESC key pressed\n"); //
		mlx_destroy_window(scene->mlx_ptr, scene->window_ptr);
		//mlx_destroy_display(scene->mlx_ptr);
		ft_free_scene(scene);
		exit(0);
	}
	else if (keycode == R_KEY)
	{
		printf("R key pressed\n"); //
		color_screen(scene, 0xff0000);
	}
	else if (keycode == G_KEY)
	{
		printf("G key pressed\n"); //
		color_screen(scene, 0xff00);
	}
	else if (keycode == B_KEY)
	{
		printf("B key pressed\n"); //
		color_screen(scene, 0xff);
	}
	return (0);
}

int close_window(t_scene *scene) 
{
    mlx_destroy_window(scene->mlx_ptr, scene->window_ptr);
	ft_free_scene(scene);
    exit(0);
    return (0);
}


void	hook_init(t_scene *scene)
{
	mlx_key_hook(scene->window_ptr, handle_input, scene);
	mlx_loop_hook(scene->mlx_ptr, handle_no_event, scene);
	mlx_hook(scene->window_ptr, 17, 0, close_window, scene);


}
