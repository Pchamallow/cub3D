/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 16:04:40 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/13 13:30:03 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../lib/libft/libft.h"

void	print_array(char **array)
{
	int y = 0;
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