/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 16:14:22 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/07/23 14:56:06 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../lib/minilibx-linux/mlx.h"
#include "../../lib/libft/libft.h"

int	handle_keypress(int keycode, void *param)
{
	t_data	*data;
	
	data = (t_data *)param;
	if (keycode == ESC)
		close_esc(keycode, data);
	if (keycode == 'w')
		data->key.w = 1;
	else if (keycode == 's')
		data->key.s = 1;
	else if (keycode == 'a')
		data->key.a = 1;
	else if (keycode == 'd')
		data->key.d = 1;
	if (keycode == ARROW_LEFT)
		rotate_player(data, 1);
	if (keycode == ARROW_RIGHT)
		rotate_player(data, 0);
	return (0);
}

int	handle_keyrelease(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	(void)keycode;
	data->key.w = 0;
	data->key.s = 0;
	data->key.a = 0;
	data->key.d = 0;
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
