/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 16:14:32 by pswirgie          #+#    #+#             */
/*   Updated: 2026/08/05 09:38:18 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"
#include "../../../lib/libft/libft.h"
#include "../../../lib/get_next_line/get_next_line.h"
#include <stdlib.h>

void	find_path(t_data *data, int y, int x)
{
	int	lines;

	lines = data->map.lines + 1;
	if (y < 0 || x < 0 || y > lines || x >= data->map.columns
		|| data->map.maze[y][x] == '1'
		|| data->map.maze[y][x] == 'G'
		|| data->map.maze[y][x] == '\n')
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

static void	ft_index_find(char *str, char c, int *index)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (i >= ft_strlen(str))
	{
		*index = -1;
		return ;
	}
	*index = i;
}

static int	is_surrounded(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (data->map.maze[y])
	{
		if (data->map.wall_missing)
			return (1);
		ft_index_find(data->map.maze[y], '0', &x);
		if (x != -1)
		{
			find_path(data, y, x);
			y = 0;
		}
		else
			y++;
	}
	return (0);
}

int	check_walls(t_data *data)
{
	int	y;
	int	x;

	y = data->player.y_start_p;
	x = data->player.x_start_p;
	find_path(data, y, x);
	if (is_surrounded(data))
	{
		ft_display_error("At least one wall is missing");
		return (1);
	}
	return (0);
}
