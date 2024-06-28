/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2023/10/05 00:11:28 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Fonction principale pour convertir une chaîne de caractères en float
float	ft_atof(char *str)
{
	float	result;
	float	num1;
	float	num2;
	char	**parts;

	if (ft_strchr(str, '.') == NULL)
	{
		result = (float)atoi(str);
		return (result);
	}
	parts = ft_split(str, '.');
	num1 = (float)ft_atoi(parts[0]);
	num2 = convert_decimal_part(parts[1]);
	if (num1 >= 0)
		result = num1 + num2;
	else
		result = num1 - num2;
	ft_free_params(parts);
	return (result);
}
	// printf("char: %s\n", str);
	// printf("********************SALGO DE FT_ATOF 
	//con result: %f\n\n", result);
	// printf("\n***************ENTRO EN FT_ATOF 
	//con str: %s*******************\n", str);