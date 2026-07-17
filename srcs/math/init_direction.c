/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_direction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 10:49:30 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/17 10:50:44 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../include/macro.h"
#include <math.h>

void	init_direction(t_data *data)
{
	double dirp = 0;
	// a recuprer depuis le praring du maze
	data->player.dir = 'N';
	if (data->player.dir == 'N')
	{
		dirp = 1.5 * PI;
		data->player.dir_x = sin(dirp);
		data->player.dir_y = cos(dirp);
	}
	else if (data->player.dir == 'S')
	{
		dirp = 0.5 * PI;
		data->player.dir_x = sin(dirp);
		data->player.dir_y = cos(dirp);
	}
	else if (data->player.dir == 'W')
	{
		dirp = 0;
		data->player.dir_x = sin(dirp);
		data->player.dir_y = cos(dirp);
	}
	else if (data->player.dir == 'E')
	{
		dirp = PI;
		data->player.dir_x = sin(dirp);
		data->player.dir_y = cos(dirp);
	}
	data->player.dirp = dirp;
}
