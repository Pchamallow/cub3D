/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_calculs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 10:10:59 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/17 15:01:31 by pswirgie         ###   ########.fr       */
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
double	distance(t_data *data, double wallx, double wally)
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

	x = (wallx - (double)data->player.pos_y);
	x = x * x;

	y = (wally - (double)data->player.pos_x);
	y = y * y;
	
	double distance = sqrt(x + y);
	printf("distance player wall = %f\n", distance);
	return (distance);
}

/* 1 = right, 2 = left
*/
void	rotate_player(t_data *data, int side)
{
	// double rotSpeed = 45;
	// if (side == 1)
	// {
	// 	double oldDirX = data->player.dir_x;
	// 	data->player.dir_x = data->player.dir_x * cos(-rotSpeed) - data->player.dir_y * sin(rotSpeed);
	// 	data->player.dir_y = oldDirX * sin(-rotSpeed) + data->player.dir_y * cos(rotSpeed);
	// 	// double oldPlaneX = planeX;
	// 	// planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
	// 	// planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
	// }
	// else
	// {
	// 	double oldDirX = data->player.dir_x;
	// 	data->player.dir_x = data->player.dir_x * cos(rotSpeed) - data->player.dir_y * sin(rotSpeed);
	// 	data->player.dir_y = oldDirX * sin(rotSpeed) + data->player.dir_y * cos(rotSpeed);
	// }
	if (side == 1)
	{
		data->player.right = 1;
		data->player.dirp += 0.1;
	}
	else
	{
		data->player.left = 1;
		data->player.dirp -= 0.1;
	}

	// eviter les limites en negatif et positif ,rester dans un meme cercle complet
	if (data->player.dirp > 2 * PI)
		data->player.dirp = 0;
	else if (data->player.dirp < 0)
		data->player.dirp = 2 * PI;

	data->player.dir_x = cos(data->player.dirp);
	data->player.dir_y = sin(data->player.dirp);
	printf("dirx = %f, diry = %f\n", data->player.dir_x, data->player.dir_y);
}

/*
* Use sin and cos in to calcul coordinates
*/
double	reach_wall(t_data *data)
{
	t_player *player = &data->player;

	// printf("dirx = %f, diry = %f\n", player->dir_x, player->dir_y);
	double len = sqrt(pow(player->dir_x, 2.0) + pow(player->dir_y, 2.0)) ;
	double dirx_norm = data->render.ray_dir_x / len;
	double diry_norm = data->render.ray_dir_y / len;
	
	// invert
	double playerx = data->player.pos_y;
	double playery = data->player.pos_x;
	double	t = 0;
	double wallx = playerx;
	double wally = playery;
	// ft_printf_fd(2, "wallx = %d\n wally = %d\n", data->player.pos_y,
	// 	data->player.pos_x);
	// printf("data->map.maze[(int)wallx][(int)wally] = %c\n", data->map.maze[ data->player.pos_y][ data->player.pos_x]);
	int x = wallx;
	int y = wally;
	while (data->map.maze[x][y]
			&& data->map.maze[x][y] != '1')
	{
		wallx = playerx + dirx_norm * t;
		wally = playery + diry_norm * t;
		// printf("wallx = %f, wally = %f"
		// 	" , playerx = %f playery = %f, dirx_norm = %f"
		// 	" diry_norm = %f, t = %f\n",
		// 	wallx, wally, playerx, playery, dirx_norm, diry_norm, t);
		// t++;
		x = wallx;
		y = wally;
		t += 0.01;
	}
	data->render.wall_x = wallx;
	data->render.wall_y = wally;
	// printf("its a wall ! : wallx =  %f, wally = %f\n", 
	// 	wallx, wally);
	
	double dis = distance(data, wallx, wally);
		// correction fish eye -> les rayons envoyer au extremite du FOV sont plus
	// longs que ceux du milieu
	// -> on faire en sorte qu ils soient tous a la meme longeur que ceux du milieu
	// dis = dis * cos(data->render.ray_dir);
	return (dis);
}



/*
* Direction : h_wall
* Est = 0, West =  PI, North = 1.5 PI, South = 0.5 PI
*		- number choosen by position on circule
* User sin and cos to have x and y from dirp point
*/
void	ray_orientation(t_data *data)
{
	// start position



	// orientation rayon 

	// if (is_rotate(data))
	// 	return ;

	if (data->player.right || data->player.left)
	{
		return;
	}
	init_direction(data);
}
