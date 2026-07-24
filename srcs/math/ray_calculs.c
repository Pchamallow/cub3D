/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_calculs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 10:10:59 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/24 12:53:18 by pswirgie         ###   ########.fr       */
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
	double x = 0;
	double y = 0;

	x = (wallx - (double)data->player.pos_y);
	x = x * x;

	y = (wally - (double)data->player.pos_x);
	y = y * y;
	
	double distance = sqrt(x + y);
	// printf("distance player wall = %f\n", distance);
	return (distance);
}

/*
* Use sin and cos in to calcul coordinates
*/
double	reach_wall(t_data *data)
{
	// t_player *player = &data->player;

	// double len = player->dir_x + player->dir_y;
	// double dirx_norm = data->render.ray_dir_x / len;
	// double diry_norm = data->render.ray_dir_y / len;
	// if (diry_norm)
	// printf("len = %f | dirX_norm = %f | dirY_norm = %f\n", len, dirx_norm, diry_norm);
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
		wallx = playerx + data->render.ray_dir_x * t;
		wally = playery + data->render.ray_dir_y * t;
		// printf("wallx = %f, wally = %f"
		// 	" , playerx = %f playery = %f, dirx_norm = %f"
		// 	" diry_norm = %f, t = %f\n",
		// 	wallx, wally, playerx, playery, dirx_norm, diry_norm, t);
		// t++;
		x = wallx;
		y = wally;
		t += 0.003;
	}
	data->render.wall_x = wallx;
	data->render.wall_y = wally;
	// printf("its a wall ! : wallx =  %f, wally = %f\n", 
	// 	wallx, wally);
	
	double dis = distance(data, wallx, wally);
		// correction fish eye -> les rayons envoyer au extremite du FOV sont plus
	// longs que ceux du milieu
	// -> on faire en sorte qu ils soient tous a la meme longeur que ceux du milieu
	dis = dis * cos(data->render.ray_dir - data->player.dirp);
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
	if (data->player.right || data->player.left)
		return;
	init_direction(data);
}
