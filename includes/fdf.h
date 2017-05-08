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

# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <math.h>

# define BUFF_SIZE		1024
# define FILEPATH_ERR	1
# define MALLOC_ERR		2
# define GNL_ERR		3
# define WHITE_COLOR	16777215
# define HEX_LENGTH		6
# define WINSIZE_X		2000
# define WINSIZE_Y		1500

typedef struct s_point{
	double	x;
	double	y;
	double	z;
	int		color;
}				t_point;

typedef struct s_map{
	t_point **points_arr;
	size_t	height;
	size_t	weight;
	void	*init;
	void	*window;
}				t_map;

int			get_next_line(const int fd, char **line);

/*
 reader.c
*/
t_map		*read_map(int fd);
void		cut_to_the_points(t_list **head, int list_size, t_map *map);
void		set_point(t_point *point, int i, int j, char *str);
void		init_point(t_point *point, double x, double y, double z);
int			hex_to_int(char *hex);

/*
 draw_map.c
*/
void		draw_map(t_map	*map);

/*
 errors.c
*/
void		print_err(short err);


void		print_map(t_map *map);

#endif
