/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 16:14:32 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/11 16:31:30 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"
#include <stdlib.h>
#include "../../../lib/get_next_line/get_next_line.h"
#include "../../../lib/libft/libft.h"

static int	is_whitespace(char c)
{
	if (c == ' ' || (c >= '\t' && c <= '\r'))
		return (1);
	return (0);
}

static int	str_iswhitespaces(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (!is_whitespace(s[i]))
			return (0);
		i++;
	}
	return (1);
}

// //find a path to take all collectibles and exit
void	find_path(t_data *game, t_map *map, int y, int x)
{
	int	lines;
	int	columns;

	lines = game->map.lines;
	columns = game->map.columns;
	if (y < 0 || x < 0 || y >= lines || x >= columns
		|| map->maze_map[y][x] == '1' || map->maze_map[y][x] == 'N')
		// parcourir la map -> verifier s il y a plus d un au choix
		// (N S, E  ou W)
		// autre choses que 0 1 ou \n mais que pour le bout de lignes
		return ;
	else
	{
		// if (map->maze_map[y][x] == 'C')
		// 	game->collect.value--;
		// if (map->maze_map[y][x] == 'E')
		// 	game->exit.value--;
		map->maze_map[y][x] = 'N';
		find_path(game, map, y + 1, x);
		find_path(game, map, y - 1, x);
		find_path(game, map, y, x + 1);
		find_path(game, map, y, x - 1);
	}
	return ;
}

static	void init_maze(t_data *data)
{
	int		i;
	int		j;

	j = 0;
	int index_apres_les_args = 8; // a remplacer
	i = index_apres_les_args; // remplacer

	int lines = data->map.lines - index_apres_les_args;
	if (lines <= 0)
		return ; // error :  pas de map
	//
	data->map.maze_map = (char **)malloc((sizeof(char *)) * (lines + 1));
	// if (!data->map.maze_map)
	// 	print_error_free(game, "Error\nMalloc failed.\n", 2);
	fill_null(data->map.maze_map, lines);
	while (data->map.full_map[i] && !str_iswhitespaces(data->map.full_map[i]))
	{
		data->map.maze_map[j] = (char *)malloc((sizeof(char))
				* (data->map.columns + 1));
		// remettre securite
		// if (!data->map.maze_map[i])
		// {
		// 	free_data->map.maze_map(data, data->map.maze_map);
		// 	print_error_free(data, "Error\nMalloc failed.\n", 2);
		// exit
		// }
		ft_bzero(data->map.maze_map[j], data->map.columns);
		ft_strlcpy(data->map.maze_map[j], (const char *)data->map.full_map[i],
			(data->map.columns + 1));
		i++;
		j++;
	}
	return ;
}

int	init_player(t_data *data)// remplacer par data et renommer les variables
{
	int	y;
	int	x;

	y = 0;
	// player->moves = 0;
	while (data->map.maze_map[y])
	{
		x = 0;
		while (data->map.maze_map[y][x])
		{
			if (data->map.maze_map[y][x] == 'N'
				|| data->map.maze_map[y][x] == 'S'
				|| data->map.maze_map[y][x] == 'E'
				|| data->map.maze_map[y][x] == 'W')
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

	init_maze(data);
	print_maze(data);
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
