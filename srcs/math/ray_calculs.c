/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_calculs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 10:10:59 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/16 11:16:40 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../include/macro.h"
#include "../../lib/minilibx-linux/mlx.h"
// #include "../../lib/libft/libft.h"
#include <math.h>
#include <stdint.h>
#include <stdio.h>

double	distance(t_data *data)
{
	double playerx = data->player.pos_x;
	double playery = data->player.pos_y;
	
	// a completer avec le reach wall
	double wallx = 0;
	double wally = 0;

	// distance parcourue
	double distance = sqrt((wallx - playerx) + (wally - playery));
	return (distance);
}

/*
* Use sin and cos in to calcul coordinates
*/
double	reach_wall(t_data *data)
{
	// if (data->render.dirp < PIE)
		
	// else if (data->render.dirp == PIE)
		
	// else if (data->render.dirp > PIE)
	

	double dis = distance(data);
	return (dis);
}

/*
* Direction : 
* Est = 0, West =  pie, North = 1.5 pie, South = 0.5 pie
*/
void	ray_orientation(t_data *data)
{
	// start position

	(void)data;
	char dir = 'N';
	double dirp = 0;

	// orientation rayon 
	if (dir == 'N')
	{
		dirp = 1.5 * PIE;
		// printf("dir player = %f\n", dirp);
	}
	else if (dir == 'S')
		dirp = 0.5 * PIE;
	else if (dir == 'W')
		dirp = PIE;
	else if (dir == 'E')
		dirp = 0 * PIE;
	data->render.dirp = dirp;
}