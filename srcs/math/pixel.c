/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 10:04:07 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/27 16:25:42 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include <stdlib.h> // for exit
#include <stdio.h> // for printf
#include <math.h> // verify if allowed

void	put_pixel(t_data *data, int x, int y, int color)
{
	char *dst;
	dst = data->render.buffer + (x * data->render.line_bytes
		+ y * (data->render.pixel_bits/ 8));
	*(unsigned int*)dst = color;
}

static void	coordinates_textures_north_south(t_data *data, int h_wall, double draw_start)
{
	data->render.wall_y -= floor(data->render.wall_y);
	data->render.tex_x = (int)(data->render.wall_y * (double)data->north.width);
	if (data->render.tex_x < 0)
		data->render.tex_x = 0;
	if (data->render.tex_x >= data->north.width)
	{
		data->render.tex_x = data->north.width - 1;
		data->render.wall_side = 0; // a enlever de la strcuture ???
	}

	if (data->render.actual_texture == &data->south)
		data->render.tex_x = data->south.width - 1 - data->render.tex_x;

	data->render.step = (double)data->north.height / (double)h_wall;
	data->render.tex_pos = (draw_start - HEIGHT_WINDOW / 2 + h_wall / 2) * data->render.step;
	
	printf("wall_y = %f | wall_x = %f | north.width = %d | tex_x = %d | step = %f | tex_pos = %f\n",
		data->render.wall_y, data->render.wall_x, data->north.width, data->render.tex_x, data->render.step, data->render.tex_pos);
}

/*
* 1. search dir wall and choose texture
* 2. if wall_x > 0.99 && wall.x < 0.01 -> its north or south
* 3. if direction is weast -> miror the texture, else if it will be reversed
* 4. set limits coordonates
*/
static void	coordinates_textures_est_west(t_data *data, int h_wall, double draw_start)
{
	data->render.wall_x -= floor(data->render.wall_x);
	// detection face ou coté
	get_dir_wall(data);
	if (data->render.wall_x > 0.99 || data->render.wall_x < 0.01)
	{
		coordinates_textures_north_south(data, h_wall, draw_start);
		return ;
	}
	
	data->render.tex_x = (int)(data->render.wall_x * (double)data->north.width);

	if (data->render.actual_texture == &data->weast)
		data->render.tex_x = data->north.width - 1 - data->render.tex_x;
	
	if (data->render.tex_x < 0)
		data->render.tex_x = 0;
	if (data->render.tex_x >= data->north.width)
		data->render.tex_x = data->north.width - 1;

	
	data->render.step = (double)data->north.height / (double)h_wall;
	data->render.tex_pos = (draw_start - HEIGHT_WINDOW / 2 + h_wall / 2) * data->render.step;

	printf("wall_x = %f | wall_y = %f | north.width = %d |tex_x = %d | step = %f | tex_pos = %f\n",
		data->render.wall_x, data->render.wall_y, data->north.width, data->render.tex_x, data->render.step, data->render.tex_pos);
}

void	put_texture_pixel(t_data *data, int x, double distance)
{
	//Calculate height of line to draw on screen
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


	int y = 0;
	// printf("ray dir x = %f, ray dir y = %f\n", data->render.ray_dir_x, data->render.ray_dir_y);
	while (y < draw_start)
	{
		put_pixel(data, y, x, 0x87CEEB);
		// printf(" ca print : y = %d, x = %d\n", y, x);
		y++;
	}

	coordinates_textures_est_west(data, h_wall, draw_start);

	int color;

	// calculer les entre deux -> entre deux print east
	// il y a un bout de north
	// si j ai :   pixel EA -> NO -> EA
	// -> faire un EA au milieu
	// sauf que c est toute un colonne qui est dans la mauvaise couleur 
	//
	// printf("ray y = %f, ray dir x = %f\n", data->render.ray_dir_y, data->render.ray_dir_x);

	while (y <= draw_end)
	{
		data->render.tex_y = (int)data->render.tex_pos;
		if (data->render.tex_y < 0)
			data->render.tex_y = 0;
		if (data->render.tex_y >= data->north.height)
			data->render.tex_y = data->north.height - 1;
		data->render.tex_pos += data->render.step;
		
		// color = 0xF5F5DC;
		// t_image *actual_texture;

		// regler pour mieux delimiter les textures faces et coté
		// if (data->render.wall_x > 0.995 || data->render.wall_x < 0.0057)
		// 	actual_texture = &data->north;
		// else
		// 	actual_texture = &data->east;

		// color = get_pixel(actual_texture, data->render.tex_x, data->render.tex_y);
		color = get_pixel(data->render.actual_texture, data->render.tex_x, data->render.tex_y);

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
