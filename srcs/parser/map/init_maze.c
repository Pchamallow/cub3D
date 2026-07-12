/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_maze.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 16:20:12 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/12 14:01:28 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"
#include "../../../lib/libft/libft.h"
#include "../../../lib/get_next_line/get_next_line.h"
#include <stdlib.h>

/*
*while not first one = X
*whitespace or empty = X
*/
static void	fill_x(t_map *map, int y, int len)
{
	int	i;

	i = 0;
	while (i < len && map->maze[y][i] != '1')
	{
		map->maze[y][i] = 'X';
		i++;
	}
	while (i < len)
	{
		if (is_whitespace(map->maze[y][i])
			|| map->maze[y][i] == '\0')
			map->maze[y][i] = 'X';
		i++;
	}
}

static int	init_fill_x(t_data *data, int y, int len)
{
	data->map.maze[y] = (char *)malloc((sizeof(char)) * data->map.columns + 1);
	if (!data->map.maze[y])
	{
		ft_display_error("Maze - content - allocation memory failed");
		free_all(data);
		return (1);
	}
	ft_bzero(data->map.maze[y], data->map.columns + 1);
	fill_x(&data->map, y, len);
	return (0);
}

static int is_invalid_player(t_data *data, int y)
{
	char	c;
	int		j;

	j = 0;
	while (data->map.full_file[y][j])
	{
		c = data->map.full_file[y][j];
		if (c == 'N' || c == 'S' || c == 'E'
			|| c == 'W')
		{
			data->map.start_count++;
			data->player.y_start_p = y - data->map.begin_maze;
			data->player.x_start_p = j + 1;
			// printf("[DEBUG] player = %d %d\n", data->player.x_start_p, data->player.y_start_p);
			if (data->map.start_count > 1)
			{
				ft_display_error("Too many player's start positions, needed only one");
				free_all(data);
				return (1);
			}
		}
		j++;
	}
	return (0);
}

static int is_invalid_chr(t_data *data, int y)
{
	char	c;
	int		j;

	j = 0;
	while (data->map.full_file[y][j])
	{
		c = data->map.full_file[y][j];
		if (c != '0' && c != '1' && c != ' '
			&& c != 'N' && c != 'S' && c != 'E'
			&& c != 'W')
		{
			ft_display_error("Invalid character: requiered only 0, 1, spaces and N/S/E/W");
			free_all(data);
			return (1);
		}
		j++;
	}
	return (0);
}

/*is_valid_line
* - is a line full of whitespaces
* - is not 0, 1, empty space, N, S, E or W
* - too many player's start position
*/
int is_valid_line(t_data *data, int i)
{
	if (str_iswhitespaces(data->map.full_file[i]))
		return (1);
	if (is_invalid_chr(data, i))
		return (1);
	if (is_invalid_player(data, i))
		return (1);
	return (0);
}

// les erreurs de longuerus de map et minimum sont a mettre icci
static int	init_maze_content(t_data *data, int after_args)
{
	int	i;
	int	j;

	i = after_args;
	j = 1;
	if (init_fill_x(data, 0, data->map.columns))
		return (1);
	while (data->map.full_file[i])
	{
		if (is_valid_line(data, i)) // tester securites
			return (1);
		data->map.maze[j] = (char *)malloc((sizeof(char))
				* data->map.columns + 2);
		if (!data->map.maze[j])
		{
			ft_display_error("Maze - content - allocation memory failed");
			free_all(data);
			return (1);
		}
		ft_bzero(data->map.maze[j], data->map.columns + 1);
		data->map.maze[j][0] = 'X';
		ft_strlcpy(&data->map.maze[j][1], (const char *)data->map.full_file[i],
			data->map.columns);
		fill_x(&data->map, j, data->map.columns);
		i++;
		j++;
	}
	if (init_fill_x(data, j, data->map.columns))
		return (1);
	return (0);
}
	
static int	init_maze_full(t_data *data, int after_args)
{
	data->map.maze = (char **)malloc((sizeof(char *)) * (data->map.lines + 3));
	if (!data->map.maze)
	{
		ft_display_error("Maze - full_file - allocation memory failed");
		free_all(data);
		return (1);
	}
	fill_null(data->map.maze, data->map.lines + 2);
	if (init_maze_content(data, after_args))
		return (1);
	return (0);
}

// est ce possible da voir des espaces avant les noms des args ?
static int	is_arg(char *str)
{
	if (!ft_strncmp(str, "NO", 2)
		|| !ft_strncmp(str, "SO", 2)
		|| !ft_strncmp(str, "WE", 2)
		|| !ft_strncmp(str, "EA", 2)
		|| !ft_strncmp(str, "F", 1)
		|| !ft_strncmp(str, "C", 1))
		return (1);
	return (0);
}

static int	get_index_after_args(t_data *data)
{
	int	i;

	i = 0;
	while (data->map.full_file[i])
	{
		if (!is_arg(data->map.full_file[i])
			&& !str_iswhitespaces(data->map.full_file[i]))
		{
			data->map.begin_maze = i;
			return (1);
		}
		i++;
	}
	ft_display_error("Map is missing");
	free_all(data);
	return (0);
}

static int	get_lines_maze(t_data *data, int end_args)
{
	int lines = data->map.lines - end_args;
	if (lines <= 0)
	{
		ft_display_error("No map found");
		free_all(data);
		return (1);
	}
	data->map.lines = lines;
	return (0);
}

// verifer s apres la maze s il y a du contenu, 
// lequel est autoriser
// index fin arg = faire une fonction get 1ere ligne avec au moins un 1
int init_maze(t_data *data)
{

	if (!get_index_after_args(data))
		return (1);
	if (get_lines_maze(data, data->map.begin_maze))
		return (1);
	ft_printf_fd(2, "[DEBUG]after_args %d l %d c %d\n", data->map.begin_maze, data->map.lines, data->map.columns);
	if (data->map.lines < 3 || data->map.columns < 3)
	{
		ft_display_error("Map is too small, have to be inbetween H3/W3 and H300/W300 (inclusive)");
		free_all(data);
		// revoir formulation ??
		return (1);
	}
	if (data->map.lines > 300 || data->map.columns > 300)
	{
		ft_display_error("Map is too big, have to be inbetween H3/W3 and H300/W300 (inclusive)");
		free_all(data);
		// revoir formulation ??
		return (1);
	}
	data->map.columns++;
	data->map.columns++;
	if (init_maze_full(data, data->map.begin_maze))
		return (1);
	return (0);
}
