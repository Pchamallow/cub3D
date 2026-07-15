/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 01:48:17 by nbaudoin          #+#    #+#             */
/*   Updated: 2026/07/15 15:31:47 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../lib/libft/libft.h"
#include "../../lib/minilibx-linux/mlx.h"

void	*load_image(t_data *data, char *path)
{
	void	*img;
	int		w;
	int		h;

	img = mlx_xpm_file_to_image(data->mlx, path, &w, &h);
	if (!img)
	{
		free_all(data);
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Error loading image :", 2);
		ft_putstr_fd(path, 2);
		ft_putchar_fd('\n', 2);
		exit(1);
	}
	return (img);
}
