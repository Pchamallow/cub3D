/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_direction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 10:49:30 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/28 15:02:43 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../include/macro.h"
#include <math.h>
#include <stdio.h>

/*
* Function to fix the columns with the wrong texture,
* which appear in the middle of west-facing walls.
* We always start from the position of the wall hit by the ray.
*
* Case 1:
*	- if there is a wall above AND below our current cell
*		= we are on a side face
*
* Case 2: bottom corner of a wall section
*	- if there is a wall above us
*	- and we are within the interval between the current wall
*	  and the wall above (e.g. we are at x = 10.5, min = 9.1,
*	  max = 10.9)
*		= we are on a side face
*
* Case 3: top corner of a wall section
*	- if there is a wall below us
*	- and we are within the interval between the current wall
*	  and the wall below (e.g. we are at x = 10.5, min = 10.1,
*	  max = 11.9)
*		= we are on a side face
*/
static int	on_side(t_data *data)
{
	int map_x = data->wall.map_x;
	int map_y = data->wall.map_y;
	double floor_x = floor(data->wall.distance_x);

	if (data->map.maze[map_x + 1][map_y]
		&& data->map.maze[map_x + 1][map_y] == '1'
		&& data->map.maze[map_x - 1][map_y]
		&& data->map.maze[map_x - 1][map_y] == '1')
		return (1);
	if (data->map.maze[map_x - 1][map_y]
		&& data->map.maze[map_x - 1][map_y] == '1'
		&& data->wall.distance_x > floor_x - 0.9
		&& data->wall.distance_x < floor_x + 0.9)
		return (1);
	if (data->map.maze[map_x + 1][map_y]
		&& data->map.maze[map_x + 1][map_y] == '1'
		&& data->wall.distance_x > floor_x + 0.1
		&& data->wall.distance_x < floor_x + 1.9)
		return (1);
	return (0);
}

/*
* Choose texture from wall direction
*/
void	get_dir_wall(t_data *data)
{
	int x = data->wall.map_x;
	int y = data->wall.map_y;
	double floor_x = floor(data->wall.distance_x);
	double floor_y = floor(data->wall.distance_y);

	data->render.actual_texture = &data->east;

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
