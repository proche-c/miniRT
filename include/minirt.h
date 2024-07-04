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

# define DEBUG 0
# define DEBUGEXEC 0
# define MAX_LEN	10000
# define PI 3.1415926535897932385
# define ASPECT_RATIO 1
# define DISTANCE_VIEWPORT 1
# define IMAGE_SIDE 1000
# define E 0.0000000001

# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# include "../libft/libft.h"
# include "mlx.h"
# include "./pixel.h"

typedef struct s_vector
{
	float				x;
	float				y;
	float				z;
	float				length_squared;
	float				length;
}	t_vector;

typedef struct s_quadratic
{
	float				a;
	float				b;
	float				c;
	float				t1;
	float				t2;
	float				disc;
}	t_quadratic;

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

typedef struct s_ray
{
	struct s_vector		origin;
	struct s_vector		direction;
	struct s_vector		pixel_center;
	float				t_min;
	float				t_max;
}	t_ray;

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

typedef struct s_intersection
{
	int					state;
	int					cy_base;
	struct s_vector		position;
	struct s_ray		ray;
	struct s_element	*element;
	float				distance;
	int					is_shadow;
}	t_intersection;

typedef struct s_scene
{
	char				*str_scene;
	int					image_side; // width and height in pixel (it's square)
	float				focal_length; // distance between viewport and camera
	float				h; // tan camera fov
	float				viewport_side;
	struct s_vector		u;
	struct s_vector		v;
	struct s_vector		view_u;
	struct s_vector		view_v;
	struct s_vector		delta_u;
	struct s_vector		delta_v;
	struct s_vector		pixel00;
	int					flag;
	struct s_camera		camera;
	struct s_ambient	ambient;
	struct s_light		light;
	struct s_element	*elements;
	struct s_img		img;
	void				*mlx_ptr;
	void				*window_ptr;
	int					num_objects;
}	t_scene;

typedef struct s_light_ambient
{
	t_light				*light;
	t_ambient			*ambient;
}	t_light_ambient;

// CHECKERS

int			ft_check(char *file_name, t_scene *scene);
int			ft_check_extension(char *file_name);
int			ft_check_file(int fd, t_scene *scene);

// PARSE
	/*parse.c*/
int			ft_parse(t_scene *scene);
int			ft_get_parameter(char *line, t_scene *scene);
int			ft_get_data(char **params, t_scene *scene);
t_vector	ft_normalize_params(t_vector vector);

	/*camera.c*/
int			ft_get_camera(char **params, t_scene *scene);
int			ft_data_camera(char **params, t_scene *scene);
int			ft_get_fov(char **params, t_scene *scene);
int			ft_get_orientation(char **params, t_scene *scene);
int			ft_is_vector(char **co);
int			ft_is_normalized(char **co);
int			ft_get_pov(char **params, t_scene *scene);

	/*ambient.c*/
int			ft_get_ambient(char **params, t_scene *scene);
int			ft_data_ambient(char **params, t_scene *scene);
int			ft_get_ambient_ratio(char **params, t_scene *scene);
int			ft_get_color(char **params, t_scene *scene);
int			ft_is_color(char **col);

	/*light.c*/
int			ft_get_light(char **params, t_scene *scene);
int			ft_data_light(char **params, t_scene *scene);
int			ft_get_position(char **params, t_scene *scene);
int			ft_get_light_ratio(char **params, t_scene *scene);

	/*elements*/
int			ft_get_element(char **params, t_scene *scene);
int			ft_data_first_element(char **params, t_scene *scene);
int			ft_data_add_element(char **params, t_scene *scene);
int			ft_data_element(t_element *new_element, char **params);
int			ft_get_e_position(t_element *new_element, char *param);
int			ft_get_e_color(t_element *new_element, char *param);
void		ft_add_element(t_element **lst, t_element *new);
t_element	*ft_elelast(t_element *lst);

	/*planes.c*/
int			ft_get_plane(t_element *new_element, char **params);
int			ft_get_e_n_vector(t_element *new_element, char *param);

	/*spheres.c*/
int			ft_get_sphere(t_element *new_element, char **params);
int			ft_get_e_diameter(t_element *new_element, char *param);

	/*cylinders.c*/
int			ft_get_cylinder(t_element *new_element, char **params);
int			ft_get_e_height(t_element *new_element, char *param);
int			ft_assign_cylinder_params(t_element *new_element, char **params);

	/*utils*/

//UTILS
	/*utils_parse*/
int			ft_count_params(char **params);
int			ft_is_float(char *str);
int			ft_is_a_num(char *str);
int			ft_is_positive(char *str);
float		ft_atof(char *str);

	/*utils_execute*/
float		ft_degrees_to_radians(float degrees);

	/*init*/
void		ft_initialize_scene(t_scene *scene);
int			ft_init_camera(t_scene *scene);
int			ft_init_ambient(t_scene *scene);
int			ft_init_light(t_scene *scene);

//EXECUTE
	/*execute*/
int			ft_execute(t_scene *scene);
void		write_pixel_object(t_scene *scene, t_intersection *intersection,
				int j, int i);

	/*vectors_1*/
t_vector	ft_add_vectors(t_vector v1, t_vector v2);
t_vector	ft_sub_vectors(t_vector v1, t_vector v2);
t_vector	ft_multiply_vectors(t_vector v1, t_vector v2);
t_vector	ft_mult_vector_float(t_vector v, float f);
t_vector	ft_div_vector_float(t_vector v, float f);

	/*vectors_2*/
