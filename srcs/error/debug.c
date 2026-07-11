/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 16:04:40 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/11 16:34:38 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include <stdio.h>

void	print_maze(t_data *data)
{
	int	y;

	y = 0;
	while (data->map.maze_map[y])
	{
		printf("%s\n", data->map.maze_map[y]);
		y++;
	}
}
