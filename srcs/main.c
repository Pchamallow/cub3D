/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 13:45:06 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/11 15:01:41 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../lib/libft/libft.h"
#include "../lib/minilibx-linux/mlx.h"

int main (int ac, char **av)
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	if (ft_args_not_valid(ac, av))
		return (1);
	data.map.file_name = av[1];
	if (ft_init_game(&data) || ft_init_data(&data))
		return (1);
	// if (parse map)
	// return (1);
	// mlx_loop_hook
	// mlx_loop(data.mlx);
	free_all(&data);
	return (0);
}



// int main (int ac, char **av)
// {
// 	t_data data;
// 	int y = 0;

// 	(void)ac;
// 	(void)av;
// 	data.map.file_name = "/home/pswirgie/Documents/04_Milestone_04/cub3d/assets/minimalist.cub";
// 	init_full_map(&data);

// 	// // PRINT MAP COPY
// 	y = 0;
// 	while (data.map.full_map[y])
// 	{
// 		printf("index = %d, %s\n", y, data.map.full_map[y]);
// 		y++;
// 	}
	
// 	check_path(&data);

// 	// // PRINT MAZE COPY
// 	y = 0;
// 	while (data.map.maze_map[y])
// 	{
// 		printf("%s\n", data.map.maze_map[y]);
// 		y++;
// 	}
	
// 	return (0);
	
// }

