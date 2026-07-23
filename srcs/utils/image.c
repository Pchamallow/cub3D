/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 01:48:17 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/07/23 16:25:36 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../lib/libft/libft.h"
#include "../../lib/minilibx-linux/mlx.h"

void	load_image(t_data *data, t_image *dir, char *path)
{
	(void)path;
	dir->width = 64;
	dir->height = 64;
	dir->image = mlx_xpm_file_to_image(data->mlx, "./srcs/texture/NO.xpm", &dir->width, &dir->height);
	if (!dir->image)
	{
		free_all(data);
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Error loading image :", 2);
		ft_putstr_fd(path, 2);
		ft_putchar_fd('\n', 2);
		exit(1);
	}
	dir->addr = mlx_get_data_addr(dir->image,
		&dir->pixel_bits, &dir->line_bytes, &dir->endian);
}
