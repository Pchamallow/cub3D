/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 16:04:40 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/11 16:06:51 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	print_maze(t_data *data)
{
	int y = 0;
	while (data->map.maze_map[y])
	{
		printf("%s\n", data->map.maze_map[y]);
		y++;
	}
}
