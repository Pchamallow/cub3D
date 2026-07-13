/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_maze.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 09:25:45 by pswirgie          #+#    #+#             */
/*   Updated: 2026/07/13 14:13:03 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

int	is_valid_maze(t_data *data)
{
	if (!data->map.start_count)
	{
		ft_display_error("Player starting position is missing");
		return (1);
	}
	if (check_walls(data))
		return (1);
	
	return (0);
}