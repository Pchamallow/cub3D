/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 12:41:36 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/24 10:32:21 by pswirgie         ###   ########.fr       */
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


// V0002
int	render(t_data *data)
{
	// int y = 0;
	int x = 0;

	while (x <= WIDTH_WINDOW)
	{
		// 1. calculer orientation de mon rayon
		ray_orientation(data);

		// pouvoir avancer reculer par rapport a la camera
		// = mettre a jour l orientation player avec les mouvemenst de camera 
		// (rajouter ex : +1 camera -> +1 player)
		
		// regarde ecran dans FOV de 90 et non pas 120
		// comme une focale longue -> ne pas avoir trop d info a l image
		
		// PIE /2 = le FOV
		// x pour incremnter changer de direction
		// la largeur de la window pour avoir une dir = une colonne
		// dirp - 1/4 de PI pour positionner l angle de vue la ou le joueur regarde 
		data->render.ray_dir = (PI/2 - ((PI/2 * x) / WIDTH_WINDOW)) + data->player.dirp - (0.25 * PI);
		data->render.ray_dir_y = sin(data->render.ray_dir);
		data->render.ray_dir_x = cos(data->render.ray_dir);
		
		// 2. faire le calcul de la distance parcouru par le rayon
		double distance = reach_wall(data);

		// 3. Mettre la texture dans le buffer image
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