/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 16:04:40 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/29 12:44:33 by pswirgie         ###   ########.fr       */
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
		printf("%s", array[y]);
		y++;
	}
	printf("\n");
}

void	print_directions(t_data *data)
{
	ft_printf_fd(2, "no = %s\n", data->direction.no);
	ft_printf_fd(2, "so = %s\n", data->direction.so);
	ft_printf_fd(2, "we = %s\n", data->direction.we);
	ft_printf_fd(2, "ea = %s\n", data->direction.ea);
}

void	print_rgb(t_data *data)
{
	ft_printf_fd(2, "ceiling = \n");
	ft_printf_fd(2, "R %d\n", data->ceiling.r);
	ft_printf_fd(2, "G %d\n", data->ceiling.g);
	ft_printf_fd(2, "B %d\n", data->ceiling.b);
	ft_printf_fd(2, "ground = \n");
	ft_printf_fd(2, "R %d\n", data->ground.r);
	ft_printf_fd(2, "G %d\n", data->ground.g);
	ft_printf_fd(2, "B %d\n", data->ground.b);
}

void	print_player_info(t_data *data)
{
	print_directions(data);
	printf("\nplayer x = %f | player y = %f\n\n", data->player.pos_x, data->player.pos_y);
	// printf("dirp = %f | dir x = %f | dir y = %f\n\n", data->player.dirp, data->player.dir_x, data->player.dir_y);
}