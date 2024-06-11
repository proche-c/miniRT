/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2023/10/05 00:11:28 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_in_out(char *str)
{
	if (DEBUG == 1)
		printf("%s", str);
}

void	ft_print_camera(t_scene *scene)
{
	printf("\n***CAMERA***\n");
	printf("scene->camera->defined: %d\n", scene->camera.defined);
	printf("scene->camera->pov[0]: %f\n", scene->camera.pov.x);
	printf("scene->camera->pov[1]: %f\n", scene->camera.pov.y);
	printf("scene->camera->pov[2]: %f\n", scene->camera.pov.z);
	printf("scene->camera->orientation[0]: %f\n", scene->camera.orientation.x);
	printf("scene->camera->orientation[1]: %f\n", scene->camera.orientation.y);
	printf("scene->camera->orientation[2]: %f\n", scene->camera.orientation.z);
	printf("scene->camera->fov: %d\n", scene->camera.fov);
}

void	ft_print_ambient(t_scene *scene)
{
	printf("\n***AMBIENT***\n");
	printf("scene->ambient->defined: %d\n", scene->ambient.defined);
	printf("scene->ambient->ratio: %f\n", scene->ambient.ratio);
	printf("scene->ambient_color[0]: %d\n", scene->ambient.color.r);
	printf("scene->ambient_color[1]: %d\n", scene->ambient.color.g);
	printf("scene->ambient_color[2]: %d\n", scene->ambient.color.b);
}

void	ft_print_light(t_scene *scene)
{
	printf("\n***LIGHT***\n");
	printf("scene->light->defined: %d\n", scene->light.defined);
	printf("sscene->light.position.x: %f\n", scene->light.position.x);
	printf("scene->light.position.y: %f\n", scene->light.position.y);
	printf("scene->light.position.z: %f\n", scene->light.position.z);
	printf("scene->light->ratio: %f\n", scene->light.ratio);
}

void	ft_print_params(char **params)
{
	 int	i;

	 i = 0;
	 while (params[i])
	 {
		printf("params[%d]: %s\n", i, params[i]);
		i++;
	 }
}

void	ft_print_element(t_element *element)
{
		if (ft_strncmp(element->identifier, "sp", 3) == 0)
		{
			printf("\n***SPHERE***\n");
			printf("pointer: %p\n", element);
			printf("element->identifier: %s\n", element->identifier);
			printf("element->position.x: %f\n", element->position.x);
			printf("element->position.y: %f\n", element->position.y);
			printf("element->position.z: %f\n", element->position.z);
			printf("element->diameter: %f\n", element->diameter);
			printf("element->color.r: %d\n", element->color.r);
			printf("element->color.g: %d\n", element->color.g);
			printf("element->color.b: %d\n", element->color.b);
		}
		else if (ft_strncmp(element->identifier, "pl", 3) == 0)
		{
			printf("\n***PLANE***\n");
			printf("pointer: %p\n", element);
			printf("element->identifier: %s\n", element->identifier);
			printf("element->position.x: %f\n", element->position.x);
			printf("element->position.y: %f\n", element->position.y);
			printf("element->position.z: %f\n", element->position.z);
			printf("element->n_vector.x: %f\n", element->n_vector.x);
			printf("element->n_vector.y: %f\n", element->n_vector.y);
			printf("element->n_vector.z: %f\n", element->n_vector.z);
			printf("element->color.r: %d\n", element->color.r);
			printf("element->color.g: %d\n", element->color.g);
			printf("element->color.b: %d\n", element->color.b);	
		}
		else if (ft_strncmp(element->identifier, "cy", 3) == 0)
		{
			printf("\n***CYLINDER***\n");
			printf("pointer: %p\n", element);
			printf("element->identifier: %s\n", element->identifier);
			printf("element->position.x: %f\n", element->position.x);
			printf("element->position.y: %f\n", element->position.y);
			printf("element->position.z: %f\n", element->position.z);
			printf("element->n_vector.x: %f\n", element->n_vector.x);
			printf("element->n_vector.y: %f\n", element->n_vector.y);
			printf("element->n_vector.z: %f\n", element->n_vector.z);
			printf("element->diameter: %f\n", element->diameter);
			printf("element->height: %f\n", element->height);
			printf("element->color.r: %d\n", element->color.r);
			printf("element->color.g: %d\n", element->color.g);
			printf("element->color.b: %d\n", element->color.b);	
		}	
}

