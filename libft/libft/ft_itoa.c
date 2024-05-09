/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/20 16:07:45 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_calculate_digits(int n)
{
	int	num_digits;

	num_digits = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		num_digits++;
		n = n / 10;
	}
	return (num_digits);
}

static char	*ft_get_string(char *result, int num_digits, int sign, int n)
{
	char	a;

	if (sign == -1)
	{
		result[num_digits + 1] = '\0';
		while (num_digits > 0)
		{
			result[0] = '-';
			a = n % 10 + 48;
			result[num_digits--] = a;
			n = n / 10;
		}
	}
	else
	{
		result[num_digits] = '\0';
		while (num_digits > 0)
		{
			a = n % 10 + 48;
			result[num_digits - 1] = a;
			n = n / 10;
			num_digits--;
		}
	}
	return (result);
}

static char	*ft_min_int(void)
{
	char	*result;

	result = malloc(sizeof(char) * 12);
	if (!result)
		return (NULL);
	result[0] = '-';
	result[1] = '2';
	result[2] = '1';
	result[3] = '4';
	result[4] = '7';
	result[5] = '4';
	result[6] = '8';
	result[7] = '3';
	result[8] = '6';
	result[9] = '4';
	result[10] = '8';
	result[11] = '\0';
	return (result);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		num_digits;
	int		sign;

	if (n == -2147483648)
	{
		result = ft_min_int();
		return (result);
	}
	sign = 1;
	if (n < 0)
	{
		n = -n;
		sign = -1;
	}
	num_digits = ft_calculate_digits(n);
	if (sign == -1)
		result = malloc(sizeof(char) * num_digits + 2);
	else
		result = malloc(sizeof(char) * num_digits + 1);
	if (!result)
		return (NULL);
	result = ft_get_string(result, num_digits, sign, n);
	return (result);
}
