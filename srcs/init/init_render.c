/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 13:01:54 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/29 14:25:37 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../lib/minilibx-linux/mlx.h"

static void	start_east_weast(t_data *data)
{
	if (data->player.direction == 'E')
	{
		data->player.dir_y = 1;
		data->player.dir_x = 0;
		data->render.plane_x = 0.66;
		data->render.plane_y = 0;
	}
	else if (data->player.direction == 'W')
	{
		data->player.dir_y = -1;
		data->player.dir_x = 0;
		data->render.plane_x = -0.66;
		data->render.plane_y = 0;
	}
}

static void	start_north_south(t_data *data)
{
	if (data->player.direction == 'N')
	{
		data->player.dir_y = 0;
		data->player.dir_x = -1;
		data->render.plane_x = 0;
		data->render.plane_y = 0.66;
	}
	else if (data->player.direction == 'S')
	{
		data->player.dir_y = 0;
		data->player.dir_x = 1;
		data->render.plane_x = 0;
		data->render.plane_y = -0.66;
	}
}

static int	load_textures(t_data *data)
{
	load_image(data, &data->north, "./srcs/texture/NO.xpm");
	load_image(data, &data->south, "./srcs/texture/SO.xpm");
	load_image(data, &data->east, "./srcs/texture/EA.xpm");
	load_image(data, &data->weast, "./srcs/texture/WE.xpm");
	return (0);
}

// create an image to show
// create a buffer image in order to write in
int	init_render(t_data *data)
{
	data->render.image = mlx_new_image(data->mlx, data->width, data->height);
	if (!data->render.image)
		return (1); // add message error
	data->render.buffer = mlx_get_data_addr(data->render.image, &data->render.pixel_bits,
		&data->render.line_bytes, &data->render.endian);
	if (!data->render.buffer)
		return (1); // message protection ?
	start_north_south(data);
	start_east_weast(data);
	if (load_textures(data))
		return (1);
	if (render(data))
		return (1);
	return (0);
}
