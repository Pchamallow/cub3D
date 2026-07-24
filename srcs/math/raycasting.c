/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 12:41:36 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/24 10:51:11 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../lib/minilibx-linux/mlx.h"
#include <stdint.h>
#include <math.h>
#include "../../lib/libft/libft.h"
#include <stdio.h>

// static void	get_color(t_data *data)
// {
	
// 	(void)data;
	
// 	// 1. savoir si on est au nord, sud, est, ouest
// 	// les directions = par raaport au joueur 
// 	// pour une case 1 :
// 	// au dessus de 1 = nord 
// 	// en dessous de 1 = sud
// 	// droite 1 = West
// 	// gauche 1 = est
// 	// connaitre notre position par rapport au 1

// 	// orientation 
// 	// if dir = PIE = EST,
// 	// dir = 0 ou 2 = west,
// 	// PI * 1.5 = NORD
// 	// if (data->render.ray_dir == 1.5 * PI)
// 		// color = data->direction.no;
// 	data->north.image = load_image(data, &data->north, data->north.image);

// 	// 2. comment mettre la texture 
// }


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
* - PI / 2 represents the FOV (PI = half circle, so PI / 2 = quarter circle = 90 degrees)
* - A 90-degree FOV is used instead of 120 to avoid excessive distortion and visual noise
* - 'x' is used to iterate through each column of the screen
* - The window width ensures one ray per column
* - The player direction is offset by PI / 4 to center the view correctly
* - Sine and cosine are used to compute the X and Y components of each ray direction
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
	int x = 0;

	load_image(data, &data->north, "placeholder");
	while (x <= WIDTH_WINDOW)
	{
		ray_orientation(data);
		data->render.ray_dir = (PI/2 - ((PI/2 * x) / WIDTH_WINDOW)) + data->player.dirp - (0.25 * PI);
		data->render.ray_dir_y = sin(data->render.ray_dir);
		data->render.ray_dir_x = cos(data->render.ray_dir);
		double distance = reach_wall(data);
		put_texture_pixel(data, x, distance);
		x++;
	}
	// print_player_info(data);
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