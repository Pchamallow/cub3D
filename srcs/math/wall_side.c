/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_side.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 10:59:10 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/24 17:16:56 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include <stdio.h> // for printf
#include <math.h> // autorise ???

// static int	ft_abs(double nb)
// {
// 	if (nb < 0)
// 		nb = nb *-1;
// 	return (nb);
// }

int get_pixel(t_image *dir, int x, int y)
{
	char *pixel;

	// printf("get pixel -> x = %d y = %d\n", x, y);
	pixel = dir->addr + (y * dir->line_bytes + x * (dir->pixel_bits / 8));
	return (*(unsigned int *)pixel);
}

// chercher le rayon qui va vers les lignes verticales
// chercher les rayon vers les lignes horizontal
// si rayon horizontal < rayon vertical = c est de face
double	cast_ray(t_data *data)
{
	// double dir_x = -1;
	// double dir_y = 0;
	double dir_x = data->player.dir_x;
	double dir_y = data->player.dir_y;
	// double dir_x = data->player.dir_y;
	// double dir_y = data->player.dir_x;

	double camera_x = 2 * data->render.x / (double)WIDTH_WINDOW - 1;
	double	plane_x = -dir_y * 0.66;
	double	plane_y = dir_x * 0.66; // FOV standrad 
	double ray_dir_x = dir_x + plane_x * camera_x;
	double ray_dir_y = dir_y + plane_y * camera_x;

	int map_x;
	int map_y;
	double side_dist_x;
	double side_dist_y;
	double delta_dist_x = sqrt(1 + (ray_dir_y * ray_dir_y) / (ray_dir_x * ray_dir_x));
	double delta_dist_y = sqrt(1 + (ray_dir_x * ray_dir_x) / (ray_dir_y * ray_dir_y));
	double	pos_x = data->player.pos_x;
	double	pos_y = data->player.pos_y;
	int step_x;
	int step_y;
	int side = 0;

	map_x = (int)pos_x;
	map_y = (int)pos_y;

	// verifier mise en forme valide
	// delta_dist_x = (ray_dir_x == 0) ? 1e30 : fabs(1 / ray_dir_x);
	// delta_dist_y = (ray_dir_y == 0) ? 1e30 : fabs(1 / ray_dir_y);
	// securite si == 0

	if (ray_dir_y < 0)
	{
		step_y = -1;
		side_dist_y = (pos_y - map_y) * delta_dist_y;
	}
	else
	{
		step_y = 1;
		side_dist_y = (map_y + 1.0 - pos_y) * delta_dist_y;
	}
	
	if (ray_dir_x < 0)
	{
		step_x = -1;
		side_dist_x = (pos_x - map_x) * delta_dist_x;
	}
	else
	{
		step_x = 1;
		side_dist_x = (map_x + 1.0 - pos_x) * delta_dist_x;
	}

	int	hit = 0;
	while (hit == 0)
	{
		if (side_dist_x < side_dist_y)
		{
			side_dist_x += delta_dist_x;
			map_x += step_x;
			side = 0;
		}
		else
		{
			side_dist_y += delta_dist_y;
			map_y += step_y;
			side = 1;
		}

		if (map_y < 0 || map_y >= data->map.height
			|| map_x < 0 || map_x >= data->map.width)
			break;

		if (data->map.maze[map_x][map_y] == '1')
		// if (data->map.maze[map_y][map_x] == '1')
			hit = 1;
	}
	printf("map x = %d, map y = %d\n", map_x, map_y);

	double perp_wall_dist;

	// if (side == 0)
	// 	perp_wall_dist = (map_x - pos_x + (1 - step_x) / 2) / ray_dir_x;
	// else
	// 	perp_wall_dist = (map_y - pos_y + (1 - step_y) / 2) / ray_dir_y;

	if (side == 0)
		perp_wall_dist = (side_dist_x - delta_dist_x);
	else
		perp_wall_dist = (side_dist_y - delta_dist_y);

	int line_height = (int)(HEIGHT_WINDOW / perp_wall_dist);
	
	int draw_start = -line_height / 2 + HEIGHT_WINDOW / 2;
	int draw_end = line_height / 2 + HEIGHT_WINDOW / 2;

	if (draw_start < 0)
		draw_start = 0;

	if (draw_end >= HEIGHT_WINDOW)
		draw_end = HEIGHT_WINDOW - 1;
		
	if (side == 0)
	{
		if (ray_dir_x > 0)
			data->render.actual_texture = EAST;
		else
			data->render.actual_texture = WEST;
	}
	else
	{
		if (ray_dir_y > 0)
			data->render.actual_texture = SOUTH;
		else
			data->render.actual_texture = NORTH;
	}
	
	// choose texture
	t_image *texture;

	// a modifier pour avoir toutes les directions
	if (data->render.actual_texture == NORTH)
		texture = &data->north;
	else 
		texture = &data->north;
	
	
		
	double wall_x;

	if (side == 0)
		wall_x = pos_y + perp_wall_dist * ray_dir_y;
	else
		wall_x = pos_x + perp_wall_dist * ray_dir_x;
	
	wall_x -= floor(wall_x);
	int tex_x = (int)(wall_x * texture->width);

	if (side == 0 && ray_dir_x > 0)
		tex_x = (int)(texture->width - tex_x - 1);

	if (side == 1 && ray_dir_y < 0)
		tex_x = (int)(texture->width - tex_x - 1);



	
	double step = (double)texture->height / line_height;

	double tex_pos = (draw_start - HEIGHT_WINDOW / 2 + line_height / 2) * step;

	int y = draw_start;
	int tex_y;
	while (y < draw_end)
	{
		 tex_y = (int)tex_pos & (texture->height - 1);

		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= texture->height)
			tex_y = texture->height - 1;

		tex_pos += step;

		int color = get_pixel(texture, tex_x, tex_y);

		put_pixel(data, data->render.x, y, color);
		// put_pixel(data, y, data->render.x, color);
		y++;
	}
	return (tex_pos);
}