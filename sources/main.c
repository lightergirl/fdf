/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eignatye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 18:45:13 by eignatye          #+#    #+#             */
/*   Updated: 2017/05/05 20:37:28 by eignatye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

void		print_map(t_map *map)
{
	for (size_t i = 0; i < map->height; i++)
	{
		for (size_t j = 0; j < map->weight; j++)
			printf ("%.1f:%.1f:%.1f:col=%d\t\t", map->points_arr[i][j].x, map->points_arr[i][j].y, map->points_arr[i][j].z, map->points_arr[i][j].color);
		printf ("\n");
	}
}

int main(int ac, char **av)
{
	t_map	*map;
	int		fd;

	if (ac == 2)
	{	
		if ((fd = open(av[1], O_RDONLY)) == -1)
		{
			print_err(FILEPATH_ERR);
			exit(0);
		}
		map = read_map(fd);
		close(fd);
		print_map(map);
		map->init = mlx_init();
		map->window = mlx_new_window(map->init, WINSIZE_X, WINSIZE_Y, "fdf");
		draw_map(map);
		mlx_loop(map->init);
		
		int i = 0;
		while (++i < 100)
			mlx_pixel_put(map->init, map->window, i, 1, 0x00FFFFFF);//does't draw((
		free(map);
	}
	else
		ft_putstr("Usage: ./fdf <filename>\n");
	return (0);
}
