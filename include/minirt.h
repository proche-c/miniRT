/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2023/10/05 00:34:53 by vaguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
#include <fcntl.h>
# include "../libft/libft.h"

#define MAX_LEN	10000

typedef struct s_coordinates
{
	float	*x;
	float	*y;
	float	*z;
}	t_coordinates;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;


typedef struct s_camera
{
	int						defined;
	int						pov_defined;
	int						orientation_defined;
	int						fov_defined;
	char					identifier;
	struct s_coordinates	*pov;
	struct s_coordinates	*orientation;
	int						*fov;
}	t_camera;

typedef struct s_ambient
{
	int				defined;
	char			identifier;
	float			ratio;
	struct s_color	color;
}	t_ambient;

typedef struct s_light
{
	int						defined;
	char					identifier;
	float					ratio;
	struct s_color			color;
	struct s_coordinates	position;
}	t_light;

typedef struct s_spheres
{
	char					identifier;
	struct s_coordinates	position;
	float					diameter;
	struct s_color			color;
	struct s_spheres		*next;
}	t_spheres;

typedef struct s_planes
{
	char					identifier;
	struct s_coordinates	position;
	struct s_coordinates	n_vector;
	struct s_color			color;
	struct s_planes			*next;
}	t_planes;

typedef struct s_cylinders
{
	char					identifier;
	struct s_coordinates	position;
	struct s_coordinates	n_vector;
	float					diameter;
	float					height;
	struct s_color			color;
	struct s_cylinders		*next;
}	t_cylinders;

typedef struct s_element
{
	struct s_spheres	*spheres;
	struct s_planes		*planes;
	struct s_cylinders	*cylinders;
}	t_element;

typedef struct s_scene
{
	char				*str_scene;
	struct s_camera		*camera;
	struct s_ambient	*ambient;
	struct s_light		*light;
	struct s_element	*elements;
}	t_scene;

// CHECKERS

int		ft_check(char *file_name, t_scene *scene);
int		ft_check_extension(char *file_name);
int		ft_check_file(int fd, t_scene *scene);

// PARSE
	/*parse.c*/
int		ft_parse(t_scene *scene);
void	ft_initialize_scene(t_scene *scene);
int		ft_get_parameter(char *line, t_scene *scene);
int		ft_get_data(char **params, t_scene *scene);
int		ft_init_elements(t_scene *scene);

	/*camera.c*/
int	 	ft_get_camera(char **params, t_scene *scene);
int		ft_init_camera(t_scene *scene);
int		ft_data_camera(char **params, t_scene *scene);
int		ft_get_fov(char **params, t_scene *scene);
int		ft_get_orientation(char **params, t_scene *scene);
int		ft_is_coordinates(char **co);
int		ft_is_normalized(char **co);
int		ft_data_orientation(char **co, t_scene *scene);

	/*ambient.c*/
int	 	ft_get_ambient(char **params, t_scene *scene);
int		ft_init_ambient(t_scene *scene);

	/*light.c*/
int	 	ft_get_light(char **params, t_scene *scene);
int		ft_init_light(t_scene *scene);

	/*planes.c*/
int	 	ft_get_planes(char **params, t_scene *scene);
int		ft_init_planes(t_scene *scene);

	/*spheres.c*/
int	 	ft_get_spheres(char **params, t_scene *scene);
int		ft_init_spheres(t_scene *scene);

	/*cylinders.c*/
int	 	ft_get_cylinders(char **params, t_scene *scene);
int		ft_init_cylinders(t_scene *scene);

//UTILS
	/*utils_parse*/
int		ft_count_params(char **params);
int		ft_is_float(char *str);
int		ft_is_a_num(char *str);
int		ft_is_positive(char *str);
float	ft_atof(char *str);

//EXECUTE
int		ft_execute(void);

// CLEAN

/*clean.c*/
void	ft_free_scene(t_scene *scene);
void	ft_free_camera(t_scene *scene);
void	ft_free_ambient(t_scene *scene);
void	ft_free_light(t_scene *scene);
void	ft_free_params(char **params);

/*clean_elements.c*/
void	ft_free_planes(t_scene *scene);
void	ft_free_spheres(t_scene *scene);
void	ft_free_cylinders(t_scene *scene);

#endif
