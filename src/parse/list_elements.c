/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2023/10/05 00:11:28 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_add_element(t_element **lst, t_element *new)
{
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
}

t_element	*ft_elelast(t_element *lst)
{
	t_element	*temp;

	temp = lst;
	if (lst)
	{
		while (temp->next)
			temp = temp->next;
		return (temp);
	}
	return (NULL);
}