void	ft_print_elements(t_scene *scene)
{
	printf("\n\nIN FT_PRINT_ELEMENTS\n");
	t_element	*element;

	element = scene->elements;
	while (element)
	{
		printf("scene->flag: %d\n", scene->flag);
		printf("pointer scene->elements: %p\n", scene->elements);
		ft_print_element(element);
		// if (ft_strncmp(element->identifier, "sp", 3) == 0)
		// {
		// 	printf("\n***SPHERE***\n");
		// 	printf("scene->flag: %d\n", scene->flag);
		// 	printf("pointer scene->elements: %p\n", scene->elements);
		// 	printf("pointer: %p\n", element);
		// 	printf("element->identifier: %s\n", element->identifier);
		// 	printf("element->position.x: %f\n", element->position.x);
		// 	printf("element->position.y: %f\n", element->position.y);
		// 	printf("element->position.z: %f\n", element->position.z);
		// 	printf("element->diameter: %f\n", element->diameter);
		// 	printf("element->color.r: %d\n", element->color.r);
		// 	printf("element->color.g: %d\n", element->color.g);
		// 	printf("element->color.b: %d\n", element->color.b);
		// }
		// else if (ft_strncmp(element->identifier, "pl", 3) == 0)
		// {
		// 	printf("\n***PLANE***\n");
		// 	printf("pointer: %p\n", element);
		// 	printf("scene->flag: %d\n", scene->flag);
		// 	printf("pointer scene->elements: %p\n", scene->elements);
		// 	printf("element->identifier: %s\n", element->identifier);
		// 	printf("element->position.x: %f\n", element->position.x);
		// 	printf("element->position.y: %f\n", element->position.y);
		// 	printf("element->position.z: %f\n", element->position.z);
		// 	printf("element->n_vector.x: %f\n", element->n_vector.x);
		// 	printf("element->n_vector.y: %f\n", element->n_vector.y);
		// 	printf("element->n_vector.z: %f\n", element->n_vector.z);
		// 	printf("element->color.r: %d\n", element->color.r);
		// 	printf("element->color.g: %d\n", element->color.g);
		// 	printf("element->color.b: %d\n", element->color.b);	
		// }
		// else if (ft_strncmp(element->identifier, "cy", 3) == 0)
		// {
		// 	printf("\n***CYLINDER***\n");
		// 	printf("pointer: %p\n", element);
		// 	printf("scene->flag: %d\n", scene->flag);
		// 	printf("pointer scene->elements: %p\n", scene->elements);
		// 	printf("element->identifier: %s\n", element->identifier);
		// 	printf("element->position.x: %f\n", element->position.x);
		// 	printf("element->position.y: %f\n", element->position.y);
		// 	printf("element->position.z: %f\n", element->position.z);
		// 	printf("element->n_vector.x: %f\n", element->n_vector.x);
		// 	printf("element->n_vector.y: %f\n", element->n_vector.y);
		// 	printf("element->n_vector.z: %f\n", element->n_vector.z);
		// 	printf("element->diameter: %f\n", element->diameter);
		// 	printf("element->height: %f\n", element->height);
		// 	printf("element->color.r: %d\n", element->color.r);
		// 	printf("element->color.g: %d\n", element->color.g);
		// 	printf("element->color.b: %d\n", element->color.b);	
		// }
		element = element->next;
	}
	printf("OUT FT_PRINT_ELEMENTS\n\n");
}

void	ft_print_viewport(t_scene *scene)
{
	printf("\n***VIEWPORT***\n");
	printf("scene->image_side: %d\n", scene->image_side);
	printf("scene->focal_length: %f\n", scene->focal_length);
	printf("scene->h: %f\n", scene->h);
	printf("scene->viewport_side: %f\n", scene->viewport_side);
	printf("scene->u.x: %f\n", scene->u.x);
	printf("scene->u.y: %f\n", scene->u.y);
	printf("scene->u.z: %f\n", scene->u.z);
	printf("scene->v.x: %f\n", scene->v.x);
	printf("scene->v.y: %f\n", scene->v.y);
	printf("scene->v.z: %f\n", scene->v.z);
	printf("scene->view_u.x: %f\n", scene->view_u.x);
	printf("scene->view_u.y: %f\n", scene->view_u.y);
	printf("scene->view_u.z: %f\n", scene->view_u.z);
	printf("scene->view_v.x: %f\n", scene->view_v.x);
	printf("scene->view_v.y: %f\n", scene->view_v.y);
	printf("scene->view_v.z: %f\n", scene->view_v.z);
	printf("scene->delta_u.x: %f\n", scene->delta_u.x);
	printf("scene->delta_u.y: %f\n", scene->delta_u.y);
	printf("scene->delta_u.z: %f\n", scene->delta_u.z);
	printf("scene->delta_v.x: %f\n", scene->delta_v.x);
	printf("scene->delta_v.y: %f\n", scene->delta_v.y);
	printf("scene->delta_v.z: %f\n", scene->delta_v.z);
	printf("scene->pixel00.x: %f\n", scene->pixel00.x);
	printf("scene->pixel00.y: %f\n", scene->pixel00.y);
	printf("scene->pixel00.z: %f\n", scene->pixel00.z);
}

void	ft_print_ray(t_ray ray)
{
	if (DEBUGEXEC == 1)
	{
		printf("    ray origin\n");
		printf("ray.origin.x: %f\n", ray.origin.x);
		printf("ray.origin.y: %f\n", ray.origin.y);
		printf("ray.origin.z: %f\n", ray.origin.z);
		printf("    ray direction\n");
		printf("ray.direction.x: %f\n", ray.direction.x);
		printf("ray.direction.y: %f\n", ray.direction.y);
		printf("ray.direction.z: %f\n", ray.direction.z);
		printf("    ray pixel center\n");
		printf("ray.pixel_center.x: %f\n", ray.pixel_center.x);
		printf("ray.pixel_center.y: %f\n", ray.pixel_center.y);
		printf("ray.pixel_center.z: %f\n", ray.pixel_center.z);
	}
}

void	ft_print_intersection(t_intersection *inter)
{
	if (DEBUGEXEC == 1)
	{
		printf("inter->state: %d\n", inter->state);
		printf("    inter position\n");
		printf("inter->position.x: %f\n", inter->position.x);
		printf("inter->position.y: %f\n", inter->position.y);
		printf("inter->position.z: %f\n", inter->position.z);
		ft_print_ray(inter->ray);
		printf("    element\n");
		ft_print_element(inter->element);
	}
}