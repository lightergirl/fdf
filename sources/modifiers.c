/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eignatye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 18:45:13 by eignatye          #+#    #+#             */
/*   Updated: 2017/05/05 20:38:27 by eignatye         ###   ########.fr       */
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
	//t_point *point;
	size_t	y;
	size_t	x;

	y = 0;
	while (y < m_fdf->map->height)
	{
		x = 0;
		while (x < m_fdf->map->width)
		{
			// point = &m_fdf->map->points_arr[y][x];
			// point->x = point->x * zoom_value;
			// point->y = point->y * zoom_value;
			// point->z = point->z * zoom_value;
			// m_fdf->map->points_arr[y][x] = *point;
			m_fdf->map->points_arr[y][x]->x *= zoom_value;
			m_fdf->map->points_arr[y][x]->y *= zoom_value;
			m_fdf->map->points_arr[y][x]->z *= zoom_value;		
			//shifting(m_fdf, point, 1);
			printf("x = %zu, y = %zu, col = %d\n", x, y, point->color);
			x++;
		}
		y++;
	}
}

void	move_map(t_fdf *m_fdf, double d_x, double d_y)
{
	//t_point *point;
	size_t	y;
	size_t	x;
	
	y = 0;
	while (y < m_fdf->map->height)
	{
		x = 0;
		while (x < m_fdf->map->width)
		{
			// point = &m_fdf->map->points_arr[y][x];
			// point->x = point->x + d_x;
			// point->y = point->y + d_y;
			// m_fdf->map->points_arr[y][x] = *point;
			m_fdf->map->points_arr[y][x]->x += d_x;
			m_fdf->map->points_arr[y][x]->y += d_y;	
			//shifting(m_fdf, point, 1);
			printf("x = %zu, y = %zu, col = %d\n", x, y, point->color);
			x++;
		}
		y++;
	}
}

void	rotate_map(t_fdf *m_fdf, char axis, double rot_angle)
{
	t_point *point;
	size_t	i;
	size_t	j;
	
	i = 0;
	while (i < m_fdf->map->height)
	{
		j = 0;
		while (j < m_fdf->map->width)
		{
			point = &m_fdf->map->points_arr[i][j];
			rotate_by_axis(point, axis, rot_angle);
			m_fdf->map->points_arr[i][j] = *point;
			//shifting(m_fdf, point, 1);
			printf("j = %zu, i = %zu, col = %d\n", j, i, point->color);
			j++;
		}
		i++;
	}
}

void	rotate_by_axis(t_point *point, char axis, double rot_angle)
{
	if (axis == 'x')
	{
		point->y = point->y * cos(angle) + point->z * -sin(angle);
		point->z = point->y * sin(angle) + point->z * cos(angle);
	}
	else if (axis == 'y')
	{
		point->x = point->x * cos(angle) + point->z * sin(angle);
		point->z = point->x * -sin(angle) + point->z * cos(angle);
	}
	else
	{
		point->x = point->x * cos(angle) + point->y * -sin(angle);
		point->y = point->x * sin(angle) + point->y * cos(angle);
	}
}