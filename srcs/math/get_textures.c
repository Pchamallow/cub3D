/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 11:29:06 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/30 11:29:30 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	coordinates_textures_north_south(t_data *data, int h_wall, double draw_start)
{
	double	wall_x;
 
	wall_x = data->wall.distance_y - floor(data->wall.distance_y);
	data->render.tex_x = (int)(wall_x * (double)data->north.width);
	if (data->render.tex_x < 0)
		data->render.tex_x = 0;
	if (data->render.tex_x >= data->north.width)
		data->render.tex_x = data->north.width - 1;
	if (data->render.actual_texture == &data->north)
		data->render.tex_x = data->north.width - 1 - data->render.tex_x;
	data->render.step = (double)data->north.height / (double)h_wall;
	data->render.tex_pos = (draw_start - HEIGHT_WINDOW / 2 + h_wall / 2) * data->render.step;
}

/*
* 1. get the x coordinate of the texture: the column of the
*	texture to render, based on where exactly the ray hit the wall
* 2. if the hit wall is the east wall, mirror the texture
*	(otherwise it would appear flipped/reversed)
* 3. step: how much to move forward in the texture for each
*	vertical pixel (with y in the put pixel loop)
*	on screen (texture height / wall height)
* 4. tex_pos: the starting position in the texture, used to know
*	where to begin sampling before the drawing loop
*/
static void	coordinates_textures_est_west(t_data *data, int h_wall, double draw_start)
{
	double	wall_x;
 
	wall_x = data->wall.distance_x - floor(data->wall.distance_x);
	data->render.tex_x = (int)(wall_x * (double)data->north.width);
	if (data->render.actual_texture == &data->east)
		data->render.tex_x = data->north.width - 1 - data->render.tex_x;
	if (data->render.tex_x < 0)
		data->render.tex_x = 0;
	if (data->render.tex_x >= data->north.width)
		data->render.tex_x = data->north.width - 1;
	data->render.step = (double)data->north.height / (double)h_wall;
	data->render.tex_pos = (draw_start - HEIGHT_WINDOW / 2 + h_wall / 2) * data->render.step;
}

/*
* 1. coordinates_textures(): get the x coordinate, step and tex_pos
*	for the texture (mirrors it if needed, depending on the wall side)
* 2. choose which texture to use, depending on whether the wall hit
*	is a north/south side or an east/west side, and on the direction
*	of the ray on that axis (positive or negative)
*/
static void	get_textures(t_data *data, t_render *render)
{
	if (data->wall.wall_side == 0)
		coordinates_textures_north_south(data, render->h_wall, render->draw_start);
	else
		coordinates_textures_est_west(data, render->h_wall, render->draw_start);
	if (data->wall.wall_side == 0)
	{
		if (render->ray_dir_x > 0)
			render->actual_texture = &data->north;
		else
			render->actual_texture = &data->south;
	}
	else
	{
		if (render->ray_dir_y > 0)
			render->actual_texture = &data->weast;
		else
			render->actual_texture = &data->east;
	}
}
