/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2023/10/05 00:11:28 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_check(char *file_name, t_scene *scene)
{
	int	fd;

	if (ft_check_extension(file_name) == 1)
	{
		perror("error: invalid extension\n");
		return (1);
	}
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		perror("error: unable to open file\n");
		return (1);
	}
	if (ft_check_file(fd, scene) == 1)
		return (1);
	return (0);
}

int	ft_check_extension(char *file_name)
{
	int	len;

	len = ft_strlen(file_name);
	if (file_name[len - 1] == 't' && file_name[len - 2] == 'r'
		&& file_name[len - 3] == '.')
		return (0);
	return (1);
}

int	ft_check_file(int fd, t_scene *scene)
{
	ssize_t	file_size;
	char	buff[MAX_LEN];
	int		result;

	result = 1;
	file_size = read(fd, buff, MAX_LEN);
	if (file_size == -1)
		perror("error: unable to read the file\n");
	else if (file_size == 0)
		perror("error: empty file\n");
	else
	{
		buff[file_size] = '\0';
		scene->str_scene = ft_strdup(buff);
		result = 0;
	}
	close(fd);
	return (result);
}
//printf("len buff: %lu\n", ft_strlen(buff));
//printf("file_size: %lu\n", file_size);
//printf("len scene: %lu\n", ft_strlen(scene->str_scene));
//free(buff);
