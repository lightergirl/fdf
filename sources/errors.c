/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eignatye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 18:45:13 by eignatye          #+#    #+#             */
/*   Updated: 2017/04/17 18:45:17 by eignatye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

void	print_err(short err)
{
	if (err == 1)
		perror("Incorrect file path");
	if (err == 2)
		perror("Malloc error");
	if (err == 3)
		perror("Get line from file error");
	exit(0);
}
