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
	printf("IN FT_EXECUTE\n");
	scene->mlx_ptr = mlx_init();
	scene->window_ptr = mlx_new_window(scene->mlx_ptr, 300, 200, "miniRT");
	mlx_loop(scene->mlx_ptr);
	printf("OUT FT_EXECUTE\n");
	return (0);
}
