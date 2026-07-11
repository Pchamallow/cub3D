/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 09:36:44 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/07/11 15:58:24 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../lib/minilibx-linux/mlx.h"

static void	*init_window(t_data *data)
{
	void	*ptr;

	data->height = HEIGHT_WINDOW;
	data->width = WIDTH_WINDOW;
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
	// init_hooks(data); --> event
	return (0);
}

int	ft_init_data(t_data *data)
{
	if (init_full_map(data))
		return (1);
	if (check_walls(data))
		return (1);
	if (init_player(data))
		return (1);
	// if ()
	return (0);
}
