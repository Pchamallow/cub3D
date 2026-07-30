/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_maze_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 14:14:44 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/30 18:04:45 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"
#include "../../../lib/libft/libft.h"

int	is_valid_maze(t_data *data)
{
	if (!data->map.start_count)
	{
		ft_display_error("Player starting position is missing");
		return (1);
	}
	if (check_walls(data))
		return (1);
	return (0);
}

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
		if ((is_whitespace(map->maze[y][i])
			|| map->maze[y][i] == '\0'))
			map->maze[y][i] = 'X';
		i++;
	}
	map->maze[y][len - 1] = '\n';
}

static int	init_fill_x(t_data *data, int y, int len)
{
	data->map.maze[y] = (char *)malloc((sizeof(char)) * data->map.columns + 1);
	if (!data->map.maze[y])
	{
		ft_display_error("Maze - content - allocation memory failed");
		return (1);
	}
	ft_bzero(data->map.maze[y], data->map.columns + 1);
	fill_x(&data->map, y, len);
	return (0);
}

static int	init_maze_line(t_data *data, int j, int i)
{
	data->map.maze[j] = (char *)malloc((sizeof(char))
			* data->map.columns + 2);
	if (!data->map.maze[j])
	{
		ft_display_error("Maze - content - allocation memory failed");
		return (1);
	}
	ft_bzero(data->map.maze[j], data->map.columns + 1);
	data->map.maze[j][0] = 'X';
	ft_strlcpy(&data->map.maze[j][1], (const char *)data->map.full_file[i],
		data->map.columns);
	fill_x(&data->map, j, data->map.columns);
	return (0);
}

int	init_maze_content(t_data *data, int after_args)
{
	int	i;
	int	j;

	i = after_args;
	j = 1;
	if (init_fill_x(data, 0, data->map.columns))
		return (1);
	while (data->map.full_file[i])
	{
		if (init_maze_line(data, j, i))
			return (1);
		i++;
		j++;
	}
	if (init_fill_x(data, j, data->map.columns))
		return (1);
	return (0);
}
