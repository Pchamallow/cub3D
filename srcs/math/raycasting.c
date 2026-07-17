/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 12:41:36 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/17 11:26:28 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../lib/minilibx-linux/mlx.h"
#include <stdint.h>
#include <math.h>
#include "../../lib/libft/libft.h"

#include <stdio.h>


static void	put_pixel(t_data *data, int start, int end, int color)
{
	char *dst;
	dst = data->render.buffer + (start * data->render.line_bytes
		+ end  * (data->render.pixel_bits/ 8));
	*(unsigned int*)dst = color;
}

static void	put_texture_pixel(t_data *data, int x, double distance)
{
	//Calculate height of line to draw on screen
	(void)distance;
	int h_wall = (int)(HEIGHT_WINDOW / distance);

	//calculate lowest and highest pixel to fill in current stripe
	int drawStart = -h_wall / 2 + HEIGHT_WINDOW / 2;
	if(drawStart < 0)
		drawStart = 0;

	int drawEnd = h_wall / 2 + HEIGHT_WINDOW / 2;
	if(drawEnd >= HEIGHT_WINDOW)
		drawEnd = HEIGHT_WINDOW - 1;

	// printf("[DEBUG] drawStart = %d   drawEnd = %d\n",
	// 	drawStart, drawEnd);

	// drawStart = 50;
	// drawEnd = 500;
	
	int y = 0;

	while (y < drawStart)
	{
		put_pixel(data, y, x, 0x87CEEB);
		// printf(" ca print : y = %d, x = %d\n", y, x);
		y++;
	}

	while (y <= drawEnd)
	{
		put_pixel(data, y, x, 0xF5F5DC);
		// printf(" brefore drawEnd ca print : y = %d, x = %d\n", y, x);
		y++;
	}

	while (y < HEIGHT_WINDOW)
	{
		put_pixel(data, y, x, 0x808080); //data->ceiling.color)
		// printf(" after drawEnd ca print : y = %d, x = %d\n", y, x);
		y++;
	}
}


// V0002
int	render(t_data *data)
{
	// int y = 0;
	int x = 0;

	while (x <= WIDTH_WINDOW)
	{
		// while (x < HEIGHT_WINDOW)
		// {
		// 1. calculer orientation de mon rayon
		ray_orientation(data);
		
		// 2. faire le calcul de la distance parcouru par le rayon
		double distance = reach_wall(data);
		// (void)distance;
	
		// utilisation distance pour generer la perspective avec le mur
		

		// 3. Mettre la texture dans le buffer image
		put_texture_pixel(data, x, distance);
		
		//4. put image
		// break ;
		// x++;
		// }
		// break ;
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->render.image, 0, 0);

	return (0);
}

int	refresh_map(t_data *data)
{
	render(data);
	print_array(data->map.maze);
	return (0);
}