float		ft_get_length_squared(t_vector v);
float		ft_get_vector_length(t_vector v);
float		ft_dot(t_vector v1, t_vector v2);
t_vector	ft_cross(t_vector v1, t_vector v2);
t_vector	ft_unit_vector(t_vector v);
float		ft_distance(t_vector v1, t_vector v2);

	/*viewport*/
void		ft_get_viewport(t_scene *scene);
t_vector	ft_get_vup(t_vector w);
void		ft_get_pixel00(t_scene *scene, t_vector vup, t_vector w);
void		ft_get_scene_u(t_scene *scene, t_vector w, t_vector vup);

	/*intersections*/
void		ft_get_ray(t_scene *scene, t_intersection *inter, int j, int i);
void		ft_hit_something(t_scene *scene, t_intersection *inter);
void		ft_get_inter_ray(t_ray ray, t_intersection *inter);

	/*inter_sphere*/
void		ft_inter_sp(t_intersection *inter, t_element *c_element);
void		ft_get_inter_sp(t_intersection *inter, t_element *c_element,
				float t);
void		ft_get_closest_point(t_intersection *inter, t_vector inter_point,
				t_element *c_element);

	/*inter_plane*/
void		ft_inter_pl(t_intersection *inter, t_element *c_element);
void		ft_get_inter_pl(t_intersection *inter, t_element *c_element,
				float t);

	/*inter_cylinder*/
void		ft_inter_cy(t_intersection *inter, t_element *c_element);
void		ft_init_tmp_inter(t_intersection *tmp_inter,
				t_intersection *inter);
void		ft_init_tmp_plane(t_element *plane, t_element *c_element,
				int point);
void		ft_get_inter_data_1(t_intersection *inter,
				t_intersection *tmp_inter, t_element *c_element);
void		ft_get_inter_data_2(t_intersection *inter,
				t_intersection *tmp_inter, t_element *c_element);
void		ft_inter_inf_cy(t_intersection *tmp_inter, t_element *c_element);
int			ft_get_quadratic(t_quadratic *q);
void		ft_get_closest_point_cy(t_intersection *inter, t_vector inter_point,
				t_element *c_element);

// CLEAN

/*clean.c*/
void		ft_free_scene(t_scene *scene);
void		ft_free_all_elements(t_scene *scene);
void		ft_free_camera(t_scene *scene);
void		ft_free_ambient(t_scene *scene);
void		ft_free_light(t_scene *scene);
void		ft_free_params(char **params);

/*clean_elements.c*/
void		ft_free_planes(t_scene *scene);
void		ft_free_spheres(t_scene *scene);
void		ft_free_cylinders(t_scene *scene);

t_vector	ft_mult_vector_float_1(t_vector v, float f);
t_color		add_light(t_color color, t_color light, float ratio);
void		hook_init(t_scene *scene);
void		color_screen(t_scene *scene, int color);
int			mlx_initiator(t_scene *scene);
int			pixel_print(t_scene *scene);
t_vector	normalize(t_vector v);
t_vector	transform_point_to_world(t_vector local_normal, t_vector n_vector);
t_vector	calculate_cylinder_normal(t_element *element,
				t_intersection *inter);
t_vector	calculate_sphere_normal(t_element *element, t_intersection *inter);
t_vector	calculate_plane_normal(t_element *element, t_vector normal);
t_vector	transform_point_to_local(t_vector inter_position,
				t_vector cylinder_position, t_vector n_vector);
t_color		calculate_lighting(t_scene *scene, t_intersection *inter,
				t_vector normal, t_vector view_dir);
void		ft_pixel_put(t_pixel_info *pixel_info, int image_side);
t_color		rgb2color(int rgb);
int			color2rgb(t_color c);
t_vector	apply_matrix(t_matrix mat, t_vector vec);
t_matrix	create_translation_matrix(float tx, float ty, float tz);

//matrix
t_matrix	create_translation_matrix(float tx, float ty, float tz);
t_matrix	create_rotation_matrix_x(float angle);
t_matrix	create_rotation_matrix_y(float angle);
t_matrix	create_rotation_matrix_z(float angle);
t_matrix	create_scaling_matrix(float sx, float sy, float sz);
t_vector	apply_matrix(t_matrix mat, t_vector vec);
t_matrix	multiply_matrices(t_matrix m1, t_matrix m2);
t_vector	reflect_vector(t_vector incident, t_vector normal);
t_ray		create_shadow_ray(t_vector origin, t_vector light_position);
int			is_in_shadow(t_scene *scene, t_ray shadow_ray, t_light *light,
				t_intersection *inter);
void		ft_hit_something_2(t_scene *scene, t_intersection *shadow_inter,
				t_element *inter_element);
t_vector	calculate_normal(t_intersection *intersection);
t_vector	calculate_view_dir(t_scene *scene, t_intersection *intersection);
void		write_pixel_no_object(t_scene *scene);
float		convert_decimal_part(const char *decimal_str);
void		ft_get_inter_data_1(t_intersection *inter,
				t_intersection *tmp_inter, t_element *c_element);
void		ft_get_inter_data_2(t_intersection *inter,
				t_intersection *tmp_inter, t_element *c_element);
void		ft_get_inter_data_shadow_0(t_intersection *inter,
				t_intersection *tmp_inter, t_element *c_element);
void		ft_get_inter_data_shadow_not_0_v1(t_intersection *inter,
				t_intersection *tmp_inter, t_element *c_element);
void		ft_get_inter_data_shadow_not_0(t_intersection *inter,
				t_intersection *tmp_inter, t_element *c_element);
#endif
