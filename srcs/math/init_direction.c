/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_direction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 10:49:30 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/27 14:28:12 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../include/macro.h"
#include <math.h>
#include <stdio.h>

/*
* Choose texture from wall direction
*/
void	get_dir_wall(t_data *data)
{
	// connaitre la direction du wall savoir quel texture choisir 
	
	// if coodonnes -> en dessous ==  0 -> sud
	// coordonnes -> au dessous == 0 -> nord
	// coord -> droite 0 == west
	// coord -> fauche 0 = est

	(void)data;
	// int side_x = (int)floor(data->render.wall_x) + 1;
	// int side_y = (int)floor(data->render.wall_x) + 1;
	// printf("side_x = %d, side_y = %d\n", side_x, side_y);
	// data->render.wall_x
}

void	init_direction(t_data *data)
{
	double	dirp;

	dirp = 0;
	if (data->player.direction == 'N')
		dirp = PI;
	else if (data->player.direction == 'S')
		dirp = 0;
	else if (data->player.direction == 'W')
		dirp = 1.5 * PI;
	else if (data->player.direction == 'E')
		dirp = 0.5 * PI;
	data->player.dir_x = cos(dirp);
	data->player.dir_y = sin(dirp);
	data->player.dirp = dirp;
}
