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

// TO DO ONCE PARSING IS DONE
int	ft_execute(t_scene *scene)
{
	int				i;
	int				j;
	int				start_x;
	int				start_y;
	t_intersection	*inter;

	j = 0;
	inter = malloc(sizeof(t_intersection));
	ft_get_viewport(scene);
	mlx_initiator(scene);
	hook_init(scene);
	pixel_print(scene);
	while (j < scene->image_side)
	{
		i = 0;
		while (i < scene->image_side)
		{
			inter->state = 0;
			ft_get_ray(scene, inter, j, i);
			ft_hit_something(scene, inter);
			if (inter->state == 1)
				write_pixel_object(scene, inter, j, i);
			else
				write_pixel_no_object(scene);
			i++;
		}
		j++;
	}
	start_x = (WIN_WIDTH - scene->image_side) / 2;
	start_y = (WIN_HEIGHT - scene->image_side) / 2;
	mlx_put_image_to_window(scene->mlx_ptr, scene->window_ptr, scene->img.img_ptr, start_x, start_y);
	mlx_loop(scene->mlx_ptr);
	return (0);
}
	//free(inter);
	//printf("OUT FT_EXECUTE\n");
	//printf("img2win\n");
	//color_screen(scene, 0xff00);
	//printf("write_pixel_no_object\n");
	// if (inter->state == 1)
	// 	ft_print_intersection(inter);
	// else
	// 	printf("nothing\n");
	//ft_print_ray(inter->ray);
	// ft_print_viewport(scene);
	// t_ray	ray;