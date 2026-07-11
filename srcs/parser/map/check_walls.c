/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 16:14:32 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/11 16:55:20 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"
#include "../../../lib/libft/libft.h"
#include "../../../lib/get_next_line/get_next_line.h"
#include <stdlib.h>



// //find a path to take all collectibles and exit
// void	find_path(t_data *game, t_map *map, int y, int x)
// {
// 	int	lines;
// 	int	columns;

// 	lines = game->map.lines;
// 	columns = game->map.columns;
// 	if (y < 0 || x < 0 || y >= lines || x >= columns
// 		|| map->maze_map[y][x] == '1' || map->maze_map[y][x] == 'N')
// 		// parcourir la map -> verifier s il y a plus d un au choix (N S, E  ou W)
// 		// autre choses que 0 1 ou \n mais que pour le bout de lignes
// 		return ;
// 	else
// 	{
// 		// if (map->maze_map[y][x] == 'C')
// 		// 	game->collect.value--;
// 		// if (map->maze_map[y][x] == 'E')
// 		// 	game->exit.value--;
// 		map->maze_map[y][x] = 'N';
// 		find_path(game, map, y + 1, x);
// 		find_path(game, map, y - 1, x);
// 		find_path(game, map, y, x + 1);
// 		find_path(game, map, y, x - 1);
// 	}
// 	return ;
// }



int	init_player(t_data *data)// remplacer par data et renommer les variables
{
	int	y;
	int	x;

	y = 0;
	// player->moves = 0;
	while (data->map.maze[y])
	{
		x = 0;
		while (data->map.maze[y][x])
		{
			if (data->map.maze[y][x] == 'N'
				|| data->map.maze[y][x] == 'S'
				|| data->map.maze[y][x] == 'E'
				|| data->map.maze[y][x] == 'W')
			{
				data->player.x_start_p = x;
				data->player.y_start_p = y;
				data->player.pos_x = data->player.x_start_p;
				data->player.pos_y = data->player.y_start_p;
				// printf("%c %c\n", data->player.x_start_p, data->player.y_start_p);
				return (0);
			}
			x++;
		}
		y++;
	}
	// no player  start finded 
	// print error message
	return (1);
}

int	check_walls(t_data *data)
{
	int		y;
	int		x;

	// print_maze(data);
	y = data->player.y_start_p;
	x = data->player.x_start_p;
	// find_path(data, &data->map, y, x);
	// if (!(game->collect.value <= 0 && game->exit.value <= 0))
	// {
	// 	free_maze(game, maze);
	// 	return (1);
	// }
	// game->collect.value = j;
	// free_maze(game, maze);
	return (0);
}
