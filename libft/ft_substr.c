/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/21 13:22:43 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t lenth)
{
	char	*result;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	if (lenth > ft_strlen(s))
		result = (char *)malloc(ft_strlen(s) + 1);
	else if (start > ft_strlen(s))
		result = (char *)malloc(1);
	else
		result = (char *)malloc(lenth + 1);
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < lenth)
			result[j++] = s[i];
		i++;
	}
	result[j] = '\0';
	return (result);
}
