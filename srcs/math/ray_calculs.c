/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_calculs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 10:10:59 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/16 14:38:57 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../include/macro.h"
#include "../../lib/minilibx-linux/mlx.h"
#include "../../lib/libft/libft.h"
#include <math.h>
#include <stdint.h>
#include <stdio.h>

// distance between player and the wall
double	distance(t_data *data, int	wallx, int wally)
{
	// printf("(double)data->player.pos_x %f,"
	// 	" (double)data->player.pos_y = %f\n",
	// 	(double)data->player.pos_x, (double)data->player.pos_y);
	
	// if (data->player.pos_y > wallx)
	// 	printf("sqrt x %f", sqrt(((double)data->player.pos_y - wallx)));
	// if (data->player.pos_x > wally)
	// 	printf("sqrt y %f", sqrt(((double)data->player.pos_x - wally)));

	double x = 0;
	double y = 0;

	if (data->player.pos_y > wallx)
		x = ((double)data->player.pos_y - wallx);
	else
		x = (wallx - (double)data->player.pos_y);

	if (data->player.pos_x > wally)
		y = ((double)data->player.pos_x - wally);
	else
		y = (wally - (double)data->player.pos_x);
	
	double distance = sqrt(x + y);
	printf("distance player wall = %f\n", distance);
	return (distance);
}

/*
* Use sin and cos in to calcul coordinates
8 
*/
double	reach_wall(t_data *data)
{
	t_render *render = &data->render;

	double len = sqrt(pow(render->dirx, 2) + pow(render->diry, 2)) ;
	double dirx_norm = render->dirx / len;
	double diry_norm = render->diry / len;
	
	// invert
	double playerx = data->player.pos_y;
	double playery = data->player.pos_x;
	int	t = 0;
	double wallx = playerx;
	double wally = playery;
	// ft_printf_fd(2, "wallx = %d\n wally = %d\n", data->player.pos_y,
	// 	data->player.pos_x);
	// printf("data->map.maze[(int)wallx][(int)wally] = %c\n", data->map.maze[ data->player.pos_y][ data->player.pos_x]);
		 
	while (data->map.maze[(int)wallx][(int)wally]
			&& data->map.maze[(int)wallx][(int)wally] != '1')
	{
		printf("wallx = %f, wally = %f\n", wallx, wally);
		wallx = playerx + dirx_norm * t;
		wally = playery + diry_norm * t;
		t++;
	}
	printf("its a wall ! : wallx =  %f, wally = %f\n", 
		wallx, wally);
		
	// // pour le nord
	// double dirx = 1;
	// double diry = 0;

	// double 
	
	double dis = distance(data, wallx, wally);
	return (dis);
}

/*
* Direction : h_wall
* Est = 0, West =  pie, North = 1.5 pie, South = 0.5 pie
*		- number choosen by position on circule
* User sin and cos to have x and y from dirp point
*/
void	ray_orientation(t_data *data)
{
	// start position

	(void)data;
	char dir = 'N';
	double dirp = 0;

	// orientation rayon 
	if (dir == 'N')
	{
		dirp = 1.5 * PIE;
		data->render.dirx = sin(dirp);
		data->render.diry = cos(dirp);
	}
	else if (dir == 'S')
	{
		dirp = 0.5 * PIE;
		data->render.dirx = -sin(dirp);
		data->render.diry = cos(dirp);
	}
	else if (dir == 'W')
	{
		dirp = PIE;
		data->render.dirx = sin(dirp);
		data->render.diry = -cos(dirp);
	}
	else if (dir == 'E')
	{
		dirp = 2 * PIE;
		data->render.dirx = sin(dirp);
		data->render.diry = cos(dirp);
	}
	data->render.dirp = dirp;
}
