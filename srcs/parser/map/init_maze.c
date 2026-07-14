/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_maze.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 16:20:12 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/14 11:45:18 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"
#include "../../../lib/libft/libft.h"
#include "../../../lib/get_next_line/get_next_line.h"
#include <stdlib.h>

static int	init_maze_full(t_data *data, int after_args)
{
	data->map.maze = (char **)malloc((sizeof(char *)) * (data->map.lines + 3));
	if (!data->map.maze)
	{
		ft_display_error("Maze - full_file - allocation memory failed");
		return (1);
	}
	fill_null(data->map.maze, data->map.lines + 2);
	if (init_maze_content(data, after_args))
		return (1);
	return (0);
}

static int	error_lines_maze(t_data *data, int lines)
{
	if (!data->map.start_count)
	{
		ft_display_error("Player starting position is missing");
		return (1);
	}
	if (lines <= 0)
	{
		ft_display_error("Map is missing");
		return (1);
	}
	return (0);
}

static int	get_nblines_maze(t_data *data)
{
	int	i;
	int	lines;

	i = data->map.begin_maze;
	lines = 0;
	while (data->map.full_file[i])
	{
		if (is_invalid_line(data, i))
			return (1);
		lines++;
		i++;
	}
	if (is_invalid_line(data, i))
		return (1);
	if (error_lines_maze(data, lines))
		return (1);
	data->map.lines = lines;
	return (0);
}

int	init_maze(t_data *data)
{
	if (get_nblines_maze(data))
		return (1);
	if (data->map.lines < 3 || data->map.columns < 3
		|| data->map.lines > 150 || data->map.columns > 150)
	{
		ft_display_error("Map size is invalid,"
			" must be between 3x3 and 150x150 (inclusive)");
		return (1);
	}
	data->map.columns += 3;
	if (init_maze_full(data, data->map.begin_maze))
		return (1);
	return (0);
}
