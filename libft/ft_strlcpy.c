/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/18 18:15:53 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	lenth;
	size_t	i;

	lenth = 0;
	i = 0;
	if (src != NULL || dest != NULL || size)
	{
		while (src[i] != '\0')
		{
			i++;
			lenth++;
		}
		i = 0;
		while ((i + 1) < size && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		if (size > 0)
			dest[i] = '\0';
	}
	return (lenth);
}
