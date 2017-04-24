/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eignatye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 18:44:52 by eignatye          #+#    #+#             */
/*   Updated: 2017/03/17 18:45:00 by eignatye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef fdf_h
#define fdf_h

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include "./get_next_line.h"
# include <fcntl.h>
# include <math.h>

typedef struct s_point{
	double	x;
	double	y;
	double	z;
}				t_point;

typedef struct s_map{
	t_point **points_arr;
	double	m_height;
	double	m_weight;
}				t_map;

/*
 reader.c
*/
t_map	*read_map(int fd);



/*
 errors.c
*/
void		print_err(short err);



#endif
