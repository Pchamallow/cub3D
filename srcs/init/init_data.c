/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 09:36:44 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/07/14 14:15:16 by pswirgie         ###   ########.fr       */
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

static int	init_rgb(t_data *data)
{
	char **floor;
	char **ceiling;
	
	floor =ft_split_rgb(data, "F");
	if (!floor)
		return (1);
	ceiling = ft_split_rgb(data, "C");
	if (!ceiling)
		return (1);
	data->ceiling.r = ft_atol(ceiling[0]);
	data->ceiling.g = ft_atol(ceiling[1]); 
	data->ceiling.b = ft_atol(ceiling[2]); 
	data->floor.r = ft_atol(floor[0]); 
	data->floor.g = ft_atol(floor[1]); 
	data->floor.b = ft_atol(floor[2]); 
	// print_rgb(data);
	// ajouter securite max et min
	free_map(floor);
	free_map(ceiling);
	return (0);
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
	// print_array(data->map.full_file);
	// ft_printf_fd(2, "-------\n");
	if (init_maze(data))
		return (1);
	ft_printf_fd(2, "\n[DEBUG] map after check walls :\n");
	print_array(data->map.maze);
	ft_printf_fd(2, "-------\n");
	if (is_valid_maze(data))
		return (1);
	return (0);
}
