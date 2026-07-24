/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_side.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 10:59:10 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/24 12:12:04 by pswirgie         ###   ########.fr       */
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

// chercher le rayon qui va vers les lignes verticales
// chercher les rayon vers les lignes horizontal
// si rayon horizontal < rayon vertical = c est de face
double	cast_ray(t_data *data, double ray_dir_x, double ray_dir_y)
{
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	int		side;
	int		hit;
	double	perp_wall_dist;

	map_x = (int)data->player.pos_x;
	map_y = (int)data->player.pos_y;

	delta_dist_x = (ray_dir_x == 0) ? 1e30 : fabs(1 / ray_dir_x);
	delta_dist_y = (ray_dir_y == 0) ? 1e30 : fabs(1 / ray_dir_y);

	if (ray_dir_x < 0)
	{
		step_x = -1;
		side_dist_x = (data->player.pos_x - map_x) * delta_dist_x;
	}
	else
	{
		step_x = 1;
		side_dist_x = (map_x + 1.0 - data->player.pos_x) * delta_dist_x;
	}

	if (ray_dir_y < 0)
	{
		step_y = -1;
		side_dist_y = (data->player.pos_y - map_y) * delta_dist_y;
	}
	else
	{
		step_y = 1;
		side_dist_y = (map_y + 1.0 - data->player.pos_y) * delta_dist_y;
	}

	hit = 0;
	side = 0;
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
		if (data->map.maze[map_y][map_x] == '1')
			hit = 1;
	}

	if (side == 0)
		perp_wall_dist = (map_x - data->player.pos_x + (1 - step_x) / 2) / ray_dir_x;
	else
		perp_wall_dist = (map_y - data->player.pos_y + (1 - step_y) / 2) / ray_dir_y;

	data->render.wall_side = side;
	return (perp_wall_dist);
}