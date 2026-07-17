/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 16:14:22 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/07/17 09:49:19 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../lib/minilibx-linux/mlx.h"
#include "../../lib/libft/libft.h"

// en pause, d abord avoir le move player pour voir si ca marche
// static int	key_press(int keycode, t_data *data)
// {
// 	if (keycode == ESC)
// 		close_esc(keycode, data);
// 	if (keycode == KEY_W)
// 		data->key.w = 1;
// }

int	handle_keypress(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == ESC)
		close_esc(keycode, data);
	if (keycode == 'w')
		move_player(data, 0, -1);
	if (keycode == 's')
		move_player(data, 0, 1);
	if (keycode == 'a')
		move_player(data, -1, 0);
	if (keycode == 'd')
		move_player(data, 1, 0);
	if (keycode == ARROW_LEFT)
		data->player.left = 1;
	if (keycode == ARROW_RIGHT)
		data->player.left = 1;
	refresh_map(data);
	return (0);
}

void	ft_init_hooks(t_data *data)
{
	mlx_key_hook(data->win, handle_keypress, data);
	// mlx_hook(data->win, 2, 1, key_press, data);
	mlx_hook(data->win, 17, 0, close_window, data);
}

// 	// if (keycode == KEY_W || keycode == ARROW_UP)
	// 	move_player(data, -1, 0);
	// if (keycode == KEY_S || keycode == ARROW_DOWN)
	// 	move_player(data, 1, 0);
	// if (keycode == KEY_A || keycode == ARROW_LEFT)
	// {
	// 	data->player.direction = LEFT;
	// 	move_player(data, 0, -1);
	// }
	// if (keycode == KEY_D || keycode == ARROW_RIGHT)
	// {
	// 	data->player.direction = RIGHT;
	// 	move_player(data, 0, 1);
	// }