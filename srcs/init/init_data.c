/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 09:36:44 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/07/16 12:39:25 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../lib/minilibx-linux/mlx.h"
#include "../../lib/libft/libft.h"

static void	*init_window(t_data *data)
{
	void	*ptr;

	data->height = HEIGHT_WINDOW;
	data->width = WIDTH_WINDOW;
	ptr = mlx_new_window(data->mlx, data->width, data->height, "cub3d");
	return (ptr);
}

// create an image to show
// create a buffer image in order to write in
static int	init_render(t_data *data)
{
	data->render.debug_color = 0xABCDEF;
	data->render.image = mlx_new_image(data->mlx, data->width, data->height);
	if (!data->render.image)
		return (1);
	// add message error
	
	data->render.buffer = mlx_get_data_addr(data->render.image, &data->render.pixel_bits,
		&data->render.line_bytes, &data->render.endian);
	if (!data->render.buffer)
		return (1);
	// protection
	if (render(data))
		return (1);
	return (0);
}

int	ft_init_game(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		ft_mlx_error();
		return (1);
	}
	data->win = init_window(data);
	if (!data->win)
	{
		ft_mlx_error();
		return (1);
	}
	ft_init_hooks(data);
	if (init_render(data))
		return (1);
	return (0);
}

static int	set_colors(t_data *data, char **ceiling, char **ground)
{
	data->ceiling.r = secure_rgb(ft_atol(ceiling[0]));
	data->ceiling.g = secure_rgb(ft_atol(ceiling[1]));
	data->ceiling.b = secure_rgb(ft_atol(ceiling[2]));
	data->ground.r = secure_rgb(ft_atol(ground[0]));
	data->ground.g = secure_rgb(ft_atol(ground[1]));
	data->ground.b = secure_rgb(ft_atol(ground[2]));
	if (data->ceiling.r == -1 || data->ceiling.g == -1
		|| data->ceiling.b == -1 || data->ground.r == -1
		|| data->ground.g == -1 || data->ground.b == -1)
		return (1);
	return (0);
}

static int	init_rgb(t_data *data)
{
	char	**ground;
	char	**ceiling;
	int		error;

	if (check_double_rgb(data, "F") || check_double_rgb(data, "C"))
		return (1);
	ground = ft_split_rgb(data, "F");
	if (!ground)
		return (1);
	ceiling = ft_split_rgb(data, "C");
	if (!ceiling)
	{
		free_map(ground);
		return (1);
	}
	error = set_colors(data, ceiling, ground);
	free_map(ground);
	free_map(ceiling);
	return (error);
}

int	ft_init_data(t_data *data)
{
	if (init_full_file(data))
		return (1);
	if (is_tabs(data->map.full_file))
		return (1);
	if (get_all_directions(data))
		return (1);
	if (init_rgb(data))
		return (1);
	if (init_maze(data))
		return (1);
	// ft_printf_fd(2, "\n[DEBUG] map after check walls :\n");
	// print_array(data->map.maze);
	// ft_printf_fd(2, "-------\n");
	if (is_valid_maze(data))
		return (1);
	return (0);
}
