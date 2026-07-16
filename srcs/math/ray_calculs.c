/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_calculs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 10:10:59 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/16 12:47:12 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../include/macro.h"
#include "../../lib/minilibx-linux/mlx.h"
#include "../../lib/libft/libft.h"
#include <math.h>
#include <stdint.h>
#include <stdio.h>

// double	distance(t_data *data)
// {

	
// 	// a completer avec le reach wall
// 	double wallx = 0;
// 	double wally = 0;

// 	// distance parcourue
// 	// double distance = sqrt((wallx - playerx) + (wally - playery));
// 	return (distance);
// }

/*
* Use sin and cos in to calcul coordinates
8 
*/
double	reach_wall(t_data *data)
{
	t_render *render = &data->render;

	double len = sqrt(pow(render->dirx, 2) + pow(render->diry, 2)) ;
	double dirx_norm = render->dirx / len;
	double diry_norm = render->diry / len;
	
	// begin after Xs
	// int x = 1;
	// int y = 1;

	// invert
	double playerx = data->player.pos_y;
	double playery = data->player.pos_x;
	int	t = 0;
	double rayx = playerx;
	double rayy = playery;
	ft_printf_fd(2, "rayx = %d\n rayy = %d\n", data->player.pos_y,
		 data->player.pos_x);
	ft_printf_fd(2, "rayx = %f\n rayy = %f\n", data->player.pos_y,
		 data->player.pos_x);
	printf("rayx = %f, rayy = %f\n", rayx, rayy);
	
	while (data->map.maze[(int)rayx][(int)rayy] != 1)
	{
		rayx = playerx + dirx_norm * t;
		rayy = playery + diry_norm * t;
		t++;
	}
	ft_printf_fd(2, "its a wall !\n");
	
	// if (data->render.dirp < PIE)
	// {
	// 	// sin = 0 et cose = -1
	// }
	// else if (data->render.dirp == PIE)
	// 	// sin = 0 et cose = -1
	// else if (data->render.dirp > PIE)
	// 	;	
		// sin = 0 et cose = -1
	
	// // pour le nord
	// double dirx = 1;
	// double diry = 0;

	// double 
	
	double dis = 0;
	// double dis = distance(data);
	return (dis);
}

/*
* Direction : 
* Est = 0, West =  pie, North = 1.5 pie, South = 0.5 pie
*		- number choosen by position on circule
* User sin and cos to have x and y from dirp point
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
		data->render.dirx = sin(dirp);
		data->render.diry = cos(dirp);
	}
	else if (dir == 'S')
		dirp = 0.5 * PIE;
	else if (dir == 'W')
		dirp = PIE;
	else if (dir == 'E')
		dirp = 0 * PIE;
	data->render.dirp = dirp;
}