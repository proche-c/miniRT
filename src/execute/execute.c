/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2023/10/05 00:11:28 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	initialize_scene(t_scene *scene)
{
	ft_get_viewport(scene);
	mlx_initiator(scene);
	hook_init(scene);
	pixel_print(scene);
}

void	process_pixels(t_scene *scene, t_intersection *inter)
{
	int	j;
	int	i;

	j = 0;
	while (j < scene->image_side)
	{
		i = 0;
		while (i < scene->image_side)
		{
			inter->state = 0;
			inter->is_shadow = 1;
			ft_get_ray(scene, inter, j, i);
			ft_hit_something(scene, inter);
			if (inter->state == 1)
			{
				write_pixel_object(scene, inter, j, i);
			}
			else
			{
				write_pixel_no_object(scene);
			}
			i++;
		}
		j++;
	}
}

void	display_image(t_scene *scene)
{
	int	start_x;
	int	start_y;

	start_x = (WIN_WIDTH - scene->image_side) / 2;
	start_y = (WIN_HEIGHT - scene->image_side) / 2;
	mlx_put_image_to_window(scene->mlx_ptr, scene->window_ptr,
		scene->img.img_ptr, start_x, start_y);
	printf("minirt: Image to Window.\n");
	mlx_loop(scene->mlx_ptr);
}

int	ft_execute(t_scene *scene)
{
	t_intersection	*inter;

	inter = malloc(sizeof(t_intersection));
	initialize_scene(scene);
	process_pixels(scene, inter);
	display_image(scene);
	free(inter);
	return (0);
}
