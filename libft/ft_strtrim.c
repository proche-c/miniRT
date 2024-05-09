/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/17 19:04:05 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str);

static int	ft_find_char(char const *set, char c)
{
	size_t	j;

	j = 0;
	while (set[j] != '\0')
	{
		if (set[j] == c)
			return (1);
		j++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, const char *set)
{
	size_t	i;
	size_t	lenth;
	char	*result;
	size_t	l;

	if (!s1)
		return (NULL);
	i = 0;
	while (s1[i] != '\0' && ft_find_char(set, s1[i]) == 1)
		i++;
	lenth = ft_strlen(s1);
	while (lenth - 1 >= i && lenth - 1 >= 0
		&& ft_find_char(set, s1[lenth - 1]) == 1)
		lenth--;
	result = malloc(lenth - i + 1);
	if (!result)
		return (NULL);
	l = 0;
	while (i < lenth)
		result[l++] = s1[i++];
	result[l] = '\0';
	return (result);
}
