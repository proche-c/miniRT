# include "../include/minirt.h"


int	handle_keydown(int key, t_scene *scene)
{
	if (key == ESC_KEY)
    {

        printf("ESC KEY PRESSED\n"); //
    	exit_win(scene);
    }
    scene->event.key[key] = 1;
	return (0);
}

int	handle_keyup(int key, t_scene *scene)
{
	scene->event.key[key] = 0;
	return (0);
}