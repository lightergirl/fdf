/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eignatye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 18:45:13 by eignatye          #+#    #+#             */
/*   Updated: 2017/05/05 20:38:27 by eignatye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		key_hook(int keycode, t_fdf *m_fdf)
{
	if (keycode == KEY_EXIT)
	{
		mlx_destroy_window(m_fdf->init, m_fdf->window);
		ft_putstr("OK, exit!\n");
		exit(EXIT_SUCCESS);
	}
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT
			 || keycode == KEY_DOWN || keycode == KEY_UP)
		move_hook(keycode, m_fdf);
	else if (keycode == KEY_SCALE_DECREASE || keycode == KEY_SCALE_INCREASE)
		zoom_hook(keycode, m_fdf);
	else if (keycode == KEY_ROT_X_POS || keycode == KEY_ROT_Y_POS || 
			keycode == KEY_ROT_Z_POS || keycode == KEY_ROT_X_NEG || 
			keycode == KEY_ROT_Y_NEG || keycode == KEY_ROT_Z_NEG)
		rotate_hook(keycode, m_fdf);
	else if (keycode == 123456)
	{}
	return (1);
}

void	zoom_hook(int keycode, t_fdf *m_fdf)
{
	if (keycode == KEY_SCALE_DECREASE)
		scale_map(m_fdf, ZOOM_OUT);
	else if (keycode == KEY_SCALE_INCREASE)
		scale_map(m_fdf, ZOOM_IN);
	reload_image(m_fdf);
}

void	move_hook(int keycode, t_fdf *m_fdf)
{
	if (keycode == KEY_LEFT)
		move_map(m_fdf, -20, 0);
	else if (keycode == KEY_RIGHT)
		move_map(m_fdf, 20, 0);
	else if (keycode == KEY_UP)
		move_map(m_fdf, 0, -20);
	else if (keycode == KEY_DOWN)
		move_map(m_fdf, 0, 20);
	reload_image(m_fdf);
}

void	rotate_hook(int keycode, t_fdf *m_fdf)
{
	if (keycode == KEY_ROT_X_POS/*q*/)
		rotate_map(m_fdf, 'x', ROT_ANGLE_POS);
	else if (keycode == KEY_ROT_Y_POS/*w*/)
		rotate_map(m_fdf, 'y', ROT_ANGLE_POS);
	else if (keycode == KEY_ROT_Z_POS/*e*/)
		rotate_map(m_fdf, 'z', ROT_ANGLE_POS);
	else if (keycode == KEY_ROT_X_NEG/*a*/)
		rotate_map(m_fdf, 'x', ROT_ANGLE_NEG);
	else if (keycode == KEY_ROT_Y_NEG/*s*/)
		rotate_map(m_fdf, 'y', ROT_ANGLE_NEG);
	else if (keycode == KEY_ROT_Z_NEG/*d*/)
		rotate_map(m_fdf, 'z', ROT_ANGLE_NEG);
	reload_image(m_fdf);
}