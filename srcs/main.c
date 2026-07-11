/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 13:45:06 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/11 12:19:19 by pswirgie         ###   ########.fr       */
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
	// parse map + init map
	if (ft_init_game(&data))
		return (1);
	// mlx_loop_hook
	mlx_loop(data.mlx);
	return (0);
}
