/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 16:14:32 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/10 13:06:42 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"


// void	free_checker(t_data *game, char **checker)
// {
// 	int	y;

// 	if (!checker)
// 		return ;
// 	y = 0;
// 	while (y < game->map.lines)
// 	{
// 		free(checker[y]);
// 		y++;
// 	}
// 	free(checker);
// 	checker = NULL;
// 	return ;
// }

// //find a path to take all collectibles and exit
// void	find_path(t_data *game, char **checker, int y, int x)
// {
// 	int	lines;
// 	int	columns;

// 	lines = game->map.lines;
// 	columns = game->map.columns;
// 	if (y < 0 || x < 0 || y >= lines || x >= columns
// 		|| checker[y][x] == '1' || checker[y][x] == 'N')
		// parcourir la map -> verifier s il y a plus d un au choix (N S, E  ou W)
		// autre choses que 0 1 ou \n mais que pour le bout de lignes
// 		return ;
// 	else
// 	{
// 		if (checker[y][x] == 'C')
// 			game->collect.value--;
// 		if (checker[y][x] == 'E')
// 			game->exit.value--;
// 		checker[y][x] = 'N';
// 		find_path(game, checker, y + 1, x);
// 		find_path(game, checker, y - 1, x);
// 		find_path(game, checker, y, x + 1);
// 		find_path(game, checker, y, x - 1);
// 	}
// 	return ;
// }

// char	**create_checker(t_data *game)
// {
// 	char	**checker;
// 	int		x;
// 	int		y;

// 	x = 0;
// 	y = 0;
// 	checker = (char **)malloc((sizeof(char *)) * (game->map.lines + 1));
// 	if (!checker)
// 		print_error_free(game, "Error\nMalloc failed.\n", 2);
// 	ft_bzero(checker, game->map.lines + 1);
// 	while (y < game->map.lines)
// 	{
// 		checker[y] = (char *)malloc((sizeof(char))
// 				* (game->map.columns + 1));
// 		if (!checker[y])
// 		{
// 			free_checker(game, checker);
// 			print_error_free(game, "Error\nMalloc failed.\n", 2);
// 		}
// 		ft_bzero(checker[y], game->map.columns);
// 		ft_strlcpy(checker[y], (const char *)game->map.index[y],
// 			(game->map.columns + 1));
// 		y++;
// 	}
// 	return (checker);
// }

void	init_player(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	// player->moves = 0;
	while (data->map.full_map[y])
	{
		x = 0;
		while (data->map.full_map[y][x])
		{
			if (data->map.full_map[y][x] == 'N'
				|| data->map.full_map[y][x] == 'S'
				|| data->map.full_map[y][x] == 'E'
				|| data->map.full_map[y][x] == 'W')
			{
				data->player.x_start_p = x;
				data->player.y_start_p = y;
				printf("%c %c\n", data->player.x_start_p, data->player.y_start_p);
				return ;
			}
			x++;
		}
		y++;
	}
}

int	check_path(t_data *data)
{
	// char	**checker;
	// int		y;
	// int		x;
	// int		j;

	init_player(data);

	
	// checker = create_checker(game);
	// if (!checker)
	// 	return (1);
	// y = game->player_index.y;
	// x = game->player_index.x;
	// j = game->collect.value;
	// find_path(game, checker, y, x);
	// if (!(game->collect.value <= 0 && game->exit.value <= 0))
	// {
	// 	free_checker(game, checker);
	// 	return (1);
	// }
	// game->collect.value = j;
	// free_checker(game, checker);
	return (0);
}

int main (int ac, char **av)
{
	// char	*line;
	// line = get_next_line(fd);
	// printf("%s\n", line);
	// end_gnl(line, fd);

	(void)av;
	if (ac != 1)
		return (1); // message error to print


	t_data data;

	data.map.file_name = "/home/pswirgie/Documents/04_Milestone_04/cub3d/assets/minimalist.cub";
	init_map(&data);

	// PRINT MAP COPY
	// int y = 0;
	// while (data.map.full_map[y])
	// {
	// 	printf("%s", data.map.full_map[y]);
	// 	y++;
	// }
	
	check_path(&data);
	return (0);
	
}
