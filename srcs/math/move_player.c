/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 13:20:06 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/14 13:27:07 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// static int	can_move(t_data *data, int x, int y)
// {
// 	if (data->map.maze[y][x] == '1')
// 		return (0);
// 	return (1);
// }

// voir lorsque le player bouge un changement de couleur 
void	move_player(t_data *data, int dx, int dy)
{
	int		new_x;
	int		new_y;

	new_x = data->player.pos_x + dx;
	new_y = data->player.pos_y + dy;
	if (data->map.maze[new_y][new_x] != '1')
	{
		data->player.pos_x  = new_x;
		data->player.pos_y = new_y;
	}
}
