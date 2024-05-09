/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/20 17:45:06 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	size_t	lenth;
	size_t	i;

	lenth = ft_strlen(s);
	result = malloc(sizeof(char) * (lenth + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (lenth > i)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[lenth] = '\0';
	return (result);
}
