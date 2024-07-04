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

#ifndef PIXEL_H
# define PIXEL_H

# define WIN_HEIGHT 1080
# define WIN_WIDTH 1920
# define SHADOW_RAY_MIN_DISTANCE 0.0001
# define IS_LINUX 1
# define ESC_KEY 65307
# define R_KEY 114
# define G_KEY 103
# define B_KEY 98
# define LEFT_CLICK 1

typedef struct s_event
{
	int		x;
	int		y;
	int		lastx;
	int		lasty;
	int		mouse;

}	t_event;

typedef struct s_img
{
	void	*img_ptr;
	char	*img_pixel_str;
	int		bpp;
	int		size_line;
	int		endian;
}			t_img;

typedef struct s_matrix
{
	float		m[4][4];
}	t_matrix;

typedef struct s_pixel_info
{
	t_img	*img;
	int		x;
	int		y;
	int		color;
}	t_pixel_info;

#endif
