
#ifndef PIXEL_H
# define PIXEL_H

#define WIN_HEIGHT 1080
#define WIN_WIDTH 1920
#define SHADOW_RAY_MIN_DISTANCE 0.0001
//HOOKS

# ifdef __APPLE__
#  define IS_LINUX 0
#  define ESC_KEY 53
#  define R_KEY 15
#  define G_KEY 5
#  define B_KEY 11
#  define LEFT_CLICK 1
/*
#  define A_KEY 0
#  define S_KEY 1
#  define D_KEY 2
#  define C_KEY 5
#  define I_KEY 34
#  define P_KEY 35
#  define L_KEY 37
#  define RIGHT_CLICK 2*/
# elif defined __unix__
#  define IS_LINUX 1
#  define ESC_KEY 65307
# define R_KEY 114
# define G_KEY 103
# define B_KEY 98
# define LEFT_CLICK 1

#endif

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
	int		size_line; //octets per line
	int		endian;
}			t_img;

typedef struct s_matrix
{
    float m[4][4];
} t_matrix;

typedef struct s_pixel_info
{
    t_img *img;
    int x;
    int y;
    int color;
} t_pixel_info;


#endif
