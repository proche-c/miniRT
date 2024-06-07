/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2023/10/05 00:11:28 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_count_params(char **params)
{
	int	n_params;

	n_params = 0;
	while (params[n_params])
		n_params++;
	//printf("n_params in camera: %d\n", n_params);
	return (n_params);
}

int	ft_is_float(char *str)
{
	// printf("ENTRO EN FT_IS_FLOAT con str: %s\n", str);
	char	**parts;
	//int		i;

	parts = ft_split(str, '.');
	// printf("ft_count_params(parts): %d\n", ft_count_params(parts));
	if (ft_count_params(parts) != 2 && ft_count_params(parts) != 1)
	{
		ft_free_params(parts);
		// printf("SALGO DE FT_IS_FLOAT, NO SON 1 O 2 PARTES\n");
		return (0);
	}
	//i = 0;
	if (ft_is_a_num(parts[0]) == 0)
	{
		ft_free_params(parts);
		// printf("SALGO DE FT_IS_FLOAT, 1ª PARTE NO ES NUMERO\n");
		return (0);
	}
	if (ft_count_params(parts) == 2)
	{
		if (ft_is_positive(parts[1]) == 0)
		{
			ft_free_params(parts);
			// printf("SALGO DE FT_IS_FLOAT, 2ª PARTE NO ES NUMERO\n");
			return (0);
		}
	}
	ft_free_params(parts);
	// printf("SALGO DE FT_IS_FLOAT, ES UN FLOAT\n");
	return (1);
}

int	ft_is_a_num(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0 && str[i] != '-') 
			return (0);
		i++;
	}
	return (1);	
}

int	ft_is_positive(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0) 
			return (0);
		i++;
	}
	return (1);	
}

float	ft_atof(char *str)
{
	// printf("\n***************ENTRO EN FT_ATOF con str: %s*******************\n", str);
	float	result;
	float	num1;
	float	num2;
	char	**parts;

	// printf("char: %s\n", str);
	if (ft_strchr(str, '.') == NULL)
	{
		result = (float)atoi(str);
		return (result);
	}
	parts = ft_split(str, '.');
	num1 = ft_atoi(parts[0]);
	if (parts[1] != NULL)
	{
		num2 = ft_atoi(parts[1]);
		while (num2 > 1)
			num2 = num2 / 10;
	}
	else
		num2 = 0;
	if (num1 >= 0)
		result = num1 + num2;
	else
		result = num1 - num2;
	ft_free_params(parts);
	// printf("********************SALGO DE FT_ATOF con result: %f\n\n", result);
	return (result);
}