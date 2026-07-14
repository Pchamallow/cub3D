/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaudoin <nbaudoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 09:36:44 by nbaudoin          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/07/14 11:10:06 by nbaudoin         ###   ########.fr       */
=======
/*   Updated: 2026/07/14 11:57:32 by pswirgie         ###   ########.fr       */
>>>>>>> dev
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
	return (0);
}

int	secure_rgb(long rgb)
{
	if (rgb < 0 || rgb > 255)
		return (-1);
	return (rgb);
}

static int	init_rgb(t_data *data)
{
	char **ground;
	char **ceiling;

	ground =ft_split_rgb(data, "F");
	if (!ground)
	{
		ft_display_error("rgb allocation failed");
		return (1);
	}
	ceiling = ft_split_rgb(data, "C");
	if (!ceiling)
	{

		free(ground);
		return (1);
	}
	data->ceiling.r = secure_rgb(ft_atol(ceiling[0]));
	data->ceiling.g = secure_rgb(ft_atol(ceiling[1]));
	data->ceiling.b = secure_rgb(ft_atol(ceiling[2]));

	data->ground.r = secure_rgb(ft_atol(ground[0]));
	data->ground.g = secure_rgb(ft_atol(ground[1]));
	data->ground.b = secure_rgb(ft_atol(ground[2]));

	print_rgb(data);
	free_map(ground);
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
	{
		ft_display_error("rgb allocation failed");
		return (1);
	// print_array(data->map.full_file);
	// ft_printf_fd(2, "-------\n");
	if (init_maze(data))
		return (1);
	// ft_printf_fd(2, "\n[DEBUG] map after check walls :\n");
	// print_array(data->map.maze);
	// ft_printf_fd(2, "-------\n");
	if (is_valid_maze(data))
		return (1);
	return (0);
}
