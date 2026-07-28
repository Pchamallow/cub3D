/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 08:42:45 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/07/28 15:06:12 by pswirgie         ###   ########.fr       */
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
	// free(dir->no);
	// free(dir->so);
	// free(dir->we);
	// free(dir->ea);
	// dir->no = NULL;
	// dir->so = NULL;
	// dir->we = NULL;
	// dir->ea = NULL;
	(void)dir;
	// rajouter if image existe pour chacun
	mlx_destroy_image(data->mlx, data->north.image);
	mlx_destroy_image(data->mlx, data->south.image);
	mlx_destroy_image(data->mlx, data->east.image);
	mlx_destroy_image(data->mlx, data->weast.image);
}

static void	free_images(t_data *data)
{
	if (!data->mlx)
		return ;
	if (data->image.image)
	{
		mlx_destroy_image(data->mlx, data->image.image);
		data->image.image = NULL;
	}
	if (data->image.path)
	{
		free(data->image.path);
		data->image.path = NULL;
	}
}

void	free_all(t_data *data)
{
	if (!data)
		return ;
	free_map(data->map.full_file);
	free_map(data->map.maze);
	free_textures(data, &data->direction);
	free_images(data);
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
