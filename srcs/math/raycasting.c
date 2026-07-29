/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 12:41:36 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/29 10:54:32 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../lib/minilibx-linux/mlx.h"
#include <stdint.h>
#include <math.h>
#include "../../lib/libft/libft.h"
#include <stdio.h>

/*
* THE LOOP OF EACH COLUMN
*
* 1. Ray Orientation:
* Calculate the ray orientation based on the player's initial direction
* if the player rotates (e.g., when arrow keys are pressed) we update from 
* the move_player() directly.
*
* 2. Ray Direction:
* The window is divided by its width (e.g., 1920), resulting in 1920 columns,
* and therefore 1920 rays. Each ray has a unique direction corresponding
* to its position within the field of view (FOV).
* - FOV_RAD = FOV * PI / 180 (PI = half circle, so PI / 2 = quarter circle = 90 degrees)
* - A 90-degree FOV is used instead of 120 to avoid excessive distortion and visual noise
* - 'x' is used to iterate through each column of the screen
* - The window width ensures one ray per column
* - The player direction is offset by PI / 4 to center the view correctly
* - Sine and cosine are used to compute the X and Y components of each ray direction
* - Now, ray are spaced ny angle, now we will spaced by distance with atan and tan
*	the space between each ray is the same
*
* 3. Reach Wall:
* Calculate the distance between the player's position and the wall hit by the ray.
* - The ray is incrementally advanced in its direction until it collides with a wall,
* storing the coordinates of the impact point.
* - Once the wall is reached, compute the distance between the player and the wall
* using their respective X and Y coordinates.
*
* 4. Put texture in each pixel
*/
int	render(t_data *data)
{
	int	x;

	x = 0;
	// remplacer les path par les macros qui correspondent
	// deplacer pour load les images une seule fois
	load_image(data, &data->north, "./srcs/texture/NO.xpm");
	load_image(data, &data->south, "./srcs/texture/SO.xpm");
	load_image(data, &data->east, "./srcs/texture/EA.xpm");
	load_image(data, &data->weast, "./srcs/texture/WE.xpm");

	while (x < WIDTH_WINDOW)
	{
		data->render.x = x;
		cast_ray(data);
		put_texture_pixel(data, x);
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->render.image, 0, 0);
	return (0);
}


/*
* move and rotate here combined with keyrelease allow continuous 
* movement and rotation while a key is held down
*/
int	refresh_map(t_data *data)
{
	rotate_player(data);
	move_forward_backward(data);
	move_left_right(data);
	render(data);
	// print_array(data->map.maze);
	// printf("dirp =  %f,  dir x = %f,  dir y = %f\n", data->player.dirp, data->player.dir_x, data->player.dir_y);
	return (0);
}
