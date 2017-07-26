/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eignatye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 18:45:13 by eignatye          #+#    #+#             */
/*   Updated: 2017/05/05 20:38:27 by eignatye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_point(t_point *point, double y, double x, double z)
{
	point->x = x;
	point->y = y;
	point->z = z;
}

void    center_map(t_fdf *m_fdf)
{
    double  max_z;
    int     i;
    int     j;
	t_point **p_arr;
	
	p_arr = m_fdf->map->points_arr;
	if (!(m_fdf->center_point.x = /*WINSIZE_X / 2 -*/ 
			p_arr[0][m_fdf->map->width - 1]->x / 2)
		m_fdf->center_point.x = 1;
	if (!(m_fdf->center_point.y = /*WINSIZE_Y / 2 -*/
			p_arr[m_fdf->map->height - 1][0]->y / 2)
		m_fdf->center_point.y = 1;
    i = -1;
    j = -1;
    max_z = p_arr[0][0].z;
    while (++i < m_fdf->map->height)
        while (++j < m_fdf->map->width)
            max_z = max(max_z, p_arr[i][j].z);
    if (!(m_fdf->center_point.z = (max_z - 1) / 2)
		m_fdf->center_point.z = 1;
}

void	fdf_init(t_fdf *m_fdf, t_map *map)
{
	m_fdf->map = map;
    center_map(m_fdf);
	scale_map(m_fdf, WINSIZE_X / 4 / m_fdf->center_point.x);
	move_map(m_fdf, WINSIZE_X / 2 - m_fdf->center_point.x,
				WINSIZE_Y / 2 - m_fdf->center_point.y);
	rotate_map(m_fdf, 'x', 45);
	m_fdf->init = mlx_init();
	m_fdf->window = mlx_new_window(m_fdf->init, WINSIZE_X, WINSIZE_Y, "fdf");
	m_fdf->image = mlx_new_image(m_fdf->init, WINSIZE_X, WINSIZE_Y);
	m_fdf->data_ptr = mlx_get_data_addr(m_fdf->image, &m_fdf->bits_per_pixel,
							   &m_fdf->size_line, &m_fdf->endian);
}

// void	ft_init_usage(t_fdf *m_fdf)
// {
// 	void	*usage_win;
	
// 	usage_win = mlx_new_window(m_fdf, 250, 250, "usage");
// 	mlx_string_put(m_fdf, usage_win, 10, 0, 0xff0000, "'i' - create img");
// 	mlx_string_put(m_fdf, usage_win, 10, 20, 0xff0000, "'d' - delete image");
// 	mlx_string_put(m_fdf, usage_win, 10, 40, 0xff0000, "'+ / -' - zoom in / out");
// 	mlx_string_put(m_fdf, usage_win, 10, 60, 0xff0000, "");
// 	mlx_string_put(m_fdf, usage_win, 10, 80, 0xff0000, "'a' - rotate x down");
// 	mlx_string_put(m_fdf, usage_win, 10, 100, 0xff0000, "'q' - rotate x up");
// 	mlx_string_put(m_fdf, usage_win, 10, 120, 0xff0000, "'s' - rotate y down");
// 	mlx_string_put(m_fdf, usage_win, 10, 140, 0xff0000, "'w' - rotate y up");
// 	mlx_string_put(m_fdf, usage_win, 10, 160, 0xff0000, "'d' - rotate z down");
// 	mlx_string_put(m_fdf, usage_win, 10, 180, 0xff0000, "'e' - rotate z down");
// 	mlx_string_put(m_fdf, usage_win, 10, 200, 0xff0000, "");
// 	mlx_string_put(m_fdf, usage_win, 10, 220, 0xff0000, "'esc' - kill fdf");
// }