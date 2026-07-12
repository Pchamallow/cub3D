/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 16:14:32 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/12 10:53:08 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"
#include "../../../lib/libft/libft.h"
#include "../../../lib/get_next_line/get_next_line.h"
#include <stdlib.h>


// V001
// //find a path to take all collectibles and exit
// void	find_path(t_data *data, int y, int x)
// {
// 	int	lines;
// 	int	columns;

// 	lines = data->map.lines;
// 	columns = data->map.columns;
// 	if (y < 0 || x < 0 || y >= lines || x >= columns
// 		|| data->map.maze[y][x] == '1' || data->map.maze[y][x] == 'N')
// 		// parcourir la map -> verifier s il y a plus d un au choix (N S, E  ou W)
// 		// autre choses que 0 1 ou \n mais que pour le bout de lignes
// 		return ;
// 	else
// 	{
// 		// if (data->map.maze[y][x] == 'C')
// 		// 	data->collect.value--;
// 		if (data->map.maze[y][x] == '\0'
// 			|| data->map.maze[y][x] == '\n')
// 			data->map.wall_missing++;
// 		data->map.maze[y][x] = 'N';
// 		find_path(data, y + 1, x);
// 		find_path(data, y - 1, x);
// 		find_path(data, y, x + 1);
// 		find_path(data, y, x - 1);
// 	}
// 	return ;
// }
		// if (data->map.maze[y][x] == 'C')
		// 	data->collect.value--;
		// if (data->map.maze[y][x] == '1')
		// {
		// 	int wall = 0;
		// 	if (data->map.maze[y + 1] && data->map.maze[y + 1][x]
		// 		&& data->map.maze[y + 1][x] == '1')
		// 		wall++;
		// 	if (data->map.maze[y - 1] && data->map.maze[y - 1][x]
		// 		&& data->map.maze[y - 1][x] == '1')
		// 		wall++;
		// 	if (data->map.maze[y] && data->map.maze[y][x + 1]
		// 		&& data->map.maze[y][x + 1] == '1')
		// 		wall++;
		// 	if (data->map.maze[y] && data->map.maze[y][x - 1]
		// 		&& data->map.maze[y][x - 1] == '1')
		// 		wall++;
		// 	if (wall < 2)
		// 		data->map.wall_missing++;
		// 	// ft_printf_fd(2, "wall is missing"); // a reformuler
		// 	// return ;
		// }

// V002
// int	find_path(t_data *data, int y, int x)
// {
// 	int	lines;
// 	// int	columns;

// 	lines = data->map.lines;
// 	// columns = data->map.columns;
// 	if (y < 0 || x < 0
// 		|| y >= lines
// 		|| x >= (int)ft_strlen(data->map.maze[y])
// 		|| is_whitespace(data->map.maze[y][x]))
// 		// parcourir la map -> verifier s il y a plus d un au choix (N S, E  ou W)
// 		// autre choses que 0 1 ou \n mais que pour le bout de lignes
// 	{
// 		data->map.wall_missing++;
// 		return (1);
// 	}
// 	else
// 	{
// 		if (data->map.maze[y][x] == '1'
// 			|| data->map.maze[y][x] == 'X')
// 			// && data->map.maze[y][x] != '0'
// 			// && data->map.maze[y][x] != 'N') // a remplacer par la lettre du player start
// 		{
// 			return (0);
// 		}
// 		data->map.maze[y][x] = 'X';
// 		if (find_path(data, y + 1, x))
// 			return (1);
// 		if (find_path(data, y - 1, x))
// 			return (1);
// 		if (find_path(data, y, x + 1))
// 			return (1);
// 		if (find_path(data, y, x - 1))
// 			return (1);
// 	}
// 	return (0);
// }


int	is_wall(t_map *map, int y, int x)
{
	if (y < 0 || y >= map->lines)
		return (0);
	if (x < 0 || x >= (int)ft_strlen(map->maze[y]))
		return (0);
	if (map->maze[y][x] == '1')
		return (1);
	return (0);
}

// V003
// trouver le 1er proche du start player comme point de depart
// -> serach for que des 0 entre le Player start et le wall = 1
// int	find_path(t_data *data, t_map *map, int y, int x)
// {
// 	// avancer vers la droite tant qu il y a un mur
// 	if (is_wall(map, y, x + 1))
// 	{
// 		map->maze[y][x + 1] = 'X';
// 		find_path(data, map, y, x + 1);
// 	}
// 	// bout de ligne, preferer le haut sinon bas
// 	else if (!map->maze[y][x + 1]
// 		|| map->maze[y][x + 1] == '\n')
// 	{
// 		// haut
// 		if (is_wall(map, y - 1, x))
// 		{
// 			map->maze[y - 1][x] = 'X';
// 			find_path(data, map, y - 1, x);
// 		}
// 		else if (is_wall(map, y + 1, x))
// 		{
// 			map->maze[y + 1][x] = 'X';
// 			find_path(data, map, y + 1, x);
// 		}
// 		// pas mur au dessus et rien en dessous
// 		else if (is_wall(map, y, x - 1))
// 		{
// 			map->maze[y][x - 1] = 'X';
// 			find_path(data, map, y, x - 1);
// 		}
// 	}
// 	else if (!is_wall(map, y, x + 1))
// 	{
// 		if (is_wall(map, y, x - 1))
// 		{
// 			map->maze[y][x - 1] = 'X';
// 			find_path(data, map, y, x - 1);
// 		}
// 		// else
// 		// 	data->map.wall_missing++;
// 	}
// 	// chercher pour chaque X de chaque ligne 
// 	else
// 	{

// 	}

	
// 	// 	data->map.wall_missing++;
// 	return (0);
// }


//V004
// 1. fill X les lignes
// 2. flodd fill sur X et non pas E

int	fill_spaces(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < data->map.lines)
	{
		while (x < (int)ft_strlen(data->map.maze[y]))
		{
			if (data->map.maze[y][x] == '1')
			{
				while (data->map.maze[y][x] == '1'
					&& x < (int)ft_strlen(data->map.maze[y]))
					x++;
			}
			if (is_whitespace(data->map.maze[y][x]))
				data->map.maze[y][x] = 'X';
			x++;
		}
		y++;
	}
	return (0);
}

int	check_walls(t_data *data)
{
	int		y;
	int		x;

	y = data->player.y_start_p;
	x = data->player.x_start_p;
	
	fill_spaces(data);
	// get_first_wall(&data->map, &y, &x);
	// find_path(data, &data->map, 0, 2);
	// if (data->map.maze[0][2] == '1')
		// ft_display_error("At leats one brick is missing");
	// if (!(game->collect.value <= 0 && game->exit.value <= 0))
	// {
	// 	free_maze(game, maze);
	// 	return (1);
	// }
	// game->collect.value = j;
	// free_maze(game, maze);
	return (0);
}

int	is_player_start(t_data *data)
{
	int	y;
	int	x;

	y = 0;
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
				printf("[DEBUG] player = %d %d\n", data->player.x_start_p, data->player.y_start_p);
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}
