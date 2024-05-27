
# include "../include/minirt.h"
#include <X11/keysym.h>


int	exit_win(t_scene *scene)
{
	ft_free_scene(scene);
	exit(0);
	return (0);
}

int	handle_no_event(t_scene *scene)
{
	(void) scene;
	return (0);
}

int handle_input(int keycode, t_scene *scene)
{
	if (keycode == XK_Escape)
	{
		printf("ESC key pressed\n");
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
	//mlx_hook(scene->window_ptr, ON_KEYUP, 1L << 1, handle_keyup, scene);
	//mlx_hook(scene->window_ptr, ON_DESTROY, 0L, exit_win, scene);
	/*
    mlx_hook(scene->window_ptr, ON_MOUSEDOWN, 1L << 2, handle_mousedown, scene);
	mlx_hook(scene->window_ptr, ON_MOUSEUP, 1L << 3, handle_mouseup, scene);
	mlx_hook(scene->window_ptr, ON_MOUSEMOVE, 1L << 6, handle_mousemove, scene);
    */
}
