/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eignatye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 18:45:13 by eignatye          #+#    #+#             */
/*   Updated: 2017/03/17 18:45:17 by eignatye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_map		*cut_to_the_points(t_list *head, int list_size)
{
	t_point	**points_arr;
	t_map	*map;
	int		i;
	int		j;
	char	**arr;
	
	i = 0;
	while (i < list_size)
	{
		arr = ft_strsplit(head->content, ' ');
		
	}
	return (map);
}

t_map		*read_map(int fd)
{
	t_map	*map;
	char	*line;
	t_list	*head;
	t_list	*current;
	
	head = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		current = ft_lstnew(line, sizeof(line));
		ft_lstadd_to_end(&head, current);
	}
	map = cut_to_the_points(head, ft_list_size(head));
	
	free(head);
	return (map);
}
