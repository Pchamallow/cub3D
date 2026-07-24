/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 10:04:07 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/24 12:13:01 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include <stdlib.h> // for exit
#include <stdio.h> // for printf
#include <math.h> // verifier possibite

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

int is_side(double hit_x, double hit_y)
{
    double frac_x;
    double frac_y;

    frac_x = hit_x - floor(hit_x);
    frac_y = hit_y - floor(hit_y);

    // si frac_x est très proche de 0 (donc hit_x quasi entier)
    // -> on a touché une face verticale (est/ouest) -> side = 0
    if (frac_x < 0.0001 || frac_x > 0.9999)
        return (0);
    // sinon c'est frac_y qui est quasi entier -> face horizontale -> side = 1
    else
        return (1);
}

void	put_texture_pixel(t_data *data, int x, double distance)
{
	//Calculate height of line to draw on screen
	(void)distance;// a suppr des arguments ?
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

	// double hit_x = data->player.pos_x + distance * data->render.ray_dir_x;
    // double hit_y = data->player.pos_y + distance * data->render.ray_dir_y;
	cast_ray(data, data->render.ray_dir_x, data->render.ray_dir_y);
    // data->render.wall_side = is_side(hit_x, hit_y);
	// wall_side(data);
	// exit(1);

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
		if (data->render.wall_side)
			color = 0x000000;
		else
			color = 0xF5F5DC;

		// texture murs
		// 1. savoir si on est au nord, sud, est, ouest
		// 2. comment mettre la texture 

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
