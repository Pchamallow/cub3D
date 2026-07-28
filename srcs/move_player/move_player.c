/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 14:50:49 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/28 14:03:04 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include <math.h>
#include "stdio.h" // a suppr

int	init_rotate_dirp(t_data *data)
{
	// printf("rotate choice -> data->key.right = %d\n", data->key.right);
	if (data->key.left)
	{
		data->player.left = 1;
		data->player.dirp += SPEED_ROT;
	}
	else if (data->key.right)
	{
		// printf("rotate right\n");
		data->player.right = 1;
		data->player.dirp -= SPEED_ROT;
	}
	else
		return (1);
	return (0);
}

/*
* Limit the number by refer to PI
*	-> avoid max limit and mini limit of number
*	when the number is > 2 * PI, we have done a complete circle
*	so we start at 0 + delta
* Delta
*	-> if we reset the number (limit by refer to PI),
*		we need to get the rest between the limit fixed and
*		the number above this limit
*		eg: number > 2 * PI
*			we need to get the range between 2 * PI -> number
*			else the player doesn t rotate
*/
void	rotate_player(t_data *data)
{
	double	delta;

	if (init_rotate_dirp(data))
		return ;
	if (data->player.dirp > 2.0 * PI)
	{
		delta = data->player.dirp - (2.0 * PI);
		data->player.dirp = 0.0 + delta;
	}
	else if (data->player.dirp < 0.0)
	{
		delta = data->player.dirp * -1.0;
		data->player.dirp = (2.0 * PI) - delta;
	}
	// printf("[DEBUG] rotate dirp = %f\n", data->player.dirp);
	data->player.dir_x = cos(data->player.dirp);
	data->player.dir_y = sin(data->player.dirp);
	// printf("[DEBUG] dirx = %f, diry = %f\n", data->player.dir_x, data->player.dir_y);
}

void	move_player(t_data *data, double x, double y)
{
	int	new_x;
	int	new_y;

	new_x = (int)x;
	new_y = (int)y;
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
		x = data->player.pos_x + data->player.dir_y / SPEED_MOVE;
		y = data->player.pos_y + data->player.dir_x / SPEED_MOVE;
		move_player(data, x, y);
	}
	if (data->key.s)
	{
		x = data->player.pos_x - data->player.dir_y / SPEED_MOVE;
		y = data->player.pos_y - data->player.dir_x / SPEED_MOVE;
		move_player(data, x, y);
	}
}

void	move_left_right(t_data *data)
{
	double	x;
	double	y;

	if (data->key.a)
	{
		x = data->player.pos_x + sin(data->player.dirp + PI / 2) / SPEED_MOVE;
		y = data->player.pos_y + cos(data->player.dirp + PI / 2) / SPEED_MOVE;
		move_player(data, x, y);
	}
	if (data->key.d)
	{
		// printf(" pos before w -> avancer :   x = %f, y = %f\n", data->player.pos_x , data->player.pos_y);
		x = data->player.pos_x - sin(data->player.dirp + PI / 2) / SPEED_MOVE;
		y = data->player.pos_y - cos(data->player.dirp + PI / 2) / SPEED_MOVE;
		// printf("calculs:   cos = %f, sin = %f\n", cos(data->player.dirp + PI/2),
		//  sin(data->player.dirp + PI/2));
		// printf(" pos after w -> avancer :   x = %f, y = %f\n", x, y);
		// printf("dirx = %f | diry = %f\n", data->player.dir_x, data->player.dir_y);
		move_player(data, x, y);
	}
}
