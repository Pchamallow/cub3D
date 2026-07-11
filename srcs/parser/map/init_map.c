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

static int	init_columns(t_data *data, int y)
{
	data->map.full_map[y] = (char *)malloc((sizeof(char))
			* (data->map.columns + 1));
	// remettre securite
	// if (!data->map.full_map[y])
	// 	print_error_free(data, "Error\nMalloc failed.\n", 2);
	return (0);
}

static int	map_columns(t_data *data)
{
	t_map *map;
	char	*line;
	int		fd;
	int		y;

	y = 0;
	map = &data->map;
	fd = open(map->file_name, O_RDONLY);
	line = get_next_line(fd);
	while (y < map->lines)
	{
		if (init_columns(data, y))
			return (1); // rajouter au clean  {free(line), close(fd)}
		ft_bzero(map->full_map[y], map->columns);
		ft_strlcpy(map->full_map[y], (const char *)line,
			ft_strlen(line));
		free(line);
		line = get_next_line(fd);
		// rajouter securite si pas de line et close fd
		y++;
	}
	// free line
	close(fd);
	return (0);
}

void	fill_null(char **array, int len)
{
	int i = 0;
	while (i < len + 1)
	{
		array[i] = NULL;
		i++;
	}
}

int	init_full_map(t_data *data) // mettre dans init data.c dans init
{
	data->map.lines = get_lines(data->map.file_name);
	data->map.columns = get_columns(data->map.file_name);
	// if (game->map.lines <3 || game->map.columns < 3)
	// securites, choisir les chiffres
		// print_error("Error\nMap is too small. Please, add some tree.\n", 2);
	// if (game->map.lines > 15 || game->map.columns > 31)
	// 	print_error("Error\nMap is too big. Please, remove some tree.\n", 2);
	data->map.full_map = (char **)malloc((sizeof(char *)) * (data->map.lines + 1));
	// remettre securite
	// if (!data->map.full_map ) 
	// 	print_error_free(data, "Error\nMalloc failed.\n", 2);
	// print_error("Error\nMap is too small. Please, add some tree.\n", 2);
	if (data->map.full_map)
		fill_null(data->map.full_map, data->map.lines);
	if (map_columns(data))
		return (1);
	// faire init player
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
