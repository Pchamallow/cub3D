/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 08:42:45 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/07/29 14:28:06 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../lib/minilibx-linux/mlx.h"
#include "stdlib.h"

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
}

static void	free_textures(t_data *data, t_direction *dir)
{
	free(dir->no);
	free(dir->so);
	free(dir->we);
	free(dir->ea);
	dir->no = NULL;
	dir->so = NULL;
	dir->we = NULL;
	dir->ea = NULL;
	if (data->north.image)
		mlx_destroy_image(data->mlx, data->north.image);
	if (data->south.image)
		mlx_destroy_image(data->mlx, data->south.image);
	if (data->east.image)
		mlx_destroy_image(data->mlx, data->east.image);
	if (data->weast.image)
		mlx_destroy_image(data->mlx, data->weast.image);
}

static void	free_render(t_data *data)
{
	if (!data->mlx)
		return ;
	if (data->render.image)
	{
		mlx_destroy_image(data->mlx, data->render.image);
		data->render.image = NULL;
	}
	// if (data->render.path)
	// {
	// 	free(data->render.path);
	// 	data->render.path = NULL;
	// }
}

void	free_all(t_data *data)
{
	if (!data)
		return ;
	free_map(data->map.full_file);
	free_map(data->map.maze);
	free_textures(data, &data->direction);
	free_render(data);
	if (data->mlx && data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	data->win = NULL;
	data->mlx = NULL;
}
