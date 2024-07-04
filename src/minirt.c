/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2023/10/05 00:11:28 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	t_scene	*scene;

	if (argc != 2)
	{
		ft_putstr_fd("error: wrong arguments\n", 1);
		return (1);
	}
	scene = malloc(sizeof(t_scene));
	if (!scene)
		return (1);
	ft_initialize_scene(scene);
	if (ft_check(argv[1], scene) != 0)
	{
		ft_free_scene(scene);
		return (1);
	}
	if (ft_parse(scene) != 0)
	{
		ft_free_scene(scene);
		return (1);
	}
	ft_execute(scene);
	ft_free_scene(scene);
	return (0);
}

// it store the struc if the params are right
// check extension, if file opens. 
//It so, it reads file and store it in scene->str
// init params in scene