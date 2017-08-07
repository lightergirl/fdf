/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eignatye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 18:45:13 by eignatye          #+#    #+#             */
/*   Updated: 2017/08/02 19:46:20 by eignatye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		key_hook(int keycode, t_fdf *m_fdf)
{
	if (keycode == KEY_EXIT || keycode == KEY_CLOSE_WIN)
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
	if (keycode == KEY_ROT_X_POS)
		rotate_map(m_fdf, 'x', ROT_ANGLE_POS);
	else if (keycode == KEY_ROT_Y_POS)
		rotate_map(m_fdf, 'y', ROT_ANGLE_POS);
	else if (keycode == KEY_ROT_Z_POS)
		rotate_map(m_fdf, 'z', ROT_ANGLE_POS);
	else if (keycode == KEY_ROT_X_NEG)
		rotate_map(m_fdf, 'x', ROT_ANGLE_NEG);
	else if (keycode == KEY_ROT_Y_NEG)
		rotate_map(m_fdf, 'y', ROT_ANGLE_NEG);
	else if (keycode == KEY_ROT_Z_NEG)
		rotate_map(m_fdf, 'z', ROT_ANGLE_NEG);
	reload_image(m_fdf);
}

int		exit_win(t_fdf *m_fdf)
{
	key_hook(KEY_CLOSE_WIN, m_fdf);
	return (0);
}
