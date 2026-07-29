/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 01:48:17 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/07/29 15:52:57 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../lib/libft/libft.h"
#include "../../lib/minilibx-linux/mlx.h"

void	load_image(t_data *data, t_image *dir)
{
	dir->image = mlx_xpm_file_to_image(data->mlx, dir->path,
		&dir->width, &dir->height);
	if (!dir->image)
	{
		ft_printf_fd(2, RED "Error\n");
		ft_printf_fd(2, "Loading image : %s", dir->path);
		ft_printf_fd(2, "\n" RESET);
		free_all(data);
		exit(1);
	}
	dir->addr = mlx_get_data_addr(dir->image,
		&dir->pixel_bits, &dir->line_bytes, &dir->endian);
}
