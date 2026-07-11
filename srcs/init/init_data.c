/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 09:36:44 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/07/11 09:52:02 by nbaudoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../lib/minilibx-linux/mlx.h"

static void	*init_window(t_data *data)
{
	void	*ptr;

	data->height = data->map.height;
	data->width = data->map.width;
	ptr = mlx_new_window(data->mlx, data->width, data->height, "cub3d");
	return (ptr);
}

int	ft_init_game(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		free_all(data);
		ft_mlx_error();
		return (1);
	}
	data->win = init_window(data);
	if (!data->win)
	{
		free_all(data);
		ft_mlx_error();
		return (1);
	}
	// init_textures(data);
	// data->player.last_time = get_time(); animations
	data->player.pos_x = data->player.x_start_p;
	data->player.pos_y = data->player.y_start_p;
	// init_hooks(data); --> event
	return (0);
}
