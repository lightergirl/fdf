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

int		hex_to_int(char *hex)
{
	int     result;
	int		i;
	int		byte;
	
	i = HEX_LENGTH;
	result = 0;
	byte = 0;
	while (--i >= 0)
	{
		byte = (int)(hex[i]);
		if (ft_isdigit(byte))
			byte = byte - '0';
		if (ft_isalpha(byte))
			if (ft_isupper(byte))
				byte = byte - 'A' + 10;
			if (ft_islower(byte))
				byte = byte - 'a' + 10;
		result += byte * (int)pow(16.0, (double)(HEX_LENGTH - 1 - i));
	}
	return (result);
}

void	set_point(t_point *point, int i, int j, char *str)
{
	int		color;
	size_t	color_len;
	char	*comma_ptr;
	char	*color_ptr;
	int		it;
	
	init_point(point, i, j, ft_atoi(str));
	point->color = WHITE_COLOR;
	color = 0;
	it = 0;
	color_ptr = ft_strnew(6);
	comma_ptr = ft_strchr(str, ',');
	if (comma_ptr && (!ft_strncmp(++comma_ptr, "0x", 2)))
	{
		if ((color_len = ft_strlen(comma_ptr + 2)) < 6)
			while (it + color_len != HEX_LENGTH)
				color_ptr[it++] = '0';
		ft_strncpy(&color_ptr[it], comma_ptr + 2, color_len);
		color = hex_to_int(color_ptr);
		if (color >= 0 && color < WHITE_COLOR)
			point->color = color;
	}
	free(color_ptr);
}

void	cut_to_the_points(t_list **head, int list_size, t_map *map)
{
	t_list	*cur;
	size_t	i;
	size_t	j;
	char	**arr;
	
	map->height = list_size;
	cur = *head;
	i = 0;
	j = 0;
	if (!(map->points_arr = (t_point**)malloc(sizeof(t_point*) * map->height)))
		print_err("Malloc error");
	while (i < map->height)
	{
		arr = ft_strsplit(cur->content, ' ');
		map->width= min(map->width, ft_arr_size(arr));
		if (!(map->points_arr[i] =
			  (t_point*)malloc(sizeof(t_point) * map->width)))
			print_err("Malloc error");
		j = 0;
		while (j < map->width)
		{
			set_point(&(map->points_arr[i][j]), i, j, arr[j]);
			j++;
		}
		cur = cur->next;
		i++;
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
	if (!(map = (t_map*)malloc(sizeof(t_map))))
		print_err("Malloc error");
	map->height = 0;
	map->width = -1; /*hack huiak*/
	while ((gnl_return = get_next_line(fd, &line)) == 1)
	{
		current = ft_lstnew(line, ft_strlen(line) * sizeof(char));
		ft_lstadd_to_end(&head, current);
	}
	if (gnl_return == -1)
		print_err("Get line from file error");
	cut_to_the_points(&head, ft_list_size(head), map);
    //add list_free() for head list
	free(head);
	return (map);
}
