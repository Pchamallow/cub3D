/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_side.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 10:59:10 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/29 10:24:23 by pswirgie         ###   ########.fr       */
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

static void	init_dda_direction_y(t_data *data)
{
	t_render *render = &data->render;
	int	player_y = (int) data->player.pos_x;

	if (render->ray_dir_y == 0)
		render->delta_y = 1e30;
	else
		render->delta_y = fabs(1.0/render->ray_dir_y);
	if (render->ray_dir_y < 0)
	{
		render->step_y = -1;
		render->side_y = (data->player.pos_x - player_y) * (render->delta_y);
	}
	else
	{
		render->step_y = 1;
		render->side_y = (player_y + 1.0 - data->player.pos_x) * (render->delta_y);
	}
		
}

static void	init_dda_direction_x(t_data *data)
{
	t_render *render = &data->render;
	int	player_x = (int) data->player.pos_y;

	if (render->ray_dir_x == 0)
		render->delta_x = 1e30;
	else
		render->delta_x = fabs(1.0/render->ray_dir_x);
	if (render->ray_dir_x < 0)
	{
		render->step_x = -1;
		render->side_x = (data->player.pos_y - player_x) * (render->delta_x);
	}
	else
	{
		render->step_x = 1;
		render->side_x = (player_x + 1.0 - data->player.pos_y) * (render->delta_x);
	}
		
}


static int	dda_loop(t_data *data)
{
	t_render *render = &data->render;
	int	side;

	side = 0;
	int	x = (int) data->player.pos_y;
	int	y = (int) data->player.pos_x;

	// rajouter limites ? < 0 + hauteur de lines et columns
	while (data->map.maze[x]
			&& data->map.maze[x][y]
			&& data->map.maze[x][y] != '1')
	{
		if (render->side_x < render->side_y)
		{
			render->side_x += render->delta_x;
			x += render->step_x;
			side = 0;
		}
		else
		{
			render->side_y += render->delta_y;
			y += render->step_y;
			side = 1;
		}
	}
	return (side);
}


// chercher le rayon qui va vers les lignes verticales
// chercher les rayon vers les lignes horizontal
// si rayon horizontal < rayon vertical = c est de face
double	cast_ray(t_data *data)
{
	t_render *render = &data->render;

	double cameraX = 2 * render->x / (double)WIDTH_WINDOW - 1;
	render->ray_dir_x = data->player.dir_x + 0 * cameraX;
	render->ray_dir_y = data->player.dir_y + 0.66 * cameraX;
	
	init_dda_direction_x(data);
	init_dda_direction_y(data);

	int	side = dda_loop(data);
	
	if (side == 0)
		data->render.perp_wall_dist = render->side_x - render->delta_x;
	else
		data->render.perp_wall_dist = render->side_y - render->delta_y;

	data->wall.map_x = (int)data->player.pos_y;
	data->wall.map_y = (int)data->player.pos_x;
	data->wall.wall_side = side;
	data->wall.distance_x = data->player.pos_y + render->perp_wall_dist * render->ray_dir_x;
	data->wall.distance_y = data->player.pos_x + render->perp_wall_dist * render->ray_dir_y;
	if (render->perp_wall_dist <= 0.0001)
		render->perp_wall_dist = 0.0001;
	return (render->perp_wall_dist);
}