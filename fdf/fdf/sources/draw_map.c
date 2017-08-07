/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eignatye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 18:45:13 by eignatye          #+#    #+#             */
/*   Updated: 2017/08/02 17:34:55 by eignatye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	set_pixel(t_fdf *m_fdf, t_point *point)
{
	int byte;

	if (point->x >= 0 && point->x < WINSIZE_X &&
			point->y >= 0 && point->y < WINSIZE_Y)
	{
		byte = ((int)point->x * 4) + ((int)point->y * m_fdf->size_line);
		m_fdf->data_ptr[byte] = point->color;
		m_fdf->data_ptr[++byte] = point->color >> 8;
		m_fdf->data_ptr[++byte] = point->color >> 16;
	}
}

void	brez_draw(t_fdf *m_fdf, t_brez *brez)
{
	double	tmp_err;
	int		flag;

	flag = 1;
	set_pixel(m_fdf, &brez->point2);
	while (flag == 1 && (brez->point1.x != brez->point2.x
				|| brez->point1.y != brez->point2.y))
	{
		flag = 0;
		set_pixel(m_fdf, &brez->point1);
		tmp_err = brez->err;
		if (tmp_err > -brez->d_x && (int)brez->point1.x != (int)brez->point2.x)
		{
			brez->err -= brez->d_y;
			brez->point1.x += brez->sign_x;
			flag = 1;
		}
		if (tmp_err < brez->d_y && (int)brez->point1.y != (int)brez->point2.y)
		{
			brez->err += brez->d_x;
			brez->point1.y += brez->sign_y;
			flag = 1;
		}
	}
}

void	brez_init(t_fdf *m_fdf, t_point point1, t_point point2)
{
	t_brez *brez;

	if (!(brez = (t_brez *)malloc(sizeof(t_brez))))
		print_err("Draw error");
	brez->point1 = point1;
	brez->point2 = point2;
	brez->d_x = fabs(point1.x - point2.x);
	brez->d_y = fabs(point1.y - point2.y);
	brez->sign_x = point2.x > point1.x ? 1 : -1;
	brez->sign_y = point2.y > point1.y ? 1 : -1;
	brez->err = brez->d_x > brez->d_y ? (brez->d_x * 0.5) : (-brez->d_y * 0.5);
	brez_draw(m_fdf, brez);
	free(brez);
}

void	draw_image(t_fdf *m_fdf)
{
	size_t y;
	size_t x;

	y = 0;
	while (y < m_fdf->map->height)
	{
		x = 0;
		while (x < m_fdf->map->width)
		{
			if (x < m_fdf->map->width - 1)
			{
				brez_init(m_fdf, m_fdf->map->points_arr[y][x],
						m_fdf->map->points_arr[y][x + 1]);
			}
			if (y < m_fdf->map->height - 1)
				brez_init(m_fdf, m_fdf->map->points_arr[y][x],
						m_fdf->map->points_arr[y + 1][x]);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(m_fdf->init, m_fdf->window, m_fdf->image, 0, 0);
	mlx_destroy_image(m_fdf->init, m_fdf->image);
}

void	reload_image(t_fdf *m_fdf)
{
	m_fdf->image = mlx_new_image(m_fdf->init, WINSIZE_X, WINSIZE_Y);
	m_fdf->data_ptr = mlx_get_data_addr(m_fdf->image, &m_fdf->bits_per_pixel,
										&m_fdf->size_line, &m_fdf->endian);
	draw_image(m_fdf);
}
