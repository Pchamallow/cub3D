/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 12:41:36 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/14 14:09:36 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../lib/minilibx-linux/mlx.h"

int	refresh_map(t_data *data)
{
	// int	x;
	// int	y;

	mlx_clear_window(data->mlx, data->win);
	render(data);
	// recalcul de render
	return (0);
}

// verLine(x, drawStart, drawEnd, color);

static void	modifiy_render(t_data *data, t_render *render)
{
	
	if (render->pixel_bits != 32)
		data->render.debug_color = mlx_get_color_value(data->mlx, data->render.debug_color);
	// protection
	
	for(int y = 0; y < data->height; ++y)
	for(int x = 0; x < data->width; ++x)
	{
		int pixel = (y * render->line_bytes) + (x * 4);

		if (render->endian  == 1)        // Most significant (Alpha) byte first
		{
			render->buffer[pixel + 0] = (data->render.debug_color >> 24);
			render->buffer[pixel + 1] = (data->render.debug_color >> 16) & 0xFF;
			render->buffer[pixel + 2] = (data->render.debug_color >> 8) & 0xFF;
			render->buffer[pixel + 3] = (data->render.debug_color) & 0xFF;
		}
		else if (render->endian  == 0)   // Least significant (Blue) byte first
		{
			render->buffer[pixel + 0] = (data->render.debug_color) & 0xFF;
			render->buffer[pixel + 1] = (data->render.debug_color >> 8) & 0xFF;
			render->buffer[pixel + 2] = (data->render.debug_color >> 16) & 0xFF;
			render->buffer[pixel + 3] = (data->render.debug_color >> 24);
		}
	}
}

int	render(t_data *data)
{
	t_render	*render = &data->render;
	
	data->render.image = mlx_new_image(data->mlx, data->width, data->height);
	if (!data->render.image)
		return (1);
	// add message error
	
	data->render.buffer = mlx_get_data_addr(data->render.image, &data->render.pixel_bits,
		&data->render.line_bytes, &data->render.endian);
	if (!data->render.buffer)
		return (1);
	// add message error

	modifiy_render(data, render);

	mlx_put_image_to_window(data->mlx, data->win, data->render.image, 0, 0);
	return (0);
}