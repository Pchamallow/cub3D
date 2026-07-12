/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 16:14:22 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/07/11 16:33:01 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../lib/minilibx-linux/mlx.h"

void	ft_init_hooks(t_data *data)
{
	mlx_key_hook(data->win, handle_keypress, data);
	mlx_hook(data->win, 17, 0, close_window, data);
}

int	handle_keypress(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	close_esc(keycode, data);
	return (0);
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