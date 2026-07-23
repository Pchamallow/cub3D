/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 16:14:22 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/07/23 14:42:53 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../lib/minilibx-linux/mlx.h"
#include "../../lib/libft/libft.h"
#include <math.h>

void	move_forward_backward(t_data *data, int keycode)
{
	double	x;
	double	y;

	if (keycode == 'w')
	{
		data->key.w = 1;
		x = data->player.pos_x + data->player.dir_y;
		y = data->player.pos_y + data->player.dir_x;
		move_player(data, x, y);
	}
	if (keycode == 's')
	{
		x = data->player.pos_x - data->player.dir_y;
		y = data->player.pos_y - data->player.dir_x;
		move_player(data, x, y);
	}
}

void	move_left_right(t_data *data, int keycode)
{
	double	x;
	double	y;

	if (keycode == 'a')
	{
		x = data->player.pos_x + sin(data->player.dirp + PI/2);
		y = data->player.pos_y + cos(data->player.dirp + PI/2);
		move_player(data, x, y);
	}
	if (keycode == 'd')
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

int	handle_keypress(int keycode, void *param)
{
	t_data	*data;
	
	data = (t_data *)param;
	if (keycode == ESC)
		close_esc(keycode, data);
	if (keycode == 'w' || keycode == 's')
		move_forward_backward(data, keycode);
	if (keycode == 'a' || keycode == 'd')
		move_left_right(data, keycode);
	if (keycode == ARROW_LEFT)
		rotate_player(data, 1);
	if (keycode == ARROW_RIGHT)
		rotate_player(data, 0);
	// refresh_map(data);
	return (0);
}

int	handle_keyrelease(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	(void)keycode;
	data->key.w = 0;
	// if (keycode == ARROW_LEFT)
	// 	data->player.left = 0;
	// if (keycode == ARROW_RIGHT)
	// 	data->player.right = 0;
	return (0);
}

void	ft_init_hooks(t_data *data)
{
	mlx_hook(data->win, 2, 1L << 0, handle_keypress, data);
	mlx_hook(data->win, 3, 1L << 1, handle_keyrelease, data);
	mlx_hook(data->win, 17, 0, close_window, data);
	mlx_loop_hook(data->mlx, refresh_map, data);
}
