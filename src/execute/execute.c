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
	ft_print_viewport(scene);
	mlx_initiator(scene);
	hook_init(scene);
	pixel_print(scene);
	while (j < scene->image_side)
	{
		i = 0;
		while (i < scene->image_side)
		{

			inter->state = 0;
			ft_get_ray(scene, inter, j, i);	//PAULA
			// ft_print_ray(inter->ray);
			ft_hit_something(scene, inter);
			// if (inter->state == 1)
			// 	printf("something\n");
			// 	// ft_print_intersection(inter);
			// else
			// 	printf("nothing\n");
			if (inter->state == 1)	//PAULA
			{
				write_pixel_object(scene, inter, j, i); //ALEX
			}
			else
				write_pixel_no_object(scene, j, i); //ALEX

			i = i + 250;
		}
		j = j + 250;
	}
	mlx_loop(scene->mlx_ptr);
	free(inter);
	printf("OUT FT_EXECUTE\n");
	return (0);
}

void	write_pixel_object(t_scene *scene, t_intersection *intersection, int j, int i)
{
	(void)scene;
	(void)intersection;
	(void)i;
	(void)j;
	return ;
}

void	write_pixel_no_object(t_scene *scene, int j, int i)
{
	(void)scene;
	(void)i;
	(void)j;
	return ;
}