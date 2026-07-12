/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 16:14:32 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/12 17:04:19 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"
#include "../../../lib/libft/libft.h"
#include "../../../lib/get_next_line/get_next_line.h"
#include <stdlib.h>

void	find_path(t_data *data, int y, int x)
{
	int	lines;
	int	columns;

	lines = data->map.lines;
	columns = data->map.columns;
	if (y < 0 || x < 0 || y >= lines || x >= columns
		|| data->map.maze[y][x] == '1'
		|| data->map.maze[y][x] == 'G')
		return ;
	else
	{
		if (data->map.maze[y][x] == 'X')
			data->map.wall_missing++;
		data->map.maze[y][x] = 'G';
		find_path(data, y + 1, x);
		find_path(data, y - 1, x);
		find_path(data, y, x + 1);
		find_path(data, y, x - 1);
	}
	return ;
}

int	check_walls(t_data *data)
{
	int		y;
	int		x;

	y = data->player.y_start_p;
	x = data->player.x_start_p;

	find_path(data, y, x);
	if (data->map.wall_missing)
	{
		ft_display_error("At least one wall is missing");
		return (1);
	}
	return (0);
}

// int	is_player_start(t_data *data)
// {
// 	int	y;
// 	int	x;

// 	y = 0;
// 	while (data->map.maze[y])
// 	{
// 		x = 0;
// 		while (data->map.maze[y][x])
// 		{
// 			if (data->map.maze[y][x] == 'N'
// 				|| data->map.maze[y][x] == 'S'
// 				|| data->map.maze[y][x] == 'E'
// 				|| data->map.maze[y][x] == 'W')
// 			{
// 				data->player.x_start_p = x;
// 				data->player.y_start_p = y;
// 				data->player.pos_x = data->player.x_start_p;
// 				data->player.pos_y = data->player.y_start_p;
// 				return (1);
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// 	return (0);
// }
