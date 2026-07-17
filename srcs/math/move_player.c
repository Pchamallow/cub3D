/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 13:20:06 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/17 11:30:23 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../lib/minilibx-linux/mlx.h"
#include "../../lib/libft/libft.h"

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
	// ft_printf_fd(2, "new pos player =  y : %d"
	// 	"  x : %d\n", new_y, new_x);
	if (data->map.maze[new_y]
		&& data->map.maze[new_y][new_x]
		&& data->map.maze[new_y][new_x] != '1')
	{
		// ft_printf_fd(2, "player moving\n");
		data->player.pos_x  = new_x;
		data->player.pos_y = new_y;
	}
}
