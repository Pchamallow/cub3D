/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 12:41:36 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/14 13:18:03 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../lib/minilibx-linux/mlx.h"



// verLine(x, drawStart, drawEnd, color);

int	render(t_data *data, void **image)
{
	int color = 0xABCDEF;
	int pixel_bits;
	int line_bytes;
	int endian;
	data->render = mlx_get_data_addr(*image, &pixel_bits, &line_bytes, &endian);
	// portection
	if (pixel_bits != 32)
		color = mlx_get_color_value(data->mlx, color);
	// protection
	for(int y = 0; y < 360; ++y)
	for(int x = 0; x < 640; ++x)
	{
		int pixel = (y * line_bytes) + (x * 4);

		if (endian == 1)        // Most significant (Alpha) byte first
		{
			data->render[pixel + 0] = (color >> 24);
			data->render[pixel + 1] = (color >> 16) & 0xFF;
			data->render[pixel + 2] = (color >> 8) & 0xFF;
			data->render[pixel + 3] = (color) & 0xFF;
		}
		else if (endian == 0)   // Least significant (Blue) byte first
		{
			data->render[pixel + 0] = (color) & 0xFF;
			data->render[pixel + 1] = (color >> 8) & 0xFF;
			data->render[pixel + 2] = (color >> 16) & 0xFF;
			data->render[pixel + 3] = (color >> 24);
		}
	}
	return (0);
}