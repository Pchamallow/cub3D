/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 14:50:49 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/29 12:25:29 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include <math.h>
#include "stdio.h" // a suppr


void	rotate_player(t_data *data)
{
	t_player *player = &data->player;

	if (data->key.right)
	{
		data->player.has_turn = 1;
		double old_dir_x = player->dir_x;
		player->dir_x = player->dir_x * cos(-ROT_SPEED) - player->dir_y * sin(-ROT_SPEED);
		player->dir_y = old_dir_x * sin(-ROT_SPEED) + player->dir_y * cos(-ROT_SPEED);
		double oldPlaneX = data->render.plane_x;
		data->render.plane_x = data->render.plane_x * cos(-ROT_SPEED) - data->render.plane_y * sin(-ROT_SPEED);
		data->render.plane_y = oldPlaneX * sin(-ROT_SPEED) + data->render.plane_y * cos(-ROT_SPEED);
	}
	if (data->key.left)
	{
		data->player.has_turn = 1;
		double old_dir_x = player->dir_x;
		player->dir_x = player->dir_x * cos(ROT_SPEED) - player->dir_y * sin(ROT_SPEED);
		player->dir_y = old_dir_x * sin(ROT_SPEED) + player->dir_y * cos(ROT_SPEED);
		double oldPlaneX = data->render.plane_x;
		data->render.plane_x = data->render.plane_x * cos(ROT_SPEED) - data->render.plane_y * sin(ROT_SPEED);
		data->render.plane_y = oldPlaneX * sin(ROT_SPEED) + data->render.plane_y * cos(ROT_SPEED);
	}
		
}


void	move_player(t_data *data, double x, double y)
{
	int	new_x;
	int	new_y;

	new_x = (int)x;
	new_y = (int)y;
	// printf(" move new pos -> x = %d, y = %d\n", new_x, new_y);
	// if (data->map.maze[new_y]
	if ( new_x > 0 && new_y > 0
		&& new_x < data->map.columns && new_y < data->map.lines
		&& data->map.maze[new_y][new_x]
		&& data->map.maze[new_y][new_x] != '1'
		&& data->map.maze[new_y][new_x] != 'X')
	{
		// ft_printf_fd(2, "player moving\n");
		data->player.pos_x = x;
		data->player.pos_y = y;
	}
}

void	move_forward_backward(t_data *data)
{
	double	x;
	double	y;

	if (data->key.w)
	{
		x = data->player.pos_x + data->player.dir_y / MOVE_SPEED;
		y = data->player.pos_y + data->player.dir_x / MOVE_SPEED;
		move_player(data, x, y);
	}
	if (data->key.s)
	{
		x = data->player.pos_x - data->player.dir_y / MOVE_SPEED;
		y = data->player.pos_y - data->player.dir_x / MOVE_SPEED;
		move_player(data, x, y);
	}
}

void	move_left_right(t_data *data)
{
	double	x = 0;
	double	y = 0;

	double perp_x = data->player.dir_y;
	double perp_y = -data->player.dir_x;
	if (data->key.d)
	{
		x = data->player.pos_x + perp_y / (MOVE_SPEED * 2);
		y = data->player.pos_y + perp_x / (MOVE_SPEED * 2);
		move_player(data, x, y);
	}
	if (data->key.a)
	{
		x = data->player.pos_x - perp_y / (MOVE_SPEED * 2);
		y = data->player.pos_y - perp_x / (MOVE_SPEED * 2);
		move_player(data, x, y);
	}
}
