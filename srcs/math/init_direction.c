/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_direction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 10:49:30 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/22 14:24:15 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../include/macro.h"
#include <math.h>

void	init_direction(t_data *data)
{
	double dirp = 0;
	// a recuprer depuis le parsing du maze
	data->player.dirp = 'N';
	if (data->player.dirp == 'N')
		dirp = 1.5 * PI;
	else if (data->player.dirp == 'S')
		dirp = 0.5 * PI;
	else if (data->player.dirp == 'W')
		dirp = 0;
	else if (data->player.dirp == 'E')
		dirp = PI;
	data->player.dir_x = cos(dirp);
	data->player.dir_y = sin(dirp);
	data->player.dirp = dirp;
}
