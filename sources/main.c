/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eignatye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 18:45:13 by eignatye          #+#    #+#             */
/*   Updated: 2017/03/17 18:45:17 by eignatye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int main(int ac, char **av)
{
	t_map	*map;
	int		fd;
	
	if ((fd = open(av[1], O_RDONLY)) == -1)
	{
		print_err(FILEPATH_ERR);
		exit(0);
	}
	map = read_map(fd);
/*	
	print_map(map);
 */
	close(fd);
	return (0);
}
