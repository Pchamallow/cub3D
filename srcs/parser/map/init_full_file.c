/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 17:57:16 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/09 17:57:16 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "../../../lib/get_next_line/get_next_line.h"
#include "../../../lib/libft/libft.h"

static int	init_columns(t_data *data, char *line, int y)
{
	if (!line)
		return (1);
	data->map.full_file[y] = (char *)malloc((sizeof(char))
			* ft_strlen(line) + 1);
	if (!data->map.full_file[y])
	{
		ft_display_error("Map - init columns - allocation memory failed");
		return (1);
	}
	ft_bzero(data->map.full_file[y], ft_strlen(line));
	ft_strlcpy(data->map.full_file[y], (const char *)line,
		ft_strlen(line) + 1);
	return (0);
}

static int	init_map_lines(t_data *data, char **line, int fd)
{
	int	y;

	y = 0;
	while (y < data->map.lines)
	{
		if (init_columns(data, *line, y))
		{
			if (*line)
				free(*line);
			close(fd);
			return (1);
		}
		free(*line);
		*line = get_next_line(fd);
		y++;
	}
	return (0);
}

static int	init_map_content(t_data *data)
{
	char	*line;
	int		fd;

	if (open_fd(data->map.file_name, &fd))
		return (1);
	line = get_next_line(fd);
	if (init_map_lines(data, &line, fd))
		return (1);
	free(line);
	close(fd);
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
	return (0);
}

int	init_full_file(t_data *data)
{
	if (get_lines_columns(data))
		return (1);
	if (data->map.lines < 10 || data->map.columns < 6
		|| data->map.lines > 300 || data->map.columns > 300)
	{
		ft_display_error("Map size is invalid,"
			" must be 6x10 and 300x300 (inclusive)");
		return (1);
	}
	data->map.full_file = (char **)malloc((sizeof(char *))
			* (data->map.lines + 1));
	if (!data->map.full_file)
	{
		ft_display_error("Map - init full_file - allocation memory failed");
		return (1);
	}
	if (data->map.full_file)
		fill_null(data->map.full_file, data->map.lines);
	if (init_map_content(data) || !get_index_after_args(data))
		return (1);
	return (0);
}
