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
# include <fcntl.h>
# include "../libft/libft.h"
# include "mlx.h"

#include <minirt.h>

#define MAX_LEN	10000
# define MAX_KEY 65535

typedef struct s_vector
{
	float				x;
	float				y;
	float				z;
}	t_vector;

typedef struct s_color
{
	int					r;
	int					g;
	int					b;
}	t_color;

typedef struct s_camera
{
	int					defined;
	struct s_vector		pov;
	struct s_vector		orientation;
	int					fov;
}	t_camera;

typedef struct s_ambient
{
	int					defined;
	float				ratio;
	struct s_color		color;
}	t_ambient;

typedef struct s_light
{
	int					defined;
	float				ratio;
	struct s_vector		position;
}	t_light;

typedef struct s_spheres
{
	char				identifier;
	struct s_vector		position;
	float				diameter;
	struct s_color		color;
	struct s_spheres	*next;
}	t_spheres;

typedef struct s_planes
{
	char				identifier;
	struct s_vector		position;
	struct s_vector		n_vector;
	struct s_color		color;
	struct s_planes		*next;
}	t_planes;

typedef struct s_cylinders
{
	char				identifier;
	struct s_vector		position;
	struct s_vector		n_vector;
	float				diameter;
	float				height;
	struct s_color		color;
	struct s_cylinders	*next;
}	t_cylinders;

typedef struct s_element
{
	char				*identifier;
	struct s_vector		position;
	struct s_color		color;
	float				diameter;
	struct s_vector		n_vector;
	float				height;
	struct s_element	*next;
}	t_element;

typedef struct s_event
{
    int		x;
    int		y;
    int		lastx;
    int		lasty;
    int		key[MAX_KEY];
    int		mouse;

}	t_event;

typedef struct s_scene
{
	char				*str_scene;
	int					flag;
	struct s_camera		camera;
	struct s_ambient	ambient;
	struct s_light		light;
	struct s_element	*elements;
	void				*mlx_ptr;
	void				*window_ptr;
	t_event				event;
}	t_scene;

// CHECKERS

int		ft_check(char *file_name, t_scene *scene);
int		ft_check_extension(char *file_name);
int		ft_check_file(int fd, t_scene *scene);

// PARSE
	/*parse.c*/
int	ft_parse(t_scene *scene);
int		ft_get_parameter(char *line, t_scene *scene);
int		ft_get_data(char **params, t_scene *scene);
int		ft_init_elements(t_scene *scene);

	/*camera.c*/
int	 	ft_get_camera(char **params, t_scene *scene);
int		ft_data_camera(char **params, t_scene *scene);
int		ft_get_fov(char **params, t_scene *scene);
int		ft_get_orientation(char **params, t_scene *scene);
int		ft_is_vector(char **co);
int		ft_is_normalized(char **co);
int		ft_get_pov(char **params, t_scene *scene);

	/*ambient.c*/
int	 	ft_get_ambient(char **params, t_scene *scene);
int		ft_data_ambient(char **params, t_scene *scene);
int		ft_get_ambient_ratio(char **params, t_scene *scene);
int		ft_get_color(char **params, t_scene *scene);
int		ft_is_color(char **col);

	/*light.c*/
int	 	ft_get_light(char **params, t_scene *scene);
int		ft_data_light(char **params, t_scene *scene);
int		ft_get_position(char **params, t_scene *scene);
int		ft_get_light_ratio(char **params, t_scene *scene);

	/*elements*/
int	 	ft_get_element(char **params, t_scene *scene);
int	ft_data_first_element(char **params, t_scene *scene);
int	ft_data_add_element(char **params, t_scene *scene);
int		ft_data_element(t_element *new_element, char **params);
int		ft_get_e_position(t_element *new_element, char *param);
int		ft_get_e_color(t_element *new_element, char *param);
void	ft_add_element(t_element **lst, t_element *new);
t_element	*ft_elelast(t_element *lst);

	/*planes.c*/
int	 	ft_get_plane(t_element *new_element, char **params);
int		ft_get_e_n_vector(t_element *new_element, char *param);

	/*spheres.c*/
int 	ft_get_sphere(t_element *new_element, char **params);
int		ft_get_e_diameter(t_element *new_element, char *param);

	/*cylinders.c*/
int	 	ft_get_cylinder(t_element *new_element, char **params);
int	ft_get_e_height(t_element *new_element, char *param);

//UTILS
	/*utils_parse*/
int		ft_count_params(char **params);
int		ft_is_float(char *str);
int		ft_is_a_num(char *str);
int		ft_is_positive(char *str);
float	ft_atof(char *str);

	/*init*/
void		ft_initialize_scene(t_scene *scene);
int		ft_init_camera(t_scene *scene);
int		ft_init_ambient(t_scene *scene);
int		ft_init_light(t_scene *scene);

	/*print*/
void	ft_print_camera(t_scene *scene);
void	ft_print_ambient(t_scene *scene);
void	ft_print_light(t_scene *scene);
void	ft_print_params(char **params);
void	ft_print_elements(t_scene *scene);

//EXECUTE
int		ft_execute(t_scene *scene);

// CLEAN

/*clean.c*/
void	ft_free_scene(t_scene *scene);
void	ft_free_all_elements(t_scene *scene);
void	ft_free_camera(t_scene *scene);
void	ft_free_ambient(t_scene *scene);
void	ft_free_light(t_scene *scene);
void	ft_free_params(char **params);

/*clean_elements.c*/
void	ft_free_planes(t_scene *scene);
void	ft_free_spheres(t_scene *scene);
void	ft_free_cylinders(t_scene *scene);

//EVENT
int	    handle_keydown(int key, t_scene *scene);
int	    handle_keyup(int key, t_scene *scene);
void	hook_init(t_scene *scene);
int	    exit_win(t_scene *scene);
static int	handle_no_event(t_scene *scene);

#endif
