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

#include "../../include/cub3d.h"

int	init_columns(t_game *game, int y)
{
	game->map.index[y] = (char *)malloc((sizeof(char))
			* (game->map.columns + 1));
	if (!game->map.index[y])
		print_error_free(game, "Error\nMalloc failed.\n", 2);
	return (0);
}

int	map_tab(t_game *game)
{
	char	*line;
	int		fd;
	int		y;

	y = 0;
	fd = open(game->file, O_RDONLY);
	line = get_next_line(fd);
	while (y < game->map.lines)
	{
		if (init_columns(game, y))
			return (1);
		ft_bzero(game->map.index[y], game->map.columns);
		ft_strlcpy(game->map.index[y], (const char *)line,
			(game->map.columns + 1));
		free(line);
		line = get_next_line(fd);
		y++;
	}
	close(fd);
	return (0);
}
print_error("Error\nMap is too small. Please, add some tree.\n", 2);

int	init_map(t_data *data)
{
	int nb_lines;
	int nb_columns;

	nb_lines = end_file(data->map.file_name);
	nb_columns = map_max_len(data->map.file_name);
	data->map.full_map = (char **)malloc((sizeof(char *)) * (game->map.lines + 1));
	if (!data->map.full_map )
		print_error_free(game, "Error\nMalloc failed.\n", 2);
	if (data->map.full_map)
		ft_bzero(game->map.index, game->map.lines + 1);
	if (map_tab(game))
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
