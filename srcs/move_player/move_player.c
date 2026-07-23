/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 14:50:49 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/23 14:56:08 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include <math.h>

void	move_player(t_data *data, double x, double y)
{
	int	new_x;
	int	new_y;

	new_x = (int)x;
	new_y = (int)y;
	// maze_x = new_y;
	// maze_x = new_y;
	// printf(" move new pos -> x = %d, y = %d\n", new_x, new_y);
	if (data->map.maze[new_y]
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
		x = data->player.pos_x + data->player.dir_y;
		y = data->player.pos_y + data->player.dir_x;
		move_player(data, x, y);
	}
	if (data->key.s)
	{
		x = data->player.pos_x - data->player.dir_y;
		y = data->player.pos_y - data->player.dir_x;
		move_player(data, x, y);
	}
}

void	move_left_right(t_data *data)
{
	double	x;
	double	y;

	if (data->key.a)
	{
		x = data->player.pos_x + sin(data->player.dirp + PI/2);
		y = data->player.pos_y + cos(data->player.dirp + PI/2);
		move_player(data, x, y);
	}
	if (data->key.d)
	{
		// printf(" pos before w -> avancer :   x = %f, y = %f\n", data->player.pos_x , data->player.pos_y);
		x = data->player.pos_x - sin(data->player.dirp + PI/2);
		y = data->player.pos_y - cos(data->player.dirp + PI/2);
		// printf("calculs:   cos = %f, sin = %f\n", cos(data->player.dirp + PI/2),
		//  sin(data->player.dirp + PI/2));
		// printf(" pos after w -> avancer :   x = %f, y = %f\n", x, y);
		// printf("dirx = %f | diry = %f\n", data->player.dir_x, data->player.dir_y);
		move_player(data, x, y);
	}
}
