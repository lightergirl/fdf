/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eignatye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 18:45:13 by eignatye          #+#    #+#             */
/*   Updated: 2017/05/04 20:25:48 by eignatye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		init_point(t_point *point, double x, double y, double z)
{
	point->x = x;
	point->y = y;
	point->z = z;
}

t_map		*init_map(t_point **point_arr, double m_height, double m_weight)
{
	t_map	*map;

	if (!(map = (t_map*)malloc(sizeof(t_map))))
		print_err(MALLOC_ERR);
	map->points_arr = point_arr;
	map->m_height = m_height;
	map->m_weight = m_weight;
	return (map);
}

void		print_map(t_map *map)
{
	for (int i = 0; i < map->m_height; i++)
	{
		for (int j = 0; j < map->m_weight; j++)
			printf ("%.1f:%.1f:%.1f\n", map->points_arr[i][j].x, map->points_arr[i][j].y, map->points_arr[i][j].z);
		printf ("\n");
	}
}

t_map		*cut_to_the_points(t_list **head, int list_size)
{
	t_map	*map;
	t_list	*cur;
	int		i;
	int		j;
	char	**arr;

	if (!(map->points_arr = (t_point**)malloc(sizeof(t_point) * list_size)))
		print_err(MALLOC_ERR);
	cur = *head;
	i = 0;
	j = 0;
	while (cur)
	{
		if (!(arr = ft_strsplit(cur->content, ' ')) ||
		!(map->points_arr[i] =
			(t_point*)malloc(sizeof(t_point) * ft_arr_size(arr))))
			print_err(MALLOC_ERR);
		j = -1;
		while (arr[++j])
			init_point(&(map->points_arr[i][j]), i, j, ft_atoi(arr[j]));
		cur = cur->next;
		i++;
	}
	map = init_map(map->points_arr, i, j);
	return (map);
}

t_map		*read_map(int fd)
{
	t_map	*map;
	char	*line;
	t_list	*head;
	t_list	*current;
	short	gnl_return;

	head = NULL;
	while ((gnl_return = get_next_line(fd, &line)) == 1)
	{
		current = ft_lstnew(line, ft_strlen(line) * sizeof(char));
		ft_lstadd_to_end(&head, current);
	}
	if (gnl_return == -1)
		print_err(GNL_ERR);
	if (!(map = cut_to_the_points(&head, ft_list_size(head))))
		print_err(MALLOC_ERR);
	free(head);
	print_map(map);
	return (map);
}
