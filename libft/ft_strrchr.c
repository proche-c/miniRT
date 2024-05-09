/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/19 10:56:34 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	lenth;

	lenth = 0;
	lenth = ft_strlen(s);
	if ((char)c == '\0' && s[lenth] == '\0')
		return ((char *)&s[lenth]);
	while (lenth > 0)
	{
		lenth--;
		if (s[lenth] == (char)c)
			return ((char *)&s[lenth]);
	}
	return (NULL);
}
