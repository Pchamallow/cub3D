/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 16:04:40 by pswirgie          #+#    #+#             */
/*   Updated: 2026/08/05 09:23:37 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../lib/libft/libft.h"

void	print_array(char **array)
{
	int	y;

	y = 0;
	while (array[y])
	{
		ft_printf_fd(1, "%s", array[y]);
		y++;
	}
	ft_printf_fd(1, "\n");
}

void	print_directions(t_data *data)
{
	ft_printf_fd(1, "no = %s\n", data->north.path);
	ft_printf_fd(1, "so = %s\n", data->south.path);
	ft_printf_fd(1, "we = %s\n", data->weast.path);
	ft_printf_fd(1, "ea = %s\n", data->east.path);
}

void	print_rgb(t_data *data)
{
	ft_printf_fd(1, "ceiling = \n");
	ft_printf_fd(1, "R %d\n", data->ceiling.r);
	ft_printf_fd(1, "G %d\n", data->ceiling.g);
	ft_printf_fd(1, "B %d\n", data->ceiling.b);
	ft_printf_fd(1, "ground = \n");
	ft_printf_fd(1, "R %d\n", data->ground.r);
	ft_printf_fd(1, "G %d\n", data->ground.g);
	ft_printf_fd(1, "B %d\n", data->ground.b);
}

void	print_player_info(t_data *data)
{
	print_directions(data);
	ft_printf_fd(1, "\nplayer x = %f | player y = %f\n\n",
		data->player.pos_x, data->player.pos_y);
}
