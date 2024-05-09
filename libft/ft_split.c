/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/20 11:42:04 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	num_words;

	i = 0;
	num_words = 0;
	if (s[0] != c)
	{
		num_words = 1;
		i++;
	}
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i - 1] == c)
			num_words++;
		i++;
	}
	return (num_words);
}

static size_t	ft_find_size(char const *s, char c, size_t i)
{
	size_t	lenth;

	lenth = 0;
	while (s[i] != c && s[i] != '\0')
	{
		lenth++;
		i++;
	}
	return (lenth);
}

static char	**ft_assign_str(char const *s, char **res, char c, size_t words)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	while (s[i] != '\0' && j < words)
	{
		k = 0;
		while (s[i] == c)
			i++;
		res[j] = (char *)malloc(sizeof(char) * ft_find_size(s, c, i) + 1);
		if (!res[j])
			return (NULL);
		while (s[i] != c && s[i] != '\0')
			res[j][k++] = s[i++];
		res[j][k] = '\0';
		j++;
	}
	res[j] = 0;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	size_t	num_words;
	char	**result;

	if (!s)
		return (NULL);
	num_words = ft_count_words(s, c);
	result = malloc(sizeof(char *) * (num_words + 1));
	if (!result)
		return (NULL);
	result = ft_assign_str(s, result, c, num_words);
	return (result);
}
