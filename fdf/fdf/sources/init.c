/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eignatye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 17:58:57 by eignatye          #+#    #+#             */
/*   Updated: 2017/08/02 19:43:50 by eignatye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_point(t_point *point, double y, double x, double z)
{
	point->x = x;
	point->y = y;
	point->z = z;
	point->color = WHITE_COLOR;
}

void	center_map(t_fdf *m_fdf)
{
	double	max_z;
	size_t	i;
	size_t	j;
	t_point	**p_arr;

	p_arr = m_fdf->map->points_arr;
	if ((m_fdf->center_point.x = (p_arr[0][0].x +
					p_arr[0][m_fdf->map->width - 1].x) * 0.5) == 0)
		m_fdf->center_point.x = 1.0;
	if ((m_fdf->center_point.y = (p_arr[0][0].y +
					p_arr[m_fdf->map->height - 1][0].y) * 0.5) == 0)
		m_fdf->center_point.y = 1.0;
	i = 0;
	while (i < m_fdf->map->height)
	{
		j = 0;
		while (j < m_fdf->map->width)
		{
			max_z = MAX(max_z, p_arr[i][j].z);
			j++;
		}
		i++;
	}
	if (!(m_fdf->center_point.z = (max_z * 0.5)))
		m_fdf->center_point.z = 1;
}

void	fdf_init(t_fdf *m_fdf, t_map *map)
{
	m_fdf->map = map;
	center_map(m_fdf);
	scale_map(m_fdf, 2);
	move_map(m_fdf, ((double)WINSIZE_X * 0.5) - m_fdf->center_point.x,
			((double)WINSIZE_Y * 0.5) - m_fdf->center_point.y);
	rotate_map(m_fdf, 'x', 45);
	m_fdf->init = mlx_init();
	m_fdf->window = mlx_new_window(m_fdf->init, WINSIZE_X, WINSIZE_Y, "fdf");
	m_fdf->image = mlx_new_image(m_fdf->init, WINSIZE_X, WINSIZE_Y);
	m_fdf->data_ptr = mlx_get_data_addr(m_fdf->image, &m_fdf->bits_per_pixel,
			&m_fdf->size_line, &m_fdf->endian);
}
