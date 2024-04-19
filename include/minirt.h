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


typedef struct s_scene
{
	struct s_camera		*camera;
	struct s_ambient	*ambient;
	struct s_light		*light;
	struct s_element	*element;
}	t_scene;

typedef struct s_camera
{
	char					identifier;
	float					ratio;
	struct s_coordinates	orientation;
	int						fov;
}	t_camera;

typedef struct s_ambient
{
	char			identifier;
	float			ratio;
	struct s_color	color;
}	t_ambient;

typedef struct s_light
{
	char					identifier;
	float					ratio;
	struct s_color			color;
	struct s_coordinates	position;
}	t_light;

typedef struct s_element
{
	struct s_element	*spheres;
	struct s_element	*planes;
	struct s_element	*cylinders;
}	t_element;

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

typedef struct s_coordinates
{
	int	x;
	int	y;
	int	z;
}	t_coordinates;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

#endif
