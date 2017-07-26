/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eignatye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 18:44:52 by eignatye          #+#    #+#             */
/*   Updated: 2017/05/05 20:35:43 by eignatye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef fdf_h
#define fdf_h

#define max(a, b) (a) > (b) ? (a) : (b)
#define min(a, b) (a) > (b) ? (b) : (a)

# include "mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <math.h>

# include <stdio.h>

# define BUFF_SIZE			1024
# define WHITE_COLOR		16777215
# define HEX_LENGTH			6
# define WINSIZE_X			1920
# define WINSIZE_Y			1080

# define ZOOM_IN			2.0
# define ZOOM_OUT			0.5
# define KEY_LEFT 			123
# define KEY_RIGHT 			124
# define KEY_UP 			126
# define KEY_DOWN 			125
# define KEY_SCALE_INCREASE 69
# define KEY_SCALE_DECREASE 78
# define KEY_EXIT 			53
# define KEY_ROT_X_POS		12
# define KEY_ROT_Y_POS		13
# define KEY_ROT_Z_POS		14
# define KEY_ROT_X_NEG		0
# define KEY_ROT_Y_NEG		1
# define KEY_ROT_Z_NEG		2
# define ROT_ANGLE_POS		0.05
# define ROT_ANGLE_NEG		-0.05

typedef struct s_point{
	double	x;
	double	y;
	double	z;
	int		color;
}				t_point;

typedef struct s_brez{
    double	d_x;
    double	d_y;
    double	sign_x;
    double	sign_y;
    double	err;
    t_point	point1;
    t_point	point2;
}               t_brez;

typedef struct s_map{
	t_point **points_arr;
	size_t	height;
	size_t	width;
}				t_map;

typedef struct s_fdf{
	t_map	*map;
    t_point center_point;
    void	*init;
	void	*window;
	void	*image;
	char	*data_ptr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}				t_fdf;

int			get_next_line(const int fd, char **line);

/*
 init.c
*/
void		init_point(t_point *point, double x, double y, double z);
void		fdf_init(t_fdf *m_fdf, t_map *map);
void		center_map(t_fdf *m_fdf);

/*
 reader.c
*/
t_map		*read_map(int fd);
void		cut_to_the_points(t_list **head, int list_size, t_map *map);
void		set_point(t_point *point, int i, int j, char *str);
int			hex_to_int(char *hex);

/*
 draw_map.c
*/
void		draw_image(t_fdf *m_fdf);
void		brez_init(t_fdf	*m_fdf, t_point point1, t_point point2);
void		brez_draw(t_fdf *m_fdf, t_brez *brez);
void		set_pixel(t_fdf *m_fdf, t_point *point);
void		reload_image(t_fdf *m_fdf);

/*
 key_hooks.c
 */
int			key_hook(int keycode, t_fdf *m_fdf);
void		zoom_hook(int keycode, t_fdf *m_fdf);
void		move_hook(int keycode, t_fdf *m_fdf);
void		rotate_hook(int keycode, t_fdf *m_fdf);

/*
 modifiers.c
 */
void		scale_map(t_fdf *m_fdf, double zoom_value);
void		move_map(t_fdf *m_fdf, double d_x, double d_y);
void		rotate_map(t_fdf *m_fdf, char axis, double rot_angle);
void		rotate_by_axis(t_point *point, char axis, double rot_angle);
void		shifting(t_fdf *m_fdf, t_point *point, short direction);

/*
 errors.c
*/
void		print_err(char *error_msg);

#endif
