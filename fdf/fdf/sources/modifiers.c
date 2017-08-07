/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eignatye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 18:45:13 by eignatye          #+#    #+#             */
/*   Updated: 2017/08/02 19:59:05 by eignatye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	shifting(t_fdf *m_fdf, t_point *point, short direction)
{
	if (direction == -1)
	{
		point->x -= m_fdf->center_point.x;
		point->y -= m_fdf->center_point.y;
	}
	if (direction == 1)
	{
		point->x += m_fdf->center_point.x;
		point->y += m_fdf->center_point.y;
	}
}

void	scale_map(t_fdf *m_fdf, double zoom_value)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < m_fdf->map->height)
	{
		x = 0;
		while (x < m_fdf->map->width)
		{
			shifting(m_fdf, &m_fdf->map->points_arr[y][x], -1);
			m_fdf->map->points_arr[y][x].x *= zoom_value;
			m_fdf->map->points_arr[y][x].y *= zoom_value;
			m_fdf->map->points_arr[y][x].z *= zoom_value;
			shifting(m_fdf, &m_fdf->map->points_arr[y][x], 1);
			x++;
		}
		y++;
	}
}

void	move_map(t_fdf *m_fdf, double d_x, double d_y)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < m_fdf->map->height)
	{
		x = 0;
		while (x < m_fdf->map->width)
		{
			shifting(m_fdf, &m_fdf->map->points_arr[y][x], -1);
			m_fdf->map->points_arr[y][x].x += d_x;
			m_fdf->map->points_arr[y][x].y += d_y;
			shifting(m_fdf, &m_fdf->map->points_arr[y][x], 1);
			x++;
		}
		y++;
	}
	center_map(m_fdf);
}

void	rotate_map(t_fdf *m_fdf, char axis, double rot_angle)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < m_fdf->map->height)
	{
		j = 0;
		while (j < m_fdf->map->width)
		{
			shifting(m_fdf, &m_fdf->map->points_arr[i][j], -1);
			rotate_by_axis(&m_fdf->map->points_arr[i][j], axis, rot_angle);
			shifting(m_fdf, &m_fdf->map->points_arr[i][j], 1);
			j++;
		}
		i++;
	}
}

void	rotate_by_axis(t_point *point, char axis, double rot_angle)
{
	double x;
	double y;
	double z;

	x = point->x;
	y = point->y;
	z = point->z;
	if (axis == 'x')
	{
		point->y = y * cos(rot_angle) + z * -sin(rot_angle);
		point->z = y * sin(rot_angle) + z * cos(rot_angle);
	}
	else if (axis == 'y')
	{
		point->x = x * cos(rot_angle) + z * sin(rot_angle);
		point->z = x * -sin(rot_angle) + z * cos(rot_angle);
	}
	else
	{
		point->x = x * cos(rot_angle) + y * -sin(rot_angle);
		point->y = x * sin(rot_angle) + y * cos(rot_angle);
	}
}
