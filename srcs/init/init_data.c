/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 09:36:44 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/07/29 13:02:53 by pswirgie         ###   ########.fr       */
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
	mlx_do_key_autorepeatoff(data->mlx);
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



// static void	init_image(t_data *data)
// {
// 	// print les valeurs pour voir les endians, lines bytes, pixel 
// 	load_image(data, &data->north, "./srcs/texture/NO.xpm");
// 	load_image(data, &data->south, "./srcs/texture/SO.xpm");
// 	load_image(data, &data->east, "./srcs/texture/EA.xpm");
// 	load_image(data, &data->weast, "./srcs/texture/WE.xpm");
// }

int	ft_init_data(t_data *data)
{
	if (init_full_file(data))
		return (1);
	if (is_tabs(data->map.full_file))
		return (1);
	// function count args lines (full_file), jusqu au debut du maze, 
	//-> parcourt le nb de directions == 4 et de rgb == 2
	if (get_all_directions(data))
		return (1);
	if (init_rgb(data))
		return (1);
	if (init_maze(data))
		return (1);
	// ft_printf_fd(2, "\n[DEBUG] map after check walls :\n");
	print_array(data->map.maze);
	ft_printf_fd(2, "-------\n");
	if (is_valid_maze(data))
		return (1);
	// init_image(data);
	return (0);
}
