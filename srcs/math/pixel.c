/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 10:04:07 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/24 10:34:55 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"


static void	put_pixel(t_data *data, int start, int end, int color)
{
	char *dst;
	dst = data->render.buffer + (start * data->render.line_bytes
		+ end  * (data->render.pixel_bits/ 8));
	*(unsigned int*)dst = color;
}

// static int get_pixel(t_image *dir, int x, int y)
// {
// 	char *pixel;

// 	pixel = dir->addr + (y * dir->line_bytes + x * (dir->pixel_bits / 8));
// 	return (*(unsigned int *)pixel);
// }

void	put_texture_pixel(t_data *data, int x, double distance)
{
	//Calculate height of line to draw on screen
	(void)distance;
	double h_wall = (HEIGHT_WINDOW / distance);

	//calculate lowest and highest pixel to fill in current stripe
	int drawStart = -h_wall / 2 + HEIGHT_WINDOW / 2;
	if(drawStart < 0)
		drawStart = 0;

	int drawEnd = h_wall / 2 + HEIGHT_WINDOW / 2;
	if(drawEnd >= HEIGHT_WINDOW)
		drawEnd = HEIGHT_WINDOW - 1;

	// printf("[DEBUG] drawStart = %d   drawEnd = %d\n",
	// 	drawStart, drawEnd);

	int y = 0;

	while (y < drawStart)
	{
		put_pixel(data, y, x, 0x87CEEB);
		// printf(" ca print : y = %d, x = %d\n", y, x);
		y++;
	}

	int color;
	while (y <= drawEnd)
	{
		color = 0xF5F5DC;

		// texture murs
		// 1. savoir si on est au nord, sud, est, ouest
		// 2. comment mettre la texture 
		// data->direction.no;
		// put_pixel(data, y, x, get_texture_pixel(&data->north, 5, 5));
		put_pixel(data, y, x, color);
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
