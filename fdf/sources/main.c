/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eignatye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 18:45:13 by eignatye          #+#    #+#             */
/*   Updated: 2017/08/02 19:46:55 by eignatye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int ac, char **av)
{
	t_map	*map;
	t_fdf	*m_fdf;
	int		fd;

	if (ac != 2)
		print_err("Usage: ./fdf <filename>\n");
	if (!(m_fdf = (t_fdf *)malloc(sizeof(t_fdf))))
		print_err("Malloc error");
	if ((fd = open(av[1], O_RDONLY)) == -1)
		print_err("Incorrect file path");
	map = read_map(fd);
	close(fd);
	fdf_init(m_fdf, map);
	draw_image(m_fdf);
	mlx_hook(m_fdf->window, 2, 5, key_hook, (void *)m_fdf);
	mlx_hook(m_fdf->window, 17, 0, exit_win, (void *)m_fdf);
	mlx_loop(m_fdf->init);
	return (0);
}
