/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 13:45:06 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/14 17:07:57 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../lib/libft/libft.h"
#include "../lib/minilibx-linux/mlx.h"

int	main(int ac, char **av)
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	if (ft_args_not_valid(ac, av))
	{
		free_all(&data);
		return (1);
	}
	data.map.file_name = av[1];
	if (ft_init_data(&data) || ft_init_game(&data))
	{
		free_all(&data);
		return (1);
	}
	mlx_loop(data.mlx);
	free_all(&data);
	return (0);
}
// between init game and mlx loop :
// // if (parse map)
// return (1);
// mlx_loop_hook()