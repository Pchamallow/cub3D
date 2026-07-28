/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_direction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 10:49:30 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/28 13:38:38 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../include/macro.h"
#include <math.h>
#include <stdio.h>

// fix pour retrirer les colonnes de nords en plein
// milieu des murs en direction des cotes
static int	on_side(t_data *data)
{
	int map_x = data->wall.map_x;
	int map_y = data->wall.map_y;
	double floor_x = floor(data->wall.distance_x);
	// double floor_y = floor(data->wall.distance_y);

	// printf(" distance x = %f, floor + 0.5 = %f,  floor + 1 = %f\n",
	// 	data->wall.distance_x, floor_x + 0.5, floor_x + 1);
	// printf("wall map x = %d - wall map y = %d\n",
	// 	data->wall.map_x, data->wall.map_y);

	// si il y a des murs au dessus et en dessous 
	// on est sur un coté
	if (data->map.maze[map_x + 1][map_y]
		&& data->map.maze[map_x + 1][map_y] == '1'
		&& data->map.maze[map_x - 1][map_y]
		&& data->map.maze[map_x - 1][map_y] == '1')
		return (1);
	// par rapport a la position actuelle disons x = entre 10.0 et 10.9
	// s il y a un mur au dessus, entre 9.1 et 10 .9
	// c est un side c est sur
	if (data->map.maze[map_x - 1][map_y]
		&& data->map.maze[map_x - 1][map_y] == '1'
		&& data->wall.distance_x > floor_x - 0.9
		&& data->wall.distance_x < floor_x + 0.9)
		return (1);
	// else if 
	return (0);
}

// si y = y.9 -> floor y + 1 == '1' -> west


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
	
	double floor_x = floor(data->wall.distance_x);
	double floor_y = floor(data->wall.distance_y);

	// int map_x = data->wall.map_x;
	// int map_y = data->wall.map_y;


	data->render.actual_texture = &data->east;

	
// fonctionne mais probeleme au niveau d un coin avec du vide derrierw
// if (data->wall.distance_x > 0.999 || data->wall.distance_x < 0.003)

// idealement ne pas print des le depart sur le cote west
// + print le west sur cette partie 
// dans quel contexte on print l est 

// position actuel =    x = 5.9   y = 4
// si floor x + 1 -> la case a cote est un G -> alors c est bien west
	printf(" distance x = %f, floor + 0.5 = %f,  floor + 1 = %f\n",
		data->wall.distance_x, floor_x + 0.5, floor_x + 1);
	printf(" distance y = %f, floor + 0.5 = %f, floor + 1 = %f\n",
		data->wall.distance_y, floor_y + 0.5, floor_y + 1);
	printf("wall map x = %d - wall map y = %d\n",
		data->wall.map_x, data->wall.map_y);

	if ((data->wall.distance_x > floor_x + 0.997
		|| data->wall.distance_x < 0.003)
		&& !on_side(data))
	{
	
		printf("its north or south\n");
		// printf("wall map x = %d - wall map y = %d\n",
		// 	data->wall.map_x, data->wall.map_y);
		if (data->map.maze[x + 1][y]
			&& data->map.maze[x + 1][y] == 'G')
		{
			// printf("its the north !\n");
			data->render.actual_texture = &data->north;
		}
		if (data->map.maze[x - 1][y]
			&& data->map.maze[x - 1][y] == 'G'
			&& data->wall.distance_x < floor_x + 0.5)
		{
			// printf("its the south !\n");
			data->render.actual_texture = &data->south;
		}
		return ;
	}
	else
	{
		// if (data->map.maze[x + 1][map_y] == 'G'
		// 	&& data->wall.distance_y > floor_y + 0.9)
		// printf("its east or weast\n");
		// if (data->map.maze[x][y - 1]
		// 	&& data->map.maze[x][y - 1] == 'G')
		// {
		// 	// printf("its the east !\n");
		// 	data->render.actual_texture = &data->east;
		// }
		if (data->map.maze[x][y + 1]
			&& data->map.maze[x][y + 1] == 'G'
			&& data->wall.distance_y > floor_y + 0.9)
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
