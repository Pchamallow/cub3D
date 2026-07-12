/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_maze.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 16:20:12 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/12 14:15:16 by pswirgie         ###   ########.fr       */
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
