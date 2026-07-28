/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_direction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 10:49:30 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/28 11:05:34 by pswirgie         ###   ########.fr       */
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
	
	// prendre en compte la position actuel du player 


	// if coodonnes -> en dessous ==  0 -> sud
	// coordonnes -> au dessous == 0 -> nord
	// coord -> droite 0 == west
	// coord -> fauche 0 = est

	int x = data->wall.map_x;
	int y = data->wall.map_y;
	
	// data->wall.distance_x -= floor(data->wall.distance_x);
	
	// || data->wall.distance_x < floor(data->wall.distance_x) - 0.9)
	// if (data->wall.distance_x < floor(data->wall.distance_x) + 0.9)
	
	printf(" distance x = %f, floor + 0.5 = %f\n",
		data->wall.distance_x, floor(data->wall.distance_x) + 0.5);
	printf(" distance y = %f, floor + 0.5 = %f\n",
		data->wall.distance_y, floor(data->wall.distance_y) + 0.5);
	
// fonctionne mais probeleme au niveau d un coin avec du vide derrierw
// if (data->wall.distance_x > 0.999 || data->wall.distance_x < 0.003)

	if ((data->wall.distance_x > floor(data->wall.distance_x) + 0.997
		|| data->wall.distance_x < 0.003))
	{
		// printf("its north or south\n");
		if (data->map.maze[x + 1][y]
			&& data->map.maze[x + 1][y] == 'G')
		{
			// printf("its the north !\n");
			data->render.actual_texture = &data->north;
		}
		if (data->map.maze[x - 1][y]
			&& data->map.maze[x - 1][y] == 'G'
			&& data->wall.distance_x < floor(data->wall.distance_x) + 0.5)
		{
			// printf("its the south !\n");
			data->render.actual_texture = &data->south;
		}
	}
	else
	{
		// printf("its east or weast\n");
		if (data->map.maze[x][y - 1]
			&& data->map.maze[x][y - 1] == 'G')
		{
			// printf("its the east !\n");
			data->render.actual_texture = &data->east;
		}
		if (data->map.maze[x][y + 1]
			&& data->map.maze[x][y + 1] == 'G')
		{
			// printf("its the weast !\n");
			data->render.actual_texture = &data->weast;
		}
	}
	

	// printf("wall coordonates x = %d, y = %d\n", x, y);
	// printf("map x + 1 = %c\n", data->map.maze[x + 1][y]);
	// printf("map y + 1 = %c\n", data->map.maze[x][y + 1]);

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
