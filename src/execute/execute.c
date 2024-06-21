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
	int	i = 0;
	int	j = 0;
	// t_ray	ray;
	t_intersection	*inter;
	
	inter = malloc(sizeof(t_intersection));
	ft_get_viewport(scene);   //PAULA
	// ft_print_viewport(scene);
	 mlx_initiator(scene);
	 hook_init(scene);
	 pixel_print(scene);
	while (j < scene->image_side)
	{
		//printf("j: %d\n", j);
		//printf("i: %d\n", i);
		i = 0;
		while (i < scene->image_side)
		{
			//printf("i: %d\n", i);
			inter->state = 0;
			inter->cy_base = 0;
			ft_get_ray(scene, inter, j, i);	//PAULA
			// ft_print_ray(inter->ray);
			ft_hit_something(scene, inter);
			// if (inter->state == 1)
			// 	ft_print_intersection(inter);
			// else
			// 	printf("nothing\n");
			if (inter->state == 1)	//PAULA
			{
				//ft_pixel_put(&scene->img, i, j, );
				//printf("inter->element->color.r: %d\n", inter->element->color.r);

				//color_screen(scene, inter->element->color.r);
				write_pixel_object(scene, inter, j, i); //ALEX
				//printf("write_pixel_object\n");
			}
			else
			{
				write_pixel_no_object(scene, j, i); //ALEX
				//color_screen(scene, 0xff00);
				//printf("write_pixel_no_object\n");
			}
			
			i++;
		}
		j++;
	}
	//printf("scene->image_side: %d\n", scene->image_side);
	int start_x = (WIN_WIDTH - scene->image_side) / 2;
    int start_y = (WIN_HEIGHT - scene->image_side) / 2;
	//printf("start_x: %d, start_y: %d\n", start_x, start_y);
    
    mlx_put_image_to_window(scene->mlx_ptr, scene->window_ptr, scene->img.img_ptr, start_x, start_y);
	
	printf("img2win\n");
	mlx_loop(scene->mlx_ptr);
	free(inter);
	printf("OUT FT_EXECUTE\n");
	return (0);
}

