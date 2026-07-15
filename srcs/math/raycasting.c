/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 12:41:36 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/15 15:22:21 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../lib/minilibx-linux/mlx.h"
#include <stdint.h>


// TEST V001
// static void	modifiy_render(t_data *data, t_render *render)
// {
	
// 	if (render->pixel_bits != 32)
// 		data->render.debug_color = mlx_get_color_value(data->mlx, data->render.debug_color);
// 	// protection
	
// 	for(int y = 0; y < data->height; ++y)
// 	for(int x = 0; x < data->width; ++x)
// 	{
// 		int pixel = (y * render->line_bytes) + (x * 4);

// 		if (render->endian  == 1)        // Most significant (Alpha) byte first
// 		{
// 			render->buffer[pixel + 0] = (data->render.debug_color >> 24);
// 			render->buffer[pixel + 1] = (data->render.debug_color >> 16) & 0xFF;
// 			render->buffer[pixel + 2] = (data->render.debug_color >> 8) & 0xFF;
// 			render->buffer[pixel + 3] = (data->render.debug_color) & 0xFF;
// 		}
// 		else if (render->endian  == 0)   // Least significant (Blue) byte first
// 		{
// 			render->buffer[pixel + 0] = (data->render.debug_color) & 0xFF;
// 			render->buffer[pixel + 1] = (data->render.debug_color >> 8) & 0xFF;
// 			render->buffer[pixel + 2] = (data->render.debug_color >> 16) & 0xFF;
// 			render->buffer[pixel + 3] = (data->render.debug_color >> 24);
// 		}
// 	}
// }

// int	raycasting(t_data *data)
// {
// 	// facilite pour l algo
// 	int tmp;
// 	tmp = data->player.pos_x;
// 	data->player.pos_x = data->player.pos_y;
// 	data->player.pos_y =  tmp;

// 	int posX = data->player.pos_x;
// 	int posY = data->player.pos_y;  //x and y start position
// 	int dirX = -1.0, dirY = 0.0; //initial direction vector
// 	int planeX = 0.0, planeY = 0.66; //the 2d raycaster version of camera plane

// 	int time = 0; //time of current frame
// 	int oldTime = 0; //time of previous frame

// 	int	*texture[8];

// 	// 1. test une image sur les murs
// 	data->image.path = "srcs/texture/NO.xpm";

// 	// 2. remplacer une image uniforme par les images par direction
// 	// data->direction.no
// 	// 3. mettre une couleur au sol et au plafond
	
// 	data->image.image = mlx_xpm_file_to_image(data->mlx, data->image.path, 2000, 3000);
// 	// securite


// 	}
// }
#include <stdio.h>
int	render(t_data *data)
{
	// t_render	*render = &data->render;
	// raycasting();
	// int x = 1000, y = 1000;
	// modifiy_render(data, render);
	void *img = load_image(data, NO_image);
	mlx_put_image_to_window(data->mlx, data->win, img, 32, 32);
	// mlx_put_image_to_window(data->mlx, data->win, data->render.image, 0, 0);
	return (0);
}

int	refresh_map(t_data *data)
{
	render(data);
	return (0);
}