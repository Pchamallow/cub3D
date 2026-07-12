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

// static int	is_whitespace(char c)
// {
// 	if (c == ' ' || (c >= '\t' && c <= '\r'))
// 		return (1);
// 	return (0);
// }

// static int	str_iswhitespaces(char *s)
// {
// 	int	i;

// 	i = 0;
// 	while (s && s[i])
// 	{
// 		if (!is_whitespace(s[i]))
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

static int	init_columns(t_data *data, char *line, int y)
{
	if (!line)
		return (1);
	data->map.full_file[y] = (char *)malloc((sizeof(char))
			* ft_strlen(line) + 1);
	if (!data->map.full_file[y])
	{
		ft_display_error("Map - init columns - allocation memory failed");
		free_all(data);
		return (1);
	}
	ft_bzero(data->map.full_file[y], ft_strlen(line));
	ft_strlcpy(data->map.full_file[y], (const char *)line,
		ft_strlen(line) + 1);
	return (0);
}

static int	init_map_content(t_data *data)
{
	t_map *map;
	char	*line;
	int		fd;
	int		y;

	y = 0;
	map = &data->map;
	fd = open(map->file_name, O_RDONLY);
	line = get_next_line(fd);
	while (y < data->map.lines)
	{
		if (init_columns(data, line, y))
		{
			if (line)
				free(line);
			close(fd);
			return (1);
		}
		free(line);
		line = get_next_line(fd);
		y++;
	}
	free(line);
	close(fd);
	return (0);
}

// en amount -> avoir bien tous les args
// verification map existe
int	init_full_file(t_data *data)
{
	data->map.lines = get_lines(data->map.file_name);
	data->map.columns = get_columns(data->map.file_name);
	if (data->map.lines < 10 || data->map.columns < 6)
	{
		ft_display_error("Element is missing : arguments NO, SO, WE, EA, F, C and a valid map needed");
		free_all(data);
		return (1);
	}
	if (data->map.lines > 350 || data->map.columns > 350)
	{
		ft_display_error("File is too big, have to be inbetween H10/W6 and H350/W350 (inclusive)");
		free_all(data);
		// revoir formulation ??
		return (1);
	}
	data->map.full_file = (char **)malloc((sizeof(char *)) * (data->map.lines + 1));
	if (!data->map.full_file)
	{
		ft_display_error("Map - init full_file - allocation memory failed");
		free_all(data);
		return (1);
	}
	if (data->map.full_file)
		fill_null(data->map.full_file, data->map.lines);
	if (init_map_content(data))
		return (1);
	return (0);
}


// // min 3 lines / min 5 columns
// // first and last lines, begin and end (only 1), all lines = same len, 
// // 1 P, 1 E, at least 1 C
// // A intruder (not PCE01)
// // path is valid
// int	map_is_valid(t_game *game)
// {
// 	if (check_file(game))
// 		print_error("Error\nWrong map.\n", 2);
// 	if (init_map(game) == 1 || check_lines_len(game)
// 		|| begin_end_one(game) || check_elements(game))
// 		print_error_free(game, "Error\nAt least one tree is missing.\n", 2);
// 	if (check_path(game))
// 		print_error_free(game, "Error\nPath is invalid.\n", 2);
// 	return (0);
// }
