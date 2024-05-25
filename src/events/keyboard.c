# include "../include/minirt.h"
# include "../include/window.h"

int	handle_keydown(int key, t_scene *scene)
{
	if (key == KV_ESCAPE)
		exit_win(scene);
	scene->event.key[key] = 1;
	return (0);
}

int	handle_keyup(int key, t_scene *scene)
{
	scene->event.key[key] = 0;
	return (0);
}