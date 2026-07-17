/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_calculs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 10:10:59 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/17 10:06:37 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../include/macro.h"
#include "../../lib/minilibx-linux/mlx.h"
#include "../../lib/libft/libft.h"
#include <math.h>
#include <stdint.h>
#include <stdio.h>

// VERSION AVEC PLANE
// static void rotate_player(t_data *data, double rot_speed)
// {
// 	double old_dir_x = data->player.dir_x;
// 	data->player.dir_x = data->player.dir_x * cos(rot_speed) - data->player.dir_y * sin(rot_speed);
// 	data->player.dir_y = old_dir_x * sin(rot_speed) + data->player.dir_y * cos(rot_speed);

// 	double old_plane_x = data->player.plane_x;
// 	data->player.plane_x = data->player.plane_x * cos(rot_speed) - data->player.plane_y * sin(rot_speed);
// 	data->player.plane_y = old_plane_x * sin(rot_speed) + data->player.plane_y * cos(rot_speed);
// }

static void rotate_player(t_data *data, double rot_speed)
{
	(void) rot_speed;
	if (data->player.dirp < 0)
		data->player.dirp += 2 * PI;
	if (data->player.dirp >= 2 * PI)
		data->player.dirp -= 2 * PI;
}

static int	is_rotate(t_data *data)
{
	if (data->player.right || data->player.left)
	{
		int delta = 5;
		double rot_speed = 2.0 * delta; 
		if (data->player.right)
			rotate_player(data, rot_speed);
		if (data->player.left)
			rotate_player(data, -rot_speed);
		return (1);
	}
	return (0);
}

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
	t_player *player = &data->player;

	double len = sqrt(pow(player->dir_x, 2) + pow(player->dir_y, 2)) ;
	double dirx_norm = player->dir_x / len;
	double diry_norm = player->dir_y / len;
	
	// invert
	double playerx = data->player.pos_y;
	double playery = data->player.pos_x;
	double	t = 0;
	double wallx = playerx;
	double wally = playery;
	// ft_printf_fd(2, "wallx = %d\n wally = %d\n", data->player.pos_y,
	// 	data->player.pos_x);
	// printf("data->map.maze[(int)wallx][(int)wally] = %c\n", data->map.maze[ data->player.pos_y][ data->player.pos_x]);
		 
	while (data->map.maze[(int)wallx][(int)wally]
			&& data->map.maze[(int)wallx][(int)wally] != '1')
	{
		wallx = playerx + dirx_norm * t;
		wally = playery + diry_norm * t;
		// printf("wallx = %f, wally = %f"
		// 	" , playerx = %f playery = %f, dirx_norm = %f"
		// 	" diry_norm = %f, t = %f\n",
		// 	wallx, wally, playerx, playery, dirx_norm, diry_norm, t);
		// t += 0.1;
		t++;
	}
	// printf("its a wall ! : wallx =  %f, wally = %f\n", 
	// 	wallx, wally);
	
	double dis = distance(data, wallx, wally);
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

	(void)data;
	char dir = 'N';
	double dirp = 0;

	// orientation rayon 

	data->player.plane_x = 0.66;
	data->player.plane_x = 0;

	if (is_rotate(data))
		return ;
	
	if (dir == 'N')
	{
		dirp = 1.5 * PI;
		data->player.dir_x = sin(dirp);
		data->player.dir_y = cos(dirp);
	}
	else if (dir == 'S')
	{
		dirp = 0.5 * PI;
		data->player.dir_x = sin(dirp);
		data->player.dir_y = cos(dirp);
	}
	else if (dir == 'W')
	{
		dirp = 0;
		data->player.dir_x = sin(dirp);
		data->player.dir_y = cos(dirp);
	}
	else if (dir == 'E')
	{
		dirp = PI;
		data->player.dir_x = sin(dirp);
		data->player.dir_y = cos(dirp);
	}
	data->player.dirp = dirp;
}
