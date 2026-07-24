/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 10:04:07 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/24 12:36:00 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include <stdlib.h> // for exit
#include <stdio.h> // for printf
#include <math.h> // verifier possibite

static void	put_pixel(t_data *data, int x, int y, int color)
{
	char *dst;
	// (void)y;
	dst = data->render.buffer + (x * data->render.line_bytes
		+ y * (data->render.pixel_bits/ 8));
	*(unsigned int*)dst = color;
}

static int get_pixel(t_image *dir, int x, int y)
{
	char *pixel;

	// printf("get pixel _> x = %d y = %d\n", x, y);
	pixel = dir->addr + (y * dir->line_bytes + x * (dir->pixel_bits / 8));
	return (*(unsigned int *)pixel);
}

// int is_side(double hit_x, double hit_y)
// {
//     double frac_x;
//     double frac_y;

//     frac_x = hit_x - floor(hit_x);
//     frac_y = hit_y - floor(hit_y);

//     // si frac_x est très proche de 0 (donc hit_x quasi entier)
//     // -> on a touché une face verticale (est/ouest) -> side = 0
//     if (frac_x < 0.0001 || frac_x > 0.9999)
//         return (0);
//     // sinon c'est frac_y qui est quasi entier -> face horizontale -> side = 1
//     else
//         return (1);
// }

void	put_texture_pixel(t_data *data, int x, double distance)
{
	//Calculate height of line to draw on screen
	(void)distance;// a suppr des arguments ?
	double h_wall = (HEIGHT_WINDOW / distance);

	//calculate lowest and highest pixel to fill in current stripe
	int draw_start = -h_wall / 2 + HEIGHT_WINDOW / 2;
	if(draw_start < 0)
		draw_start = 0;

	int draw_end = h_wall / 2 + HEIGHT_WINDOW / 2;
	if(draw_end >= HEIGHT_WINDOW)
		draw_end = HEIGHT_WINDOW - 1;

	// printf("[DEBUG] draw_start = %d   draw_end = %d\n",
	// 	draw_start, draw_end);

	// TEST DETECT SIDE WALL
	// double hit_x = data->player.pos_x + distance * data->render.ray_dir_x;
    // double hit_y = data->player.pos_y + distance * data->render.ray_dir_y;
	// cast_ray(data, data->render.ray_dir_x, data->render.ray_dir_y);
    // data->render.wall_side = is_side(hit_x, hit_y);
	// wall_side(data);
	// exit(1);

	int y = 0;

	while (y < draw_start)
	{
		put_pixel(data, y, x, 0x87CEEB);
		// printf(" ca print : y = %d, x = %d\n", y, x);
		y++;
	}

	int tex_x;

	tex_x = (int)(data->render.wall_x * (double)data->north.width);
	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= data->north.width)
		tex_x = data->north.width - 1;

	double step = (double)data->north.height / (double)h_wall;
	double tex_pos = (draw_start - HEIGHT_WINDOW / 2 + h_wall / 2) * step;
	
	int color;
	while (y <= draw_end)
	{
		// if (data->render.wall_side)
		// 	color = 0x000000;
		// else

		int tex_y = (int)tex_pos;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= data->north.height)
			tex_y = data->north.height - 1;
		tex_pos += step;
		
		color = 0xF5F5DC;
		color = get_pixel(&data->north, tex_x, tex_y);

		// texture murs
		// 1. savoir si on est au nord, sud, est, ouest
		// 2. comment mettre la texture 

		put_pixel(data, y, x, color);

		// printf(" brefore draw_end ca print : y = %d, x = %d\n", y, x);
		y++;
	}

	while (y < HEIGHT_WINDOW)
	{
		put_pixel(data, y, x, 0x808080); //data->ceiling.color)
		// printf(" after draw_end ca print : y = %d, x = %d\n", y, x);
		y++;
	}
}
