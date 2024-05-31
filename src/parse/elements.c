/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2023/10/05 00:11:28 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// WORK IN PROGRESS
int	 ft_get_element(char **params, t_scene *scene)
{
	print_in_out("IN FT_GET_ELEMENT\n");
	if (scene->flag == 0)
	{
		scene->flag = 1;
		if (ft_data_first_element(params, scene) == 1)
		{
			print_in_out("OUT FT_GET_ELEMENT, DATA FIRST ELEMENT FAILED\n");
			return (1);
		}
	}
	else
	{
		if (ft_data_add_element(params, scene) == 1)
		{
			print_in_out("OUT FT_GET_ELEMENT, DATA ADD ELEMENT FAILED\n");
			return (1);
		}
	}
	//ft_print_elements(scene);
	print_in_out("OUT FT_GET_ELEMENT, OK\n");
	return (0);
}

int	ft_data_first_element(char **params, t_scene *scene)
{
	print_in_out("IN FT_DATA_FIRST_ELEMENT\n");
	t_element	*new_element;

	new_element = malloc(sizeof(t_element));
	if (!new_element)
	{
		perror("error: element: failed to assign memory\n");
		return (1);
	}
	if (ft_data_element(new_element, params) == 1)
	{
		print_in_out("OUT FT_DATA_FIRST_ELEMENT, DATA_ELEMENT FAILED\n");
		return (1);
	}
	scene->elements = new_element;
	return (0);
}

int	ft_data_add_element(char **params, t_scene *scene)
{
	print_in_out("IN FT_DATA_ADD_ELEMENT\n");
	t_element	*new_element;

	new_element = malloc(sizeof(t_element));
	if (!new_element)
	{
		perror("error: element: failed to assign memory\n");
		return (1);
	}
	if (ft_data_element(new_element, params) == 1)
	{
		print_in_out("OUT FT_DATA_ADD_ELEMENT, DATA_ELEMENT FAILED\n");
		return (1);
	}
	ft_add_element(&(scene->elements), new_element);
	return (0);
}

int	ft_data_element(t_element *new_element, char **params)
{
	int	result;

	result = 0;
	if (ft_strncmp(params[0], "sp", 3) == 0)
		result = ft_get_sphere(new_element, params);
	else if (ft_strncmp(params[0], "pl", 3) == 0)
		result = ft_get_plane(new_element, params);
	else if (ft_strncmp(params[0], "cy", 3) == 0)
		result = ft_get_cylinder(new_element, params);
	return (result);
}

int	ft_get_e_position(t_element *new_element, char *param)
{
	print_in_out("ENTRO EN FT_GET_E_POSITION\n");
	char **co;
	
	co = ft_split(param, ',');
	// position must be a vector
	if (ft_is_vector(co) == 1)
	{
		new_element->position.x = ft_atof(co[0]);
		new_element->position.y = ft_atof(co[1]);
		new_element->position.z = ft_atof(co[2]);
		print_in_out("OUT FT_GET_E_POSITION IN 1\n");
		ft_free_params(co);
		return (0);
	}
	// if position is not a vector, error:
	ft_free_params(co);
	print_in_out("OUT FT_GET_E_POSITION EN 2\n");
	return (1);
}

int	ft_get_e_color(t_element *new_element, char *param)
{
	char **col;

	col = ft_split(param, ',');
	// col must be a color
	if (ft_is_color(col) == 1)
	{
		new_element->color.r = ft_atoi(col[0]);
		new_element->color.g = ft_atoi(col[1]);
		new_element->color.b = ft_atoi(col[2]);
		ft_free_params(col);
		return (0);
	}
	ft_free_params(col);
	return (1);
}

void	ft_add_element(t_element **lst, t_element *new)
{
	print_in_out("IN FT_ADD_ELEMENT\n");
	t_element	*last;

	if (lst && new)
	{
		if (*lst)
		{
			last = ft_elelast(*lst);
			last->next = new;
		}
		else
			*lst = new;
	}
	print_in_out("OUT FT_ADD_ELEMENT\n");
}

t_element	*ft_elelast(t_element *lst)
{
	print_in_out("IN FT_ELELAST\n");
	t_element	*temp;

	temp = lst;
	if (lst)
	{
		while (temp->next)
			temp = temp->next;
		print_in_out("IN FT_ELELAST IN 1\n");
		return (temp);
	}
	print_in_out("IN FT_ELELAST IN 2\n");
	return (NULL);
}