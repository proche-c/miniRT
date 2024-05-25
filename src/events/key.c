
# include "../include/minirt.h"


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

void	hook_init(t_scene *scene)
{
	ft_memset(scene->event.key, 0, MAX_KEY);
	scene->event.mouse = 0;
	mlx_loop_hook(scene->mlx_ptr, handle_no_event, scene);
	mlx_hook(scene->window_ptr, ON_KEYDOWN, 1L << 0, handle_keydown, scene);
	mlx_hook(scene->window_ptr, ON_KEYUP, 1L << 1, handle_keyup, scene);
	mlx_hook(scene->window_ptr, ON_DESTROY, 0L, exit_win, scene);
	/*
    mlx_hook(scene->window_ptr, ON_MOUSEDOWN, 1L << 2, handle_mousedown, scene);
	mlx_hook(scene->window_ptr, ON_MOUSEUP, 1L << 3, handle_mouseup, scene);
	mlx_hook(scene->window_ptr, ON_MOUSEMOVE, 1L << 6, handle_mousemove, scene);
    */
}
