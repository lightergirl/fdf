/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eignatye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 18:45:13 by eignatye          #+#    #+#             */
/*   Updated: 2017/05/05 20:38:27 by eignatye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_point(t_point *point, double x, double y, double z)
{
	point->x = x;
	point->y = y;
	point->z = z;
}

int		hex_to_int(char *hex)
{
	double	result;
	int		i;
	int		byte;
	
	i = HEX_LENGTH;
	result = 0;
	byte = 0;
	while (--i >= 0)
	{
		byte = (int)hex[i];
		if (ft_isdigit(byte))
			byte = byte - '0';
		if (ft_isalpha(byte))
			if (ft_isupper(byte))
				byte = byte - 'A' + 10;
			if (ft_islower(byte))
				byte = byte - 'a' + 10;
		result += byte * pow(16.0, (double)(HEX_LENGTH - 1 - i));
	}
	return (result);
}

void	set_point(t_point *point, int i, int j, char *str)
{
	int		color;
	char	*comma_ptr;
	
	init_point(point, i, j, ft_atoi(str));
	point->color = WHITE_COLOR;
	color = 0;
	comma_ptr = ft_strchr(str, ',');
	if (comma_ptr && (ft_strlen(++comma_ptr) == 8)
		&& (!ft_strncmp(comma_ptr, "0x", 2)))
	{
		color = hex_to_int(comma_ptr + 2);
		if (color && (color >= 0 && color <= WHITE_COLOR))
			point->color = color;
		else
			point->color = WHITE_COLOR;
	}
}

void	cut_to_the_points(t_list **head, int list_size, t_map *map)
{
	t_list	*cur;
	int		i;
	int		j;
	char	**arr;
	
	map->height = list_size;
	cur = *head;
	i = -1;
	j = 0;
	if (!(map->points_arr = (t_point**)malloc(sizeof(t_point) * map->height)))
		print_err(MALLOC_ERR);
	while (++i < list_size)
	{
		arr = ft_strsplit(cur->content, ' ');
		map->weight = min(map->weight, ft_arr_size(arr));
		if (!(map->points_arr[i] =
			  (t_point*)malloc(sizeof(t_point) * map->weight)))
			print_err(MALLOC_ERR);
		j = -1;
		while (arr[++j])
			set_point(&(map->points_arr[i][j]), i, j, arr[j]);
		cur = cur->next;
	}
}

t_map	*read_map(int fd)
{
	t_map	*map;
	char	*line;
	t_list	*head;
	t_list	*current;
	short	gnl_return;

	head = NULL;
	// map init
	if (!(map = (t_map*)malloc(sizeof(t_map))))
		print_err(MALLOC_ERR);
	map->height = 0;
	map->weight = -1; //hack huiak
	//read from file
	while ((gnl_return = get_next_line(fd, &line)) == 1)
	{
		current = ft_lstnew(line, ft_strlen(line) * sizeof(char));
		ft_lstadd_to_end(&head, current);
	}
	if (gnl_return == -1)
		print_err(GNL_ERR);
	cut_to_the_points(&head, ft_list_size(head), map);
	//	print_err(MALLOC_ERR);
	free(head);
	return (map);
}
