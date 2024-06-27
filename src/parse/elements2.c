/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                          :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2023/10/05 00:11:28 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

t_element	*ft_elelast(t_element *lst)
{
	t_element	*temp;

	print_in_out("IN FT_ELELAST\n");
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

void	ft_add_element(t_element **lst, t_element *new)
{
	t_element	*last;

	print_in_out("IN FT_ADD_ELEMENT\n");
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

int	ft_get_e_color(t_element *new_element, char *param)
{
	char	**col;

	col = ft_split(param, ',');
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

	// col must be a color