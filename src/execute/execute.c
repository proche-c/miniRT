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

int	ft_execute(t_scene *scene)
{
	int	i = 0;
	int	j = 0;
	t_intersection	*inter;
	
	inter = malloc(sizeof(t_intersection));
	if (!inter)
		return (1);
	ft_init_window(scene);
	while (j < scene->image_side)
	{
		i = 0;
		while (i < scene->image_side)
		{
			ft_paint(scene, inter, i, j);
			i++;
		}
		j++;
	}
	ft_launch_window(scene);
	int start_x = (WIN_WIDTH - scene->image_side) / 2;
    int start_y = (WIN_HEIGHT - scene->image_side) / 2;
    mlx_put_image_to_window(scene->mlx_ptr, scene->window_ptr,
		scene->img.img_ptr, start_x, start_y);
	mlx_loop(scene->mlx_ptr);
	free(inter);
	return (0);
}

void	ft_init_window(t_scene *scene)
{
	ft_get_viewport(scene);
	mlx_initiator(scene);
	hook_init(scene);
	pixel_print(scene);	
}

void	ft_paint(t_scene *scene, t_intersection *inter, int i, int j)
{
	inter->state = 0;
	inter->cy_base = 0;
	ft_get_ray(scene, inter, j, i);
	ft_hit_something(scene, inter);
	if (inter->state == 1)
		write_pixel_object(scene, inter, j, i);
	else
		write_pixel_no_object(scene, j, i);	
}