/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_maze.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 16:20:12 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/11 18:51:55 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"
#include "../../../lib/libft/libft.h"
#include "../../../lib/get_next_line/get_next_line.h"
#include <stdlib.h>




// les erreurs de longuerus de map et minimum sont a mettre icci
	// if (data->map.lines < 3 || data->map.columns < 3)
	// {
	// 	ft_display_error("Map is too small");
	// 	return (1);
	// }
	// if (data->map.lines > 50 || data->map.columns > 50)
	// {
	// 	ft_display_error("Map is too big, have to inbetween X and X (inclusive)");
	// 	return (1);
	// }

static int	init_maze_content(t_data *data, int after_args)
{
	int	i;
	int	j;

	i = after_args;
	j = 0;
	while (data->map.full_file[i])
	{
		data->map.maze[j] = (char *)malloc((sizeof(char))
				* ft_strlen(data->map.full_file[i]) + 1);
		if (!data->map.maze[j])
		{
			ft_display_error("Maze - content - allocation memory failed");
			free_all(data);
			return (1);
		}
		ft_bzero(data->map.maze[j], ft_strlen(data->map.full_file[i]));
		ft_strlcpy(data->map.maze[j], (const char *)data->map.full_file[i],
			(data->map.columns + 1));
		i++;
		j++;
	}
	return (0);
}
	
static int	init_maze_full(t_data *data, int after_args)
{
	data->map.maze = (char **)malloc((sizeof(char *)) * (data->map.lines + 1));
	if (!data->map.maze)
	{
		ft_display_error("Maze - full_file - allocation memory failed");
		free_all(data);
		return (1);
	}
	fill_null(data->map.maze, data->map.lines);
	if (init_maze_content(data, after_args))
		return (1);
	return (0);
}

static int	is_full_one_or_whitespace(char *str)
{
	int	i;
	int	one;

	i = 0;
	one = 0;
	while (str[i])
	{
		if (str[i] == '1')
			one++;
		if (!is_whitespace(str[i]) && str[i] != '1')
			return (0);
		i++;
	}
	if (one)
		return (1);
	return (0);
}

static int	get_index_after_args(t_data *data)
{
	int	first;
	int	i;

	i = 0;
	first = 0;
	while (data->map.full_file[i])
	{
		if (is_full_one_or_whitespace(data->map.full_file[i]))
		{
			first = i;
			break ;
		}
		i++;
	}
	if (!first)
	{
		ft_display_error("Map is missing");
		free_all(data);
		return (-1);
	}
	return (first);
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
	int	after_args;

	after_args = get_index_after_args(data);
	if (after_args == -1)
		return (1);
	if (get_lines_maze(data, after_args))
		return (1);
	if (init_maze_full(data, after_args))
		return (1);
	return (0);
}